#include "IntSetList.h"

IntSetList::IntSetList(int maxelements, int maxval)
{
	sentinel = head = new node(maxval, 0);
	n = 0;
}

IntSetList::~IntSetList()
{
	node * p;
	
	do 
	{
		p = head->next;
		delete head;
		head = p;
	} while (head != sentinel);

	delete head;
}

void IntSetList::insert(int t)
{
	head = rinsert(head, t);
}

void IntSetList::report(int * v)
{
	int j = 0;
	node * p;

	for (p = head; p != sentinel; p = p->next)
	{
		v[j++] = p->val;
	}
}

IntSetList::node * IntSetList::rinsert(node * p, int t)
{
	if (p->val < t)
	{
		p->next = rinsert(p->next, t);
	}
	else if (p->val > t)
	{
		p = new node(t, p);
		n++;
	}

	return p;
}

//////////////////////////////////////////////////////////////////////////
//≤‚ ‘

#include <cstdlib>
#include <iostream>

using namespace std;

static void gensets(int m, int maxval)
{
	int * v = new int[m];
	IntSetList s(m, maxval);
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

void testSetList(void)
{
	gensets(10, 100);
}