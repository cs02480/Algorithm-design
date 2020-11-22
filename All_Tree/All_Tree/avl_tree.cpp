#include "stdafx.h"
#include <iostream>
using namespace std;

typedef struct _avlnode 
{
	int key;
	int bf;
	_avlnode * left;
	_avlnode * right;
}avlnode;
avlnode * root=NULL;
avlnode * new_node(int key)
{
	avlnode * tmp = (avlnode *)malloc(sizeof(avlnode));
	tmp->bf=0;
	tmp->left=tmp->right=NULL;
	tmp->key=key;
	return tmp;
}
void free_node(avlnode * tmp)
{
	if (tmp==NULL)
	{
		return;
	}
	free(tmp);
}
avlnode* rotate_to_right(avlnode*root,int *ub)
{
	avlnode * child = root->left;
	if(child->bf == 1)
	{
		root->left = child->right;
		child->right=root;
		child->bf=root->bf=0;
		*ub=0;
		return child;
	}
	else
	{
		avlnode * grndchild = child->right;
		child->right=grndchild->left;
		root->left = grndchild->right;
		grndchild->left=child;
		grndchild->right=root;
		switch (grndchild->bf)
		{
		case 0:
			child->bf=root->bf=0;
			break;
		case 1:
			child->bf=0;
			root->bf=-1;
			break;
		case -1:
			child->bf=1;
			root->bf=0;

		}
		*ub=0;
		grndchild->bf=0;
		return grndchild;
	}

}


avlnode* del_rotate_to_right(avlnode*root,int *ub)
{
	avlnode * child = root->left;
	if(child->bf >=0)
	{
		root->left = child->right;
		child->right=root;
		child->bf=root->bf=0;
		*ub=0;
		return child;
	}
	else
	{
		avlnode * grndchild = child->right;
		child->right=grndchild->left;
		root->left = grndchild->right;
		grndchild->left=child;
		grndchild->right=root;
		switch (grndchild->bf)
		{
		case 0:
			child->bf=root->bf=0;
			break;
		case 1:
			child->bf=0;
			root->bf=-1;
			break;
		case -1:
			child->bf=1;
			root->bf=0;

		}
		*ub=0;
		grndchild->bf=0;
		return grndchild;
	}

}
avlnode* rotate_to_left(avlnode*root,int *ub)
{
	avlnode * child = root->right;
	if(child->bf == -1)
	{
		root->right = child->left;
		child->left=root;
		child->bf=root->bf=0;
		*ub=0;
		return child;
	}
	else
	{
		avlnode * grndchild = child->left;
		child->left =grndchild->right;
		root->right = grndchild->left;
		grndchild->right = child;
		grndchild->left  = root;
		switch (grndchild->bf)
		{
		case 0:
			child->bf=root->bf=0;
			break;
		case 1:
			child->bf=-1;
			root->bf=0;
			break;
		case -1:
			child->bf=0;
			root->bf=1;

		}
		*ub=0;
		grndchild->bf=0;
		return grndchild;
	}

}

avlnode* del_rotate_to_left(avlnode*root,int *ub)
{
	avlnode * child = root->right;
	if(child->bf <= 0)
	{
		root->right = child->left;
		child->left=root;
		child->bf=root->bf=0;
		*ub=0;
		return child;
	}
	else
	{
		avlnode * grndchild = child->left;
		child->left =grndchild->right;
		root->right = grndchild->left;
		grndchild->right = child;
		grndchild->left  = root;
		switch (grndchild->bf)
		{
		case 0:
			child->bf=root->bf=0;
			break;
		case 1:
			child->bf=-1;
			root->bf=0;
			break;
		case -1:
			child->bf=0;
			root->bf=1;

		}
		*ub=0;
		grndchild->bf=0;
		return grndchild;
	}

}
avlnode * addtoAvl(avlnode * root,int key,int *ub)
{
		if(root == NULL)
		{
			*ub=1;
			return new_node(key); 
		}

		if (root->key > key)
		{
			root->left = addtoAvl(root->left,key,ub);
			if(*ub)
			{
				switch (root->bf)
				{
				case -1:
					root->bf=0;
					*ub=0;
					break;
				case 0:
					root->bf=1;
					break;
				case 1:
					root = rotate_to_right(root,ub);//LL aand LR
				}
			}
		}
		else if(root->key < key)
		{
			root->right = addtoAvl(root->right,key,ub);
			if(*ub)
			{
				switch (root->bf)
				{
				case 1:
					root->bf=0;
					*ub=0;
						break;
				case 0:
					root->bf=-1;
					break;
				case -1:
					root = rotate_to_left(root,ub);//RR aand RL
				}
			}
		}

		return root;
}
void preOrder(avlnode *root)
{
	if(root != NULL)
	{
		printf("%d ", root->key);
		preOrder(root->left);
		preOrder(root->right);
	}
}
avlnode * minNode(avlnode * root)
{
	while (root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}
avlnode * removeNode(avlnode * root,int key)
{
	if(root == NULL)
		return NULL;
	int ub=0;
	if(root->key > key)
	{
		root->left = removeNode(root->left,key);
		switch (root->bf)
		{
		case 1:
			root->bf = 0;
			break;
		case 0:
			root->bf = -1;
			break;
		case -1:
			root = del_rotate_to_left(root,&ub);
		}
	}
	else if (root->key < key)
	{
		root->right = removeNode(root->right,key);
		switch (root->bf)
		{
		case -1:
			root->bf=0;
			break;
		case 0:
			root->bf=1;
			break;
		case 1:
			root = del_rotate_to_right(root,&ub);//LL aand LR
		}
	}
	else
	{
		if(root->left == NULL)
		{
			avlnode * tmp = root->right;
			free_node(root);
			//root->bf = 0;
			return tmp;
		}
		else if(root->right == NULL)
		{
			avlnode * tmp = root->left;
			free_node(root);
			//root->bf = 0;
			return tmp;
		}
		avlnode * min_node = minNode(root->right);
		root->key = min_node->key;

		root->right = removeNode(root->right,min_node->key);
		ub=0;
		switch (root->bf)
		{
		case -1:
			root->bf=0;
			break;
		case 0:
			root->bf=1;
			break;
		case 1:
			root = del_rotate_to_right(root,&ub);//LL aand LR
		}
	}
}
int main()
{
	int ub=0;
	root = addtoAvl(root, 9,&ub);ub=0;
	root = addtoAvl(root, 5,&ub);ub=0;
	root = addtoAvl(root, 10,&ub);ub=0;
	root = addtoAvl(root, 0,&ub);ub=0;
	root = addtoAvl(root, 6,&ub);ub=0;
	root = addtoAvl(root, 11,&ub);ub=0;
	root = addtoAvl(root, -1,&ub);ub=0;
	root = addtoAvl(root, 1,&ub);ub=0;
	root = addtoAvl(root, 2,&ub);ub=0;
	preOrder(root);
	cout<<endl;
	root = removeNode(root,10);
	preOrder(root);
	cout<<endl;

	root = removeNode(root,6);
	preOrder(root);
	cout<<endl;
	return 0;
}