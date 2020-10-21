/*

How to find the maximum element at a given level in a binary tree?

APPROACH :

Points to Note :
Not A Binary Search tree 
(So we have to traverse all the nodes at a given Level to find the maximum element)

How do we traverse nodes at a given level ?

Simple. Level Order Traversal

We do a simple level Order traversal.

To keep in mind:

    -> Keep track which level we are traversing
    -> Maximum element at that level (Since that is what we will be going to find)

How do we keep track of levels ?

Using a queue . Normal BFS.
Note down the queue size at each level. After the nodes in that level are 
traversed increment the pointer (to keep track of levels);

Simple! Got it :)

Edge cases (Think on it )
-> When the tree is empty
-> When the tree has only node 



*/


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

//Function to find maximum element at a given Level
int findMaxNodeatLevel(Node* root,int level) 
{ 
    //If the tree is empty
    if (root == NULL) 
        return 0; 
    //If level is 0 there is only one Node at that level ,so answer is the same node;
    if(level ==0)
        return root->data;

   // Doing a level Order Traversal
    queue<Node*> q; 

    int ans=0,maximum=INT_MIN,k=0;//To keep track of levels

    q.push(root); 
    while (!q.empty()) { 

            int size=q.size();//Number of nodes at that level;

            while(size--){
            //get element from front of the queue
            Node* temp = q.front(); 
            q.pop(); 


            //If current level = given level and the node's data is greater than the maximum value at that level
            //Update the maximum value.
            if(level == k && maximum < temp->data)
                maximum = temp->data;
            //if left and right child exists,enqueue it to the queue
            if (temp->left) 
                q.push(temp->left); 
            if (temp->right) 
                q.push(temp->right);
            } 
            //Go to next level
            k++;
            ans=max(maximum,ans);

        } 

        return ans;

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


    int level = 2;

	cout << "Max Node in a Binary Tree of a given Level  is \n"; 
	cout << findMaxNodeatLevel(root,level); 

	return 0; 
} 

//Follow Up:
//WRITE A FUNCTION THAT RETURNS THE MINIMUM ELEMENT AT A GIVEN LEVEL!


/*
INPUT:

              1 ---------------> Level 0
            /   \
           2      3 -----------> Level 1
          / \    /  \
         4    5  10 11 --------> Level 2
        / \  / \
       6   7 8  9--------------> Level 3

OUTPUT :

(Maximum node at level 2)
Elements at level 2: 4,5,10,11

max(4,5,10,11) => 11


(Maximum node at level 3)

Elements at level 3 : 6,7,8,9
max(6,7,8,9) => 9



*/