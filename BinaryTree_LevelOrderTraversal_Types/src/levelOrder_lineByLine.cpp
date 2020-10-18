// Program to print level order traversal line by line of a binary tree

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

//function to print level order traversal line by line
void printLevel_LineByLine(Node* root) 
{ 
    if (root == NULL) 
        return; 
   
    queue<Node*> q; 
  
    q.push(root); 
    while (!q.empty()) { 
            //get size of the level
            int size = q.size();

            while(size--){
            //get element from front of the queue
            Node* temp = q.front(); 
            q.pop(); 

            //print it
            cout << temp->data << " "; 
  
            //if left and right child exists,enqueue it to the queue
            if (temp->left) 
                q.push(temp->left); 
            if (temp->right) 
                q.push(temp->right); 
            }
            //put newline after each level
            cout<<endl;
        } 
  
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
	cout << "Level Order traversal of the binary tree line by line is \n"; 
	printLevel_LineByLine(root); 

	return 0; 
} 
