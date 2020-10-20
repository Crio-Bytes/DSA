// A program to find the maximum number of Nodes at a Given Level

#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 

// Binary Tree node 
struct Node { 
	int data; 
	Node* left; 
	Node* right;
}; 
//New Node
TreeNode* newNode(int item)
{
    TreeNode* temp = new TreeNode;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

//Function to find maximum element at a given Level
int findMaxNodeatLevel(Node* root int level) 
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
	root = newNode(45); 
    root->left = newNode(46); 
    root->left->left = newNode(18); 
    root->left->left->left = newNode(16);
    root->left->left->right = newNode(23); 
    root->left->right = newNode(17); 
    root->left->right->left = newNode(24); 
    root->left->right->right = newNode(21); 
    root->right = newNode(15); 
    root->right->left = newNode(22); 
     
    root->right->left->left = newNode(37); 
    root->right->left->right = newNode(41); 
    root->right->right = newNode(19); 
    root->right->right->left = newNode(49); 
    root->right->right->right = newNode(29); 
     
     
    int level = 3;
   
	cout << "Max Node in a Binary Tree of a given Level  is \n"; 
	cout << findMaxNodeatLevel(root,level); 

	return 0; 
} 
