#include<iostream>
using namespace std;
void MergeSort(int a[], int left, int right);
void Merge(int c[], int d[], int n, int m, int r);//合并两个有序数据集 
void copy(int a[], int b[], int l, int r);//拷贝已排好的数据 

int main()
{
	int array[14] = { 1,4,2,3,9,11,10,7,95,64,100,151,121,113 };	
	cout << "初始时，array里的元素顺序是：" << endl;
	for (int i = 0; i < 14; i++)
	{
		cout << array[i] << "，";
	}
	cout << endl;
	MergeSort(array, 0, 13);
	cout << "排序后，array里的元素顺序是：" << endl;
	for (int i = 0; i < 14; i++)
	{
		cout << array[i] << "，";
	}
	cout << endl;
	return 0;
}

//合并c[n:m]和c[m+1:r]到d[n:r]
void Merge(int c[], int d[], int n, int m, int r)
{
	int i = n, j = m + 1, k = n;
	while ((i <= m) && (j <= r))
	{
		if (c[i] <= c[j])
			d[k++] = c[i++];
		else
			d[k++] = c[j++];
	}
	if (i > m)
	{
		for (int q = j; q <= r; q++)
		d[k++] = c[q];
	}
	else
	{
		for (int q = i; q <= m; q++)
		d[k++] = c[q];
	}	
}

void copy(int a[], int b[], int l, int r)
{
	for (int i = l; i <= r; i++)
	{
		a[i] = b[i];
	}
}

void MergeSort(int a[], int left, int right)
{
	int b[200];
	if (left < right)
	{
		int i = (left + right)/2;
		MergeSort(a, left, i);//数据排序 
		MergeSort(a, i + 1, right);
		Merge(a, b, left, i, right);//合并到数组b
		copy(a, b, left, right);//复制回数组a
	}
}
