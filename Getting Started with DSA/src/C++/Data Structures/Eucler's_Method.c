#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m,G;
    printf("Enter two integer number:\n");
    scanf("%d %d",&m,&n);
    G=gcd(m,n);
    printf("GCD of %d and %d is %d:\n",m,n,G);
    return 0;
}



int gcd(int m,int n)
{
    int r;
    while(n!=0)
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}
