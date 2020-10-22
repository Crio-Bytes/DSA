#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};

// steps to be done in spiral order traversal
// 1) make teh binary tree in form of a matrix 
// 2) print the matrix in spiral order

/*
               10
             /     \
           12      13
                 /     \
               14       15
              /   \     /  \
             21   22   23   24
   
    sample tree
    converting into a matrix with intialized value as -1

        10  -1  -1  -1  
        12  13  -1  -1
        14  15  -1  -1
        21  22  23  24
    
    now spiral trverse the matrix 

*/
// Gets width of Binary Tree
int get_width (Node* root){
    if (!root)
        return 0;
    
    int ans = 0;
    // mantain a queue for every level, check the size of the queue for maximum
    queue<Node*> nodes;
    nodes.push(root);
    while (!nodes.empty()){
        int count  =nodes.size();
        ans = max (ans, count);
        while (count--){
            Node* cur = nodes.front();
            nodes.pop();
            // insert every child element of every node present in the present level
            if (cur->left)
                nodes.push(cur->left);
            if (cur->right)
                nodes.push(cur->right);
        }
    }
    return ans;
}

// Gets the height of the binary tree
// simple recursion, adding 1 to the max height of its children
int get_height(Node* root){
    if (!root)
        return 0;

    int leftheight = get_height(root->left);
    int rightheight = get_height(root->right);

    return 1+ max (leftheight, rightheight);
}

void fill_matrix(Node* root, int** elements){
    // Traversal of the binary tree, filling the matrix
    queue <Node*> trav;
    trav.push(root);
    Node* currnode = NULL;
    int row=-1, col=-1;
    while (!trav.empty()){
        row++;
        int size = trav.size();
        while (size--){
            col++;
            currnode = trav.front();
            trav.pop();
            elements[row][col]= currnode->data;
            if (currnode->left)
                trav.push(currnode->left);
            if (currnode->right)
                trav.push(currnode->right);
        }
        col = -1;
    }
}

void print_matrix(int** elements, int height, int width){
    string final="";
    int uppr_row=0, lower_row=height-1;
    for (int rnd=0; rnd<height/2; rnd++){
        for (int i=0; i<width; i++){
            if (elements[uppr_row][i]!=INT_MAX)
                final += to_string(elements[uppr_row][i]) + " ,";
        }
        uppr_row++;

        for (int i=width-1; i>=0; i--){
            if (elements[lower_row][i]!=INT_MAX)
                final += to_string(elements[lower_row][i]) + " ,";
        }
        lower_row--;
    }
    // special case if the number of rows are odd, one row would be left in height/2 rounds
    if (height%2){
        for (int i=0; i<width; i++){
            if (elements[uppr_row][i]!=INT_MAX)
                final += to_string(elements[uppr_row][i]) + " ,";
        }
    }
    cout<<(final.substr(0, final.length() - 1));
}

void print_spiral(Node* root){
    // make a matrix to convert the tree in form of a matrix, by level order traversal
    // matrix of height, width size
    int width = get_width(root);
    int height = get_height(root);

    int **elements = new int*[height];
    for (int i=0; i<height; i++)
        elements[i] = new int[width];

    // initializing the matrix
    for (int i=0; i<height; i++)
        for (int j=0; j<width; j++)
            elements[i][j] = INT_MAX;

    fill_matrix(root, elements);
    print_matrix(elements, height, width);
}

int main()
{

    // making of a sample tree
    Node* root = new Node(10);  
    root->left = new Node(12);  
    root->right = new Node(13);  
    root->right->left = new Node(14);  
    root->right->right = new Node(15);  
    root->right->left->left = new Node(21);  
    root->right->left->right = new Node(22);  
    root->right->right->left = new Node(23);  
    root->right->right->right = new Node(24); 

    print_spiral (root);
    
    return 0;
}

