// A program to connect Nodes at Same Level in a Binary Tree

struct Node { 
	int data; 
	Node* left; 
	Node* right;

    // Additional pointer to connect Nodes at the Same Level
    Node* nextRight;

	Node(int value) 
	{ 
		data = value; 
		left = NULL;
        right = NULL; 
        nextRight=NULL;
	} 
}; 


void connectNodesAtSameLevel(Node* root) 
{ 
    if (root == NULL) 
        return; 
   
    queue<Node*> q; 
    q.push(root); 

    // An additional marker to denote end of Level
    q.push(NULL);
    while (!q.empty()) { 

            //get element from front of the queue
            Node* temp = q.front(); 
            q.pop(); 

            // Checking if temp is not the last node of the level
            if(temp!=NULL)
            {
                // Assign the front of the queue as the nextRight to the current Node
                //Because the queue's elements will have the elements in Level Order.
                temp->nextRight=q.front();
                 //if left and right child exists,enqueue it to the queue
                if (temp->left) 
                    q.push(temp->left); 
                if (temp->right) 
                    q.push(temp->right); 

            }

            // if queue is not empty, push NULL to mark  
            // nodes at this level are visited 
            else if (!q.empty()) { 
                q.push(NULL);
            }
  
           
           
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
	connectNodesAtSameLevel(root); 

	return 0; 
} 