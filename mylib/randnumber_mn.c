#include <stdlib.h>
#include <memory.h>
#include <time.h>

//---------------------------------------------------------
//λ����
enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F };

struct tagBitOption;
typedef struct tagBitOption BitOption;

struct tagBitOption {
	int (*init)(BitOption * bit, int m, int n, int k);
	void (*destroy)(BitOption ** bit);

	void (*set)(BitOption * bit, int i);
	void (*clr)(BitOption * bit, int i);
	int (*test)(BitOption * bit, int i);

	int m, n, k, *x;
};

static void set(BitOption * bit, int i)
{
	int t;
	if (bit && (i >= bit->m) && (i < bit->n)) {
		t = i - bit->m;
		bit->x[t>>SHIFT] |= (1 << (t & MASK));
	}
}

static void clr(BitOption * bit, int i)
{
	int t;
	if (bit && (i >= bit->m) && (i < bit->n)) {
		t = i - bit->m;
		bit->x[t>>SHIFT] &= ~(1 << (t & MASK));
	}
}

static int test(BitOption * bit, int i)
{
	int t;
	if (bit && (i >= bit->m) && (i < bit->n)) {
		t = i - bit->m;
		return bit->x[t>>SHIFT] & (1 << (t & MASK));
	}
	return 1;//��i���ڷ�Χ[m,n)������Ϊi���ڵģ�������Ҫ�������������
}

static int init(BitOption * bit, int m, int n, int k)
{
	int s;
	int ret = 0;
	if (bit) {
		bit->m = m;
		bit->n = n;
		bit->k = k;
		s = (1 + (n - m)/BITSPERWORD) * sizeof(int);
		bit->x = (int *)malloc(s);
		if (bit->x) {
			memset(bit->x, 0, s);
			ret = 1;//�ɹ�
		}
	}
	return ret;
}

static void destroy(BitOption ** bit)
{
	if (bit) {
		if (*bit) {
			if ((*bit)->x)
				free((*bit)->x);
			free(*bit);
			*bit = NULL;
		}
	}
}

//ĳЩ���ֲ��ܳ��������������У���������һ��
static void setInvalidNumber(BitOption * bit, int * inum, int size)
{
	if (bit && inum && size > 0) {
		int i;
		for (i = 0; i < size; i++) {
			bit->set(bit, inum[i]);
		}
	}
}

static BitOption * createBitOption(int m, int n, int k) 
{
	BitOption * b = NULL;
	b = (BitOption *)malloc(sizeof(BitOption));
	if (b) {
		memset(b, 0, sizeof(BitOption));
		b->init = init;
		b->destroy = destroy;
		b->set = set;
		b->clr = clr;
		b->test = test;
		if (!b->init(b, m, n, k))
			b->destroy(&b);
	}
	return b;
}

//---------------------------------------------------------

//����һ�����飬����k�����ظ�������������Ҫ����Щ������ΧΪ[m,n)
//���ɵĽ���в��ܰ���inum�е����֣�size��ʾinum�ĳ���
//m < n, k < n - m
int * RandNumberMN(int m, int n, int k, int * inum, int size)
{
	int i,t;
	int * result = NULL;
	BitOption * bit = NULL;
	int ok = 0;

	do {
		srand((int)time(NULL));
		if (m >= n || k > n - m)
			break;
		bit = createBitOption(m, n, k);
		if (NULL == bit)
			break;
		setInvalidNumber(bit, inum, size);
		result = malloc(k * sizeof(int));
		if (NULL == result)
			break;
		for (i = 0; i < k; i++) {
			while(bit->test(bit, t = rand()%(n-m+1)+m));
			result[i] = t;
			bit->set(bit, t);
		}
		ok = 1;
	} while (0);
	if (bit)
		bit->destroy(&bit);
	if (1 != ok) {
		if (result) {
			free(result);
			result = NULL;
		}
	} 
	return result;
}

//////////////////////////////////////////////////////////////////////////
//����
#include <stdio.h>

void testRandMN(void)
{
	time_t start, end;
	int * result = NULL;
	int m = 490, n = 540, k = 10;
	int inum[] = {3, 90, 200, 305, 487, 503, 500, 501,502, 504};

	printf("m = %d, n = %d, k = %d\n", m, n, k);

	start = time(NULL);
	result = RandNumberMN(m, n, k, inum, sizeof(inum)/sizeof(inum[0]));
	end = time(NULL);
	printf("time = %d\n\n", end - start);

	if (result) {
		printf("RandNumber success!\n");
		if (k < 200) {//������Сʱ���鿴����Ƿ����Ҫ��
			int i;
			for (i = 0; i < k; i++) {
				printf("%d, ", result[i]);
			}
			printf("\n");
		}
		free(result);
		result = NULL;
	} else {
		printf("RandNumber failed!\n\n");
	}
}

