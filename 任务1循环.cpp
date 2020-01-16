#include<stdio.h>
#define N 10
int a[N]={1,2,3,4,5,6,7,8,9,10};
int BinarySearch(int x)
{
	int left=0;
	int right=a[10]-1;
	while(left<=right)
	{
		int middle=(left+right)/2;
		if(a[middle]==x)
		{
			return middle;//刚好找到关键字 
		}
		else if(a[middle]>x)//比关键字大则关键字在左区域 
		{
			return middle-1;
		}
		else //比关键字小则关键字在右区域 
		{
			return middle+1;
		}
	}
	return -1;//最后仍然没有找到，则返回-1 
}
int main(void)
{
	int x;
	printf("输入要查找的关键字：");
	scanf("%d",&x);
	//int pos=BinarySearch(0,N-1,x);
	int pos;
	printf("原数据表：");
	for(int i=0;i<N;i++)
		printf("%d",a[i]);
	printf("\n\n");
	if(pos>=0)
		printf("查找成功，该关键字位于数组的第%d个元素！\n",pos+1);
	else
		printf("查找失败！\n");
	return 0;	
}
