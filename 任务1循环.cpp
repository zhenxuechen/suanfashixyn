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
			return middle;//�պ��ҵ��ؼ��� 
		}
		else if(a[middle]>x)//�ȹؼ��ִ���ؼ����������� 
		{
			return middle-1;
		}
		else //�ȹؼ���С��ؼ����������� 
		{
			return middle+1;
		}
	}
	return -1;//�����Ȼû���ҵ����򷵻�-1 
}
int main(void)
{
	int x;
	printf("����Ҫ���ҵĹؼ��֣�");
	scanf("%d",&x);
	//int pos=BinarySearch(0,N-1,x);
	int pos;
	printf("ԭ���ݱ�");
	for(int i=0;i<N;i++)
		printf("%d",a[i]);
	printf("\n\n");
	if(pos>=0)
		printf("���ҳɹ����ùؼ���λ������ĵ�%d��Ԫ�أ�\n",pos+1);
	else
		printf("����ʧ�ܣ�\n");
	return 0;	
}
