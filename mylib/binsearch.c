/*
���ֲ���α����
int BinSearch(SeqList * R�� int n , KeyType K )
{
	//�������R[0..n-1]�н��ж��ֲ��ң��ɹ�ʱ���ؽ���λ�ã�ʧ��ʱ����-1
	int low=0,high=n-1,mid; //�õ�ǰ���������ϡ��½�ĳ�ֵ

	if(R[low].key==K)
	{
		return 0;
	}
	while(low<=high)
	{//��ǰ��������R[low..high]�ǿ�
		mid=low+((high-low)/2);//ʹ�� (low + high) / 2 �����������������
		if(R[mid].key==K)
		{
			return mid; //���ҳɹ�����
		}
		if(R[mid].key>K)
			high=mid-1; //������R[low..mid-1]�в���
		else
			low=mid+1; //������R[mid+1..high]�в���
	}
	return -1; //��low>highʱ��ʾ��������Ϊ�գ�����ʧ��
}
*/

//����r[0] ~ r[n - 1]��Ų��Ҽ���
int BinSearch1(int r[], int count, int key)
{
    int low = 0;
	int high = count - 1;
	int mid;

    while (low <= high)
    {
		mid = low + ((high - low) >> 1);
		if (key < r[mid])
		{
			high = mid - 1;
		}
		else if (key > r[mid])
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
    }
    return -1;
}

//���ֲ���ͨ�ð汾
int BinSearch2(
			   void * list,	
			   //�����������

			   int count,
			   //Ԫ������

			   void * key,
			   //Ҫ���ҵ�Ԫ��

			   int (*cmpFunc)(void * key, void * list, int index)
			   //�ȽϺ���
			   //���� 0 ��ʾ��key���; >0 ��ʾ��keyС; <0 ��ʾ��key��
			   )
{
	int ret = 0;
    int low = 0;
	int high = count - 1;
	int mid;
	
    while (low <= high)
    {
		mid = low + ((high - low) >> 1);
		ret = cmpFunc(key, list, mid);
		if (ret < 0)
		{
			high = mid - 1;
		}
		else if (ret > 0)
		{
			low = mid + 1;
		}
		else
		{
			return mid;
		}
    }
    return -1;
}

//////////////////////////////////////////////////////////////////////////
//����
#include <stdio.h>

#define COUNT  11//10

//�ȽϺ���
//���� 0 ��ʾ��key���; >0 ��ʾ��keyС; <0 ��ʾ��key��
int myCompare(void * key, void * list, int index)
{
	int keyValue = (int)key;
	int * array = (int *)list;

	return (keyValue - array[index]);
}


void testBinSearch(void)
{
	int array[COUNT];
	int i;

	for (i = 0; i < COUNT; i++)
	{
		array[i] = i * 2 + 1;
		printf("%d, ", array[i]);
	}
	printf("\n");

	printf("%d -> %d\n", array[0],			BinSearch1(array, COUNT, array[0]));
	printf("%d -> %d\n", array[COUNT / 2],	BinSearch1(array, COUNT, array[COUNT / 2]));
	printf("%d -> %d\n", array[COUNT - 1],	BinSearch1(array, COUNT, array[COUNT - 1]));


	printf("%d -> %d\n", array[0],			BinSearch2(array, COUNT, (void *)(array[0]), myCompare));
	printf("%d -> %d\n", array[COUNT / 2],	BinSearch2(array, COUNT, (void *)(array[COUNT / 2]), myCompare));
	printf("%d -> %d\n", array[COUNT - 1],	BinSearch2(array, COUNT, (void *)(array[COUNT - 1]), myCompare));
}