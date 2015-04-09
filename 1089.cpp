//判断一个经过某种排序到一部分的结果是插入拍寻还是归并排序
#include <iostream>
using namespace std;
#define MAX 105
int array1[MAX],array2[MAX];
int N;
void InsertSort(int start)
{
	int i,tmp,min,pick;
	tmp = array2[start];
	pick=0;
	while (pick<start)
	{
		if (array2[pick]>array2[start]) break;
		pick++;
	}
	for(i=start;i>pick;i--)
	{
		array2[i] = array2[i-1];
	}
	array2[pick] = tmp;
}
bool cmp(int* array1,int* array2)
{
	for(int i=0;i<N;i++)
	if (array1[i]!=array2[i]) return false;
	return true;
}
void MergeSort()
{
	int i,j,k,tmp;
	int flag=1,base=1;
	while (flag)
	{
		if (cmp(array1,array2)) flag = 0;
		base *=2;
		for(i=0;i<N/base;i++)
		for(j=0;j<base-1;j++)
		for(k=j+1;k<base;k++)
		{
			if (array1[i*base+k]<array1[i*base+j])
			{
				tmp = array1[i*base+k];
				array1[i*base+k] = array1[i*base+j];
				array1[i*base+j] = tmp;
			}
		}
		for(j=N/base*base;j<N-1;j++)
		for(k=j+1;k<N;k++)
		{
			if (array1[k]<array1[j])
			{
				tmp = array1[k];
				array1[k] = array1[j];
				array1[j] = tmp;
			}
		}
	}
}
void Print(int* array)
{
	for(int i=0;i<N;i++)
	if (0 == i) printf("%d",array[i]);
	else printf(" %d",array[i]);
}
int main()
{
	int i,len,flag;
	cin >> N;
	for(i=0;i<N;i++)
		cin>>array1[i];
	for(i=0;i<N;i++)
		cin>>array2[i];
	len = 1;
	while (len<N)
	{
		if(array2[len]<array2[len-1]) break;
		len++;
	}
	flag = 1;
	for(i=len;i<N;i++)			//找到第一个不顺序的节点，看从他开始到最后是否一样，一样：表明未处理，即为插入排序
	if (array1[i] != array2[i])
	{
		flag = 0;
		break;
	}
	if (flag)
	{
		printf("Insertion Sort\n");
		InsertSort(len);
		Print(array2);
	}
	else
	{
		printf("Merge Sort\n");
		MergeSort();
		Print(array1);
	}
	//system("pause");
	return 0;
}