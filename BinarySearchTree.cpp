//Eric Whyne
// 1999
// Binary Search Tree Example Code
// This code demonstrates creating and using binary search trees.
// Shown in the output is the entire tree looked at three different ways.
// 
// License: 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the license or any later version.
//  
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//         



#include <iostream.h>
#define itemsize 20


struct treenode
{
	treenode *lptr;
	treenode *rptr;
	int item;
};

class bintree
{
public:
	bintree();
	void binadd(int data);
	void pre();
	void in();
	void post();

private:
	treenode *root;
	void addnode(int data, treenode *ptr);
	void preoutput(treenode *r);
	void inoutput(treenode *r);
	void postoutput(treenode *r);
};



int main ()
{
	bintree A;
	A.binadd(5);
	A.binadd(7);
	A.binadd(3);
	A.binadd(4);
	A.binadd(9);

	cout<<"Pre:\n";
	A.pre();
	cout<<"In:\n";
	A.in();
	cout<<"Post:\n";
	A.post();
	
	return 0;
}

bintree::bintree (){	root = NULL;	}
void bintree::binadd(int data)
{
	if(root == NULL)
	{
		root = new treenode;
		root->item = data;
		root->lptr = NULL;
		root->rptr = NULL;
	}
	else
		addnode(data, root);
}


void bintree::pre()
{	
	preoutput(root);	
	cout<<"\n\n";	
}
void bintree::in()
{
	inoutput(root);	
	cout<<"\n\n";	
}
void bintree::post ()
{	
	postoutput(root);	
		cout<<"\n\n";	
}
void bintree::preoutput(treenode *r)
{
		
	cout<<"\n"<<r->item;

	if(r->lptr != NULL)
		preoutput(r->lptr);

	if(r->rptr != NULL)
		preoutput(r->rptr);
}
void bintree::inoutput(treenode *r)
{
	
	if(r->lptr != NULL)
	inoutput(r->lptr);
	
	cout<<"\n"<<r->item;
	
	if(r->rptr != NULL)
		inoutput(r->rptr);
}
void bintree::postoutput(treenode *r)
{
	
	if(r->lptr != NULL)
		postoutput(r->lptr);
	
	if(r->rptr != NULL)
		postoutput(r->rptr);

	cout<<"\n"<<r->item;
}


void bintree::addnode(int data, treenode *ptr)
{
	if(data <= ptr->item)
	{
		if(ptr->lptr == NULL)
		{
			ptr->lptr = new treenode;
			ptr->lptr->item = data;
			ptr->lptr->lptr = NULL;
			ptr->lptr->rptr = NULL;
		}
		else
			addnode(data, ptr->lptr);
	}
	else
	{
		if(ptr->rptr == NULL)
		{
			ptr->rptr = new treenode;
			ptr->rptr->item = data;
			ptr->rptr->lptr = NULL;
			ptr->rptr->rptr = NULL;
		}
		else
			addnode(data, ptr->rptr);
	}
};
