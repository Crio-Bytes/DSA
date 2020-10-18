// Program for zigzag order traversal of a binary tree

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

//function to print in zigzag or spiral form
void printSpiral(Node* root) 
{ 
    if (root == NULL) 
        return; 
  
    stack<int> st;  
    queue<Node*> q; 
  
    bool reverse = true; 
    q.push(root); 
    while (!q.empty()) { 
  
        //size of the queue,that is size of the level
        int size = q.size(); 
        while (size) { 
            Node* temp = q.front(); 
            q.pop(); 
  
            // if reverse == true, push node's data onto the stack, else print it 
            if (reverse) 
                st.push(temp->data); 
            else
                cout << temp->data << " "; 

            //if left and right child exist,enqueue it to the queue
            if (temp->left) 
                q.push(temp->left); 
            if (temp->right) 
                q.push(temp->right); 
            size--; 
        } 
  
        // print nodes from the stack if  reverse ==true 
        if (reverse) { 
            while (!st.empty()) { 
                cout << st.top() << " "; 
                st.pop(); 
            } 
        } 
        reverse = !reverse; 
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
	cout << "ZigZag Order traversal of binary tree is \n"; 
	printSpiral(root); 

	return 0; 
} 
