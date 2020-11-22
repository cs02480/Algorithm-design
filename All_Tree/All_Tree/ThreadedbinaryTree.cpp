#include "stdafx.h"
#include <iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
typedef struct _tnode Tnode;
struct _tnode
{
	Tnode * left_child;
	short left_thread;
	int key;
	short right_thread;
	Tnode * right_child;
};
Tnode * troot=NULL;
Tnode * DumyNode=NULL;
Tnode * GetThreadNode(int key)
{
	Tnode * tmp = (Tnode *)malloc(sizeof(Tnode));
	tmp->key=key;
	tmp->left_thread=tmp->right_thread=TRUE;
	tmp->left_child=tmp->right_child=NULL;
	return tmp;
}

void FreeTnode(Tnode * node)
{
	if(node)
		free(node);
}


Tnode * insucc(Tnode * node)
{
	Tnode * tmp = node->right_child;
	if(!node->right_thread)
		while (!tmp->left_thread)
		{
			tmp=tmp->left_child;
		}
	return tmp;
}
void tinorder(Tnode * root)
{
	Tnode * temp = root;
	while (!temp->left_thread)
	{
		temp=temp->left_child;
	}
	//cout<<temp->key<<" "
	do 
	{
		cout<<temp->key<<" ";
		temp = insucc(temp);
	} while (temp != DumyNode);
	cout<<endl;
}
void InitThreadTree(int key)
{
	if(troot)
		return;
	if(DumyNode == NULL)
	{
		DumyNode = GetThreadNode(INT_MAX);
		DumyNode->right_thread=FALSE;
		DumyNode->right_child=DumyNode;
		DumyNode->left_child=DumyNode;
		DumyNode->left_thread=TRUE;
	}

	if(troot == NULL)
	{
		troot=GetThreadNode(key);
		troot->left_child=troot->right_child=DumyNode;
		DumyNode->left_child=troot;
		DumyNode->left_thread=FALSE;
		return ;
	}
}
void insertTnode(Tnode * root,int key)
{
	if(root == NULL)
	{
		InitThreadTree(key);
		return ;
	}
	
	while (1)
	{
		if(key < root->key)
		{	
			if(root->left_thread == TRUE)
				break;

			root=root->left_child;
		}
		else if(root->key < key)
		{
			if(root->right_thread == TRUE)
					break;
			root=root->right_child;
		}
	}
	Tnode * newNode = GetThreadNode(key);
	if(key < root->key)
	{	
		root->left_thread=FALSE;
		newNode->left_thread=newNode->right_thread=TRUE;
		newNode->left_child=root->left_child;
		newNode->right_child=root;
		root->left_child=newNode;
	}
	else if(root->key < key)
	{
		root->right_thread = FALSE;
		newNode->left_thread=newNode->right_thread=TRUE;
		newNode->right_child=root->right_child;
		newNode->left_child=root;
		root->right_child=newNode;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	insertTnode(troot,50);
	insertTnode(troot,30);
	insertTnode(troot,20);
	insertTnode(troot,40);
	insertTnode(troot,70);
	insertTnode(troot,60);
	insertTnode(troot,80);
	tinorder(troot);
}