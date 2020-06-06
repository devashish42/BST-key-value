#include<bits/stdc++.h>

#include"BST.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	BST *bst=new BST();

	bst->put("C","100");
	cout<<bst->get("C")<<endl;
	return 0;
}
