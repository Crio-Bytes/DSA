#include <stdio.h>
#include <stdlib.h>

int v,e,s,D[20],P[20],adjMat[25][25];

struct node
{
    int vertex,distance;
    struct node *llink,*rlink;
};
typedef struct node *NODE;

NODE initialize(NODE queue)
{
    int i;
    NODE cur;
    for(i=1;i<=v;i++)
    {
        D[i] = 9999;
        P[i] = 0;
        NODE temp = (NODE)malloc(sizeof(struct node));
        temp->vertex = i;
        temp->distance = 99999;
        temp->rlink = NULL;
        if(queue==NULL)
        {
            queue=temp;
            queue->llink=NULL;
            cur=queue;
        }
        else
        {
            cur->rlink = temp;
            temp->llink = cur;
            cur=cur->rlink;
        }
    }
    return queue;
}

int deleteMin(NODE *queue)
{
    int del, m = 9999;
    NODE cur=(*queue),prev,min=NULL;
    while(cur!=NULL)
    {
        if(cur->distance<m)
        {
            min=cur;
            m=cur->distance;
        }
        cur=cur->rlink;
    }
    if(min==(*queue))
    {
        (*queue)=min->rlink;
        if(*queue!= NULL)
            (min->rlink)->llink=NULL;
    }
    else
    {
        prev=min->llink;
        prev->rlink=min->rlink;
        if(min->rlink != NULL)
            (min->rlink)->llink = prev;
    }
    del = min->vertex;
    free(min);
    return del;
}

void Decrease(NODE queue, int v, int d)
{
    NODE cur;
    cur=queue;
    while(cur!=NULL)
    {
        if(cur->vertex==v)
        {
            cur->distance=d;
            return;
        }
        cur=cur->rlink;
    }
}

void Dijikstras(NODE queue)
{
    int i,j,u,VT[20],V_VT[20];
    queue=initialize(queue);
    for(i=1;i<=v;i++)
    {
        VT[i]=0;
        V_VT[i]=1;
    }
    VT[s]=1;
    V_VT[s]=0;
    D[s]=0;
    Decrease(queue,s,D[s]);
    for(i=1;i<=v;i++)
    {
        u=deleteMin(&queue);
        VT[u]=1;
        V_VT[u]=0;
        for(j=1; j<=v; j++)
            if(VT[u]==1 && V_VT[j]==1 && adjMat[u][j]<9999)
                if(D[u]+adjMat[u][j] < D[j])
                {
                    D[j]=D[u]+adjMat[u][j];
                    Decrease(queue,j,D[j]);
                    P[j]=u;
                }
    }
}

int main()
{
    int i,j, v1,v2,w;
    NODE queue = NULL;
    printf("Enter the number of Vertices : ");
    scanf("%d", &v);
    printf("Enter the number of edges : ");
    scanf("%d", &e);
    printf("Enter %d edges : \n",e);
    for(i=1;i<=e;i++)
    {
        for(j=1;j<=v;j++)
        {
            if(i==j)
                adjMat[i][j]=0;
            else
                adjMat[i][j]=9999;
        }
    }
    for(i=1;i<=e;i++)
    {
        printf("Edges - %d : ",i);
        scanf("%d%d",&v1,&v2);
        printf("Enter the weight of edge %d --> %d : ", v1,v2);
        scanf("%d", &w);
        adjMat[v1][v2]=adjMat[v2][v1]=w;
    }
    printf("Enter the Source vertex : ");
    scanf("%d",&s);
    Dijikstras(queue);
    printf("\nSingle source (vertex - %d)Shortest distance : \n",s);
    for(i=1;i<=v;i++)
    {
        if(D[i]==0)
            continue;
        printf("Distance %d --> %d : %d\tPrevious Vertex : %d\n",s,i,D[i],P[i]);
    }
    return 0;
}
