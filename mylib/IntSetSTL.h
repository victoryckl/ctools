
#include <set>

class IntSetSTL
{
private:
	set <int> S;
public:
	IntSetSTL(int maxelements, int maxval){}
	int size(){ return S.size(); }
	void insert(int t) { S.insert(t); }
	void report(int * v)
	{
		int j = 0;
// 		set <int>::iterator i;
// 		for (i = S.begin; i != S.end(); ++i)
// 			v[j++] = *i;
	}

};