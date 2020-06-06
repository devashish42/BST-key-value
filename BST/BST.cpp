#include<bits/stdc++.h>
#include"BST.h"
using  namespace std;

	BST::BST()
	{
		ifstream fin("root.txt");
		string line;
		if(fin)
		{
			getline(fin,line);
			if(line.size())
			this->root=new BSTNode(line);	
			else
			this->root=NULL;
		}
		else
		{
			this->root=NULL;
		}
	}
	void BST::put(string key,string val)
	{
		putIN(root,key,val);
	}
	void BST::putIN(BSTNode* root,string key,string val)
	{
		if(!root)
		{
			this->root =new BSTNode(key,val);
			fstream f1;
			f1.open("root.txt",ios::out|ios::in);
			string line=this->root->key;
			
			f1<<line<<endl;
			f1.close();
			return;
		}
		if(val>root->getvalue())
		{
			if(!root->getrightnode())
			root->setrightnode(new BSTNode(key,val));
			else
			putIN(root->getrightnode(),key,val);
		}
		else
		{
			if(!root->getleftnode())
			root->setleftnode(new BSTNode(key,val));
			else
			putIN(root->getleftnode(),key,val);
		}	
	}
	string BST::get(string key)
	{
		return getIN(root,key);
	}
	string BST::getIN(BSTNode* root,string key)
	{
		if(!root)return "";
		
		if(root->getkey()==key)
		return root->getvalue();
		
		string ls=getIN(root->getleftnode(),key);
		if(ls.size())
		return ls;
		
		return getIN(root->getrightnode(),key);
	}
	
	


