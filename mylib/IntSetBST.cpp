#include "IntSetBST.h"

IntSetBST::~IntSetBST()
{
	DeleteNode(root);
}

IntSetBST::node * IntSetBST::rinsert(IntSetBST::node * p, int t)
{
	if (p == 0)
	{
		p = new node(t);
		n++;
	}
	else if (t < p->val)
	{
		p->left = rinsert(p->left, t);
	}
	else if (t > p->val)
	{
		p->right = rinsert(p->right, t);
	}
	else
	{
		//do nothing if p->val == t
	}
	return p;
}

void IntSetBST::traverse(IntSetBST::node * p)
{
	if (p == 0)
		return;
	traverse(p->left);
	v[vn++] = p->val;
	traverse(p->right);
}

void IntSetBST::DeleteNode(IntSetBST::node * p)
{
	if (p == 0)
		return;
	DeleteNode(p->left);
	DeleteNode(p->right);
	delete p;
}


//////////////////////////////////////////////////////////////////////////
//≤‚ ‘

#include <cstdlib>
#include <iostream>

using namespace std;

static void gensets(int m, int maxval)
{
	int * v = new int[m];
	IntSetBST s(m, maxval);
	while(s.size() < m)
	{
		s.insert(rand()%maxval);
	}
	
	s.report(v);
	
	for (int i = 0; i < m; i++)
	{
		cout << v[i] << "\n";
	}
}

void testSetBST(void)
{
	gensets(10, 100);
}