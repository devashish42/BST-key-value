#include<bits/stdc++.h>
#include"insertBST.h"
using  namespace std;
class BST
{
	public:
	BSTNode *root;
	
	
	BST();
	void put(string key,string val);
	void putIN(BSTNode* root,string key,string val);
	string get(string key);
	string getIN(BSTNode* root,string key);
	
	
};

