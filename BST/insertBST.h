#include<bits/stdc++.h>
using namespace std;

class BSTNode
{
    public:
	BSTNode* left,*right;
	string val;
	string key;
	BSTNode(string key);
	BSTNode(string key,string value);
	string  getvalue();
	string getkey();
	BSTNode* getleftnode();
	BSTNode* getrightnode();
	void setleftnode(BSTNode* node);
	void setrightnode(BSTNode* node);
	void writetofile();
};
