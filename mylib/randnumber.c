#include <stdlib.h>
#include <memory.h>
#include <time.h>

int bigrand(void)
{
	return RAND_MAX * rand() + rand();
}

int randint(int n, int u)
{
	return n + bigrand() % (u - n + 1);
}

//����һ�����飬����k�����ظ�������������Ҫ����Щ������ΧΪ[0,n)
int * RandNumber(int n, int k)
{
	int i,j;
	int * result = NULL;
	char * appear = NULL; //����Ƿ���ֹ���
	int ok = 0;

	do {
		srand((int)time(NULL));

		result = malloc(k * sizeof(int));
		if (NULL == result)
			break;

		appear = malloc(n * sizeof(char));
		if (NULL == appear)
			break;
		memset(appear, 0, n * sizeof(char));
		
		for (i = 0; i < k; i++) {

			//ʹ��rand()���ܵ�RAND_MAX�����ƣ�k > RAND_MAX ʱ������ѭ��
			while(appear[j = rand()%n]);
			//while(appear[j = (int)(1.0 * n * rand()/(RAND_MAX))]);

			result[i] = j;
			appear[j] = 1;
		}

		ok = 1;
	} while (0);

	if (appear) {
		free(appear);
		appear = NULL;
	}

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
#include <time.h>

#define COUNT	20//9999
//#define COUNT  (RAND_MAX)
//#define COUNT  (RAND_MAX * 2)

//����RAND_MAX�����ƣ����ܲ���̫�಻ͬ������������ｫ������ѭ��
//#define COUNT  (RAND_MAX * 2 + 4)

void testRand(void)
{
	time_t start, end;
	int * result = NULL;

	printf("n = %d, k = %d\n", COUNT, COUNT/2);

	start = time(NULL);

	result = RandNumber(COUNT, COUNT/2);

	end = time(NULL);

	printf("time = %d\n\n", end - start);

	if (result) {
		if (COUNT < 200)
		{//������Сʱ���鿴����Ƿ����Ҫ��
			int i;
			for (i = 0; i < COUNT / 2; i++)
			{
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


void testRandNumber(void)
{
	testRand();
}

