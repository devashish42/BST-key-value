#include<bits/stdc++.h>
#include"insertBST.h"
using namespace std;




	BSTNode::BSTNode(string key,string val)
	{ this->val=val;this->key=key;left=NULL;right=NULL;writetofile(); }
	BSTNode::BSTNode(string key)
	{
		fstream f1;
		f1.open(key,ios::in|ios::out);
		vector<string> s;string line;
		while(f1)
		{
			getline(f1,line);
			s.push_back(line);
		}
		f1.close();
		this->key=s[0];
		this->val=s[1];
		if(s[2]=="NULL")
			this->left=NULL;
		else
			this->left=new BSTNode(s[2]);
		
		if(s[3]=="NULL")
			this->right=NULL;
		else
			this->right=new BSTNode(s[3]);
		
	}
	string  BSTNode::getvalue(){return this->val;}
	string BSTNode::getkey(){ return this->key;}
	BSTNode* BSTNode::getleftnode(){return this->left ;}
	BSTNode* BSTNode::getrightnode(){return this->right ;}
	void BSTNode::setleftnode(BSTNode* node){this->left=node;writetofile();}
	void BSTNode::setrightnode(BSTNode* node){this->right=node;writetofile();}
	void BSTNode::writetofile()
	{
		fstream f;
		f.open(key,ios::in | ios::out| ios::trunc);
		string lnode=left?left->getkey():"NULL";
		string rnode=right?right->getkey():"NULL";
		string d=key+"\n"+val+"\n"+lnode+"\n"+rnode;
		f<<d<<endl;
		f.close();
	}
