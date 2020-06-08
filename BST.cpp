#include<bits/stdc++.h>
using namespace std;
class BSTNode
{
public:
	string key,val;
	BSTNode *left,*right;

	BSTNode(string key,string val)
	{ this->val=val;this->key=key;left=NULL;right=NULL; thread t1(&BSTNode::writetofile,this); t1.join();}
	BSTNode(string key)
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
	string getvalue(){return this->val;}
	string getkey(){ return this->key;}
	BSTNode* getleftnode(){return this->left ;}
	BSTNode* getrightnode(){return this->right ;}
	void setleftnode(BSTNode* node){this->left=node;  thread t2(&BSTNode::writetofile,this); t2.join();}
	void setrightnode(BSTNode* node){this->right=node;  thread t3(&BSTNode::writetofile,this); t3.join();}
	void writetofile()
	{
		fstream f;
		f.open(key,ios::in |ios::out|ios::trunc);
		string lnode=left?left->getkey():"NULL";
		string rnode=right?right->getkey():"NULL";
		string d=key+"\n"+val+"\n"+lnode+"\n"+rnode;
		f<<d<<endl;
		f.close();
	}
};

class BST{

public:
	
	BSTNode* root;
	BST()
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
			this->root=NULL;
	}
	bool checkroot()
	{
		return this->root!=NULL;
	}
	void put(string key,string val)
	{
		putIN(root,key,val);
	}
	
	void putIN(BSTNode* root,string key,string val)
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
	string get(string key)
	{
		return getIN(root,key);
	}
	string getIN(BSTNode* root,string key)
	{
		if(!root)return "";
		
		if(root->getkey()==key)
		return root->getvalue();
		
		string ls=getIN(root->getleftnode(),key);
		if(ls.size())
		return ls;
		
		return getIN(root->getrightnode(),key);
	}	
};

int main(int argc, char** argv) 
{
	BST *bst=new BST();
	int c;
	string k,v;
	
	while(1)
	{
		cout<<endl<<"Press 1/2/3  \n1: Enter data  \n2: Find key \n3: Quit"<<endl;
		cin>>c;
		switch(c)
		{
			case 1:
				int n;
				cout<<"Enter the number of nodes to enter "<<endl;
				cin>>n;
				while(n--)
				{
					cout<<"Enter key and value respectively "<<endl;
					cin>>k>>v;
					if( (bst->get(k)).size() )
						cout<<"Key already exists "<<endl;
					else
					bst->put(k,v);
				}
				break;
			case 2:
				cout<<"Enter key to find"<<endl;
				cin>>k;
				if(!bst->checkroot())
				{
					cout<<"No Tree Found ,First Create a Tree"<<endl;break;
				}
				v=bst->get(k);
				if(v.size())
					cout<<"Value = "<<v<<endl;
				else
					cout<<"Key doesn't exist"<<endl;
				break;
			case 3:
				exit(1);
			default:
				cout<<"Wrong choice choose again"<<endl;
				break;
		}
	}

	return 0;
}
