/*
平移向量
将一个具有n个元素的一维向量向左旋转i个位置
例如，假设n=8,i=3,那么向量abcdefgh旋转之后得到向量defghabc。

旋转向量X实际上就是将向量ab的两个部分交换为向量ba，
先从ab开始，转置a得到aTb，再转置b得到aTbT，然后转置aTbT，得到(aTbT)T，即ba，
reverse(0, i - 1);// cbadefgh
reverse(i, n - 1);// cbahgfed
reverse(0, n - 1);// defghabc
*/

static void reverse(void * list, int start, int end,
			 void (*swapFunc)(void * list, int i, int j))
{
    while (start < end)
    {
		swapFunc(list, start, end);
        start++;
        end--;
    }
}

void shift(void * list, int count, int i,
				  void (*swapFunc)(void * list, int i, int j))
{
    reverse(list, 0,     i - 1, swapFunc);
    reverse(list, i, count - 1, swapFunc);
    reverse(list, 0, count - 1, swapFunc);
}

//////////////////////////////////////////////////////////////////////////
//测试

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mySwap(void * list, int i, int j)
{
	char * x = (char *)list;
	char t;

	t = x[i];
	x[i] = x[j];
	x[j] = t;
}

void testShift(void)
{
	char x1[20] = "abcdefgh";
	char x2[30] = "abcdefghijklmnopqrstuvwxyz";

	printf("%s\n", x1);
	shift(x1, strlen(x1), 3, mySwap);
	printf("%s\n", x1);

	printf("%s\n", x2);
	shift(x2, strlen(x2), 20, mySwap);
	printf("%s\n", x2);	
}