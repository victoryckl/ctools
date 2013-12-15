/*
ƽ������
��һ������n��Ԫ�ص�һά����������תi��λ��
���磬����n=8,i=3,��ô����abcdefgh��ת֮��õ�����defghabc��

��ת����Xʵ���Ͼ��ǽ�����ab���������ֽ���Ϊ����ba��
�ȴ�ab��ʼ��ת��a�õ�aTb����ת��b�õ�aTbT��Ȼ��ת��aTbT���õ�(aTbT)T����ba��
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
//����

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