#include <bits/stdc++.h>
using namespace std;
//create a class for node
class Node
{
	public:
	int data;
	node* left;
	node* right;
};

//function to get vertical order
void get_vertical_order(Node* root,int t,map<int,vector<int>>&m)
{
	if(root==NULL)
	{
		return;
	}
	m[t].push_back(root->data);
	//getting left data
	get_vertical_order(root->left,t-1,m);
	//getting right data
	get_vertical_order(root->right,t+1,m);
}
//to print the vertical order
void print(Node* root)
{
	map<int ,vector<int>> m;
	int t=0;
	get_vertical_order(root,t,m);
	map< int,vector<int> > :: iterator i;
	for(i=m.begin();i!=m.end();i++)
	{
		for (int j=0;j<i->second.size();++j)
            cout << i->second[j] << " ";
        cout << "\n";
	}
}
