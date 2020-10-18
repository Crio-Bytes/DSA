/* Program to print reverse level order traversal of a binary tree in spiral form */
#include<iostream>
#include <bits/stdc++.h> 

using namespace std; 

// structur of node
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

// function to print reverse spiral traversal 
void reverseSpiral(Node* root) 
{ 
	if (root == NULL) { 
		return; 
	} 
	queue<Node*> q; 
	 
	bool reverse = true; 
	q.push(root); 

	// loop until queue is empty 
	while (!q.empty()) { 
		// get current size of the queue, i.e the size of the level 
		int size = q.size(); 

        //initialize a stack 
        stack<int> st;
		// iterate over level nodes 
		while(size --) { 
			Node* temp = q.front(); 
			q.pop(); 
			if(reverse == true)
                cout<<temp->data<<" ";
            else st.push(temp->data);

            //if left and right child exist,enqueue it
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);

			} 
		
        // pop and print reversed nodes
        if(reverse == false){
            while (!st.empty()) { 
		        cout << st.top() << " "; 
		        st.pop(); 
	        } 
        }
		reverse = !reverse; 
	} 
	
} 

// Driver code to test the above funtion
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
    root->right->right = new Node(11); 
	reverseSpiral(root); 
	return 0; 
} 
