#include "timemod.h"

#define TEST_TIMES 5
#define TEST_COUNT 50000
#define OPTION	free(malloc(1024 * 5))

void testTime(void)
{
	int k = 0;
	int n, i;
	clock_t start, t;
	clock_t timesum = 0;

	printf("(");
	for (n = 0; n < TEST_TIMES; n++)
	{
		if (n>0)
		{
			printf(" + ");
		}
		start = clock();
		for (i = 0; i < TEST_COUNT; i++)
		{
			OPTION;
		}
		t = clock() - start;
		printf("%d", t);
		timesum += t;
	}
	printf(") / %d = %d (ms)\n", TEST_TIMES, timesum / (TEST_TIMES));
}