/*
二分查找伪代码
int BinSearch(SeqList * R， int n , KeyType K )
{
	//在有序表R[0..n-1]中进行二分查找，成功时返回结点的位置，失败时返回-1
	int low=0,high=n-1,mid; //置当前查找区间上、下界的初值

	if(R[low].key==K)
	{
		return 0;
	}
	while(low<=high)
	{//当前查找区间R[low..high]非空
		mid=low+((high-low)/2);//使用 (low + high) / 2 会有整数溢出的问题
		if(R[mid].key==K)
		{
			return mid; //查找成功返回
		}
		if(R[mid].key>K)
			high=mid-1; //继续在R[low..mid-1]中查找
		else
			low=mid+1; //继续在R[mid+1..high]中查找
	}
	return -1; //当low>high时表示查找区间为空，查找失败
}
*/

//数组r[0] ~ r[n - 1]存放查找集合
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

//二分查找通用版本
int BinSearch2(
			   void * list,	
			   //从这里面查找

			   int count,
			   //元素总数

			   void * key,
			   //要查找的元素

			   int (*cmpFunc)(void * key, void * list, int index)
			   //比较函数
			   //返回 0 表示与key相等; >0 表示比key小; <0 表示比key大
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
//测试
#include <stdio.h>

#define COUNT  11//10

//比较函数
//返回 0 表示与key相等; >0 表示比key小; <0 表示比key大
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