#include <stdlib.h>
#include <memory.h>

enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F };

struct IntSetBitVecC
{
//public:
	int (*init)(struct IntSetBitVecC * bitSet, int maxelements, int maxval);
	void (*destroy)(struct IntSetBitVecC ** bitSet);
	int (*size)(struct IntSetBitVecC * bitSet);
	void (*insert)(struct IntSetBitVecC * bitSet, int t);
	void (*report)(struct IntSetBitVecC * bitSet, int * v);

//private:
	int n, hi, *x;
	void (*set)(struct IntSetBitVecC * bitSet, int i);
	void (*clr)(struct IntSetBitVecC * bitSet, int i);
	int (*test)(struct IntSetBitVecC * bitSet, int i);
};

static void set(struct IntSetBitVecC * bitSet, int i)
{
	bitSet->x[i>>SHIFT] |= (1 << (i & MASK));
}

static void clr(struct IntSetBitVecC * bitSet, int i)
{
	bitSet->x[i>>SHIFT] &= ~(1 << (i & MASK));
}

static int test(struct IntSetBitVecC * bitSet, int i)
{
	return bitSet->x[i>>SHIFT] & (1 << (i & MASK));
}

static int init(struct IntSetBitVecC * bitSet, int maxelements, int maxval)
{
	int i;
	int ret = 0;
	if (bitSet) {
		bitSet->hi = maxval;
		bitSet->x = (int *)malloc((1 + bitSet->hi/BITSPERWORD) * sizeof(int));
		if (bitSet->x) {
			for (i = 0; i < bitSet->hi; i++) {
				bitSet->clr(bitSet, i);
			}
			bitSet->n = 0;
			ret = 1;//≥…π¶
		}
	}
	return ret;
}

static void destroy(struct IntSetBitVecC ** bitSet)
{
	if (bitSet) {
		if (*bitSet) {
			if ((*bitSet)->x)
				free((*bitSet)->x);
			free(*bitSet);
			*bitSet = NULL;
		}
	}
}

static int size(struct IntSetBitVecC * bitSet)
{
	if (bitSet) {
		return bitSet->n;
	}
	return 0;
}

static void insert(struct IntSetBitVecC * bitSet, int t)
{
	if (bitSet) {
		if (bitSet->test(bitSet, t))
			return;
		bitSet->set(bitSet, t);
		bitSet->n++;
	}
}

static void report(struct IntSetBitVecC * bitSet, int * v)
{
	if (bitSet) {
		int i, j = 0;
		for (i = 0; i < bitSet->hi; i++) {
			if (bitSet->test(bitSet, i))
				v[j++] = i;
		}
	}
}

struct IntSetBitVecC * createIntSetBitVecC(void) 
{
	struct IntSetBitVecC * b = NULL;
	b = (struct IntSetBitVecC *)malloc(sizeof(struct IntSetBitVecC));
	if (b) {
		memset(b, 0, sizeof(struct IntSetBitVecC));
		b->init = init;
		b->destroy = destroy;
		b->size = size;
		b->insert = insert;
		b->report = report;
		b->set = set;
		b->clr = clr;
		b->test = test;
	}
	return b;
}

//////////////////////////////////////////////////////////////////////////
//≤‚ ‘
#include <stdio.h>
#include <time.h>
static void gensets(int m, int maxval)
{
	int * v = NULL;
	int i;
	struct IntSetBitVecC * s = createIntSetBitVecC();

	v = (int *)malloc(m * sizeof(int));
	if (NULL == v)
		return;

	if (s) {
		srand((int)time(NULL));
		if (s->init(s, m, maxval)) {
			while(s->size(s) < m)
			{
				s->insert(s, rand()%maxval);
			}
			
			s->report(s, v);
			
			for (i = 0; i < m; i++)
			{
				printf("%d, ", v[i]);
			}
			printf("\n");
		}
		s->destroy(&s);
	}

}

void testSetBitVecC(void)
{
	gensets(10, 100);
}