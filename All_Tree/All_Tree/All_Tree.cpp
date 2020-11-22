// All_Tree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;
typedef struct _node node;
struct _node
{
	node * left;
	int key;
	node * right;
};
node * root=NULL;
node * Getnode(int key)
{
	node * tmp = (node *)malloc(sizeof(_node));
	tmp->key=key;
	tmp->left=tmp->right=NULL;
	return tmp;
}
void remove_node(node * nd)
{
	if(nd)
		free(nd);
}
node * SearchBST(int key,node * root)
{
	if( root == NULL)
			return NULL;
	if(root->key  == key )
	{	
		return root;
	}
	else if(root->key  < key )
	{
		return SearchBST(key,root->left);
	}
	else
	{
		return SearchBST(key,root->right);
	}
}

node * AddToBst(int key,node * root)
{
	if(root == NULL)
	{
		return Getnode(key);
	}
	if(key < root->key)
	{
		root->left = AddToBst(key,root->left);
	}
	else
	{
		root->right = AddToBst(key,root->right);
	}

	//return the unchanged node;
	return root;
}

node * getMinvalue(node * root)
{
	while (root->left)
	{
		root=root->left;
	}
	return root;
}
node * removeBstNode(int key,node * root)
{

	if((root) == NULL)
	{
		cout<<"No node found"<<endl;
		return NULL;
	}
	if(key < root->key )
	{
		root->left = removeBstNode(key,root->left);
	}
	else if(key > root->key)
	{
		root->right = removeBstNode(key,root->right);
	}
	else
	{
		if(root->left == NULL)
		{
			node * tmp = root->right;
			remove_node(root);
			return tmp;
		}
		else if(root->right == NULL)
		{
			node * tmp = root->left;
			remove_node(root);
			return tmp;
		}
		node * tmp = getMinvalue(root->right);
		root->key = tmp->key;
		root->right = removeBstNode(tmp->key,root->right);
	}
	return root;
}

void inorder(node *root)
{
	if(root == NULL)
		return ;
	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
}

int _tmain(int argc, _TCHAR* argv[])
{
	root = AddToBst(50,root);
	root = AddToBst(30,root);
	root = AddToBst(20,root);
	root = AddToBst(40,root);
	root = AddToBst(70,root);
	root = AddToBst(60,root);
	root = AddToBst(80,root);

	printf("Inorder traversal of the given tree \n");
	inorder(root);
	cout<<endl;

	printf("\nDelete 20\n");
	root = removeBstNode(20,root);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);
	cout<<endl;
	printf("\nDelete 30\n");
	root = removeBstNode(30,root);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);
	cout<<endl;
	printf("\nDelete 50\n");
	root = removeBstNode(50,root);
	printf("Inorder traversal of the modified tree \n");
	inorder(root);
	cout<<endl;
	return 0;
}

