#include "IntSetBitVec.h"

IntSetBitVec::IntSetBitVec(int maxelements, int maxval)
{
	hi = maxval;
	x = new int[1 + hi/BITSPERWORD];
	for (int i = 0; i < hi; i++) {
		clr(i);
	}
	n = 0;
}

IntSetBitVec::~IntSetBitVec()
{
	delete [] x;
}

void IntSetBitVec::insert(int t)
{
	if (test(t))
		return;
	set(t);
	n++;
}

void IntSetBitVec::report(int * v)
{
	int j = 0;
	for (int i = 0; i < hi; i++) {
		if (test(i))
			v[j++] = i;
	}
}


//////////////////////////////////////////////////////////////////////////
//²âÊÔ

#include <cstdlib>
#include <iostream>

using namespace std;

static void gensets(int m, int maxval)
{
	int * v = new int[m];
	IntSetBitVec s(m, maxval);
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

void testSetBitVec(void)
{
	gensets(10, 100);
}