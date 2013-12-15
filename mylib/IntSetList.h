class IntSetList
{
public:
	IntSetList(int maxelements = 0, int maxval = 0);
	~IntSetList();
	int size(){ return n; }
	void insert(int t);
	void report(int * v);
private:
	int n;
	struct node {
		int val;
		node * next;
		node(int v, node * p) { val = v; next = p;}
	};
	node * head, * sentinel;

	node * rinsert(node * p, int t);
};