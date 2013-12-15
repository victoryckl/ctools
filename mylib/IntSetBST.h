class IntSetBST
{
public:
	IntSetBST(int maxlements, int maxval) { root = 0; n = 0; }
	~IntSetBST();
	int size() { return n; }
	void insert(int t) { root = rinsert(root, t); }
	void report(int * x) { v = x; vn = 0; traverse(root); }
protected:
private:
	int n, *v, vn;
	struct node {
		int val;
		node * left, * right;
		node(int i){val = i; left = right = 0;}
	};
	node * root;
	node * rinsert(node * p, int t);
	void traverse(node * p);
	void DeleteNode(IntSetBST::node * p);
};
