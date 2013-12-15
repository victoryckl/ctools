class IntSetArray
{
private:
	int n, *x;
public:
	IntSetArray(int maxelements, int maxval);
	~IntSetArray();
	int size(void){ return n; }
	void insert(int t);
	void report(int * v);
};