class IntSetBitVec
{
public:
	IntSetBitVec(int maxelements, int maxval);
	~IntSetBitVec();
	int size() { return n; }
	void insert(int t);
	void report(int * v);
private:
	enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F };
	int n, hi, *x;
	void set(int i) { x[i>>SHIFT] |= (1 << (i & MASK)); }
	void clr(int i)	{ x[i>>SHIFT] &= ~(1 << (i & MASK)); }
	int test(int i) { return x[i>>SHIFT] & (1 << (i & MASK)); }
};