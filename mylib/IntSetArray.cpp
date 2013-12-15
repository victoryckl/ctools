#include "IntSetArray.h"

IntSetArray::IntSetArray(int maxelements, int maxval)
{
	x = new int[1 + maxelements];
	n = 0;
	x[0] = maxval;
}

IntSetArray::~IntSetArray()
{
	delete [] x;
}

void IntSetArray::insert(int t)
{
	for (int i = 0; x[i] < t; i++)
		;

	if (x[i] == t)
		return ;

	for (int j = n; j >= i; j--)
		x[j+1] = x[j];

	x[i] = t;
	n++;
}

void IntSetArray::report(int * v)
{
	for (int i = 0; i < n; i++)
		v[i] = x[i];
}

//////////////////////////////////////////////////////////////////////////
//²âÊÔ
#include <cstdlib>
#include <iostream>

using namespace std;

static void gensets(int m, int maxval)
{
	int * v = new int[m];
	IntSetArray s(m, maxval);
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

void testSetArray(void)
{
	gensets(10, 100);
}