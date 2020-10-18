// Program to print dfs traversal (preorder,inorder,postorder) of a binary tree

#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 

// Binary Tree node 
struct Node { 
	int data; 
	Node* left; 
	Node* right;

	Node(int value) 
	{ 
		data = value; 
		left = NULL;
        right = NULL; 
	} 
}; 

//function for preorder traversal
void preorder(Node *root){
    if(root == NULL) return ;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//function for inorder traversal
void inorder(Node *root){
    if(root == NULL) return ;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//function for postorder traversal
void postorder(Node *root){
    if(root == NULL) return ;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}
int main() 
{ 
	Node* root = new Node(1); 
	root->left = new Node(2); 
	root->right = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5); 
	root->left->left->left = new Node(6); 
	root->left->left->right = new Node(7);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9); 
    root->right->left = new Node(10); 
    root->right->right = new Node(11); ; 
	cout << "Preorder traversal of the binary tree is \n"; 
	preorder(root); 
    cout<<endl<<endl;
    cout << "Inrder traversal of the binary tree is \n"; 
	inorder(root); 
    cout<<endl<<endl;
    cout << "Postorder traversal of the binary tree is \n"; 
	postorder(root); 
    cout<<endl<<endl;




	return 0; 
} 
