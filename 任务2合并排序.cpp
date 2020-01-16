#include<iostream>
using namespace std;
void MergeSort(int a[], int left, int right);
void Merge(int c[], int d[], int n, int m, int r);//�ϲ������������ݼ� 
void copy(int a[], int b[], int l, int r);//�������źõ����� 

int main()
{
	int array[14] = { 1,4,2,3,9,11,10,7,95,64,100,151,121,113 };	
	cout << "��ʼʱ��array���Ԫ��˳���ǣ�" << endl;
	for (int i = 0; i < 14; i++)
	{
		cout << array[i] << "��";
	}
	cout << endl;
	MergeSort(array, 0, 13);
	cout << "�����array���Ԫ��˳���ǣ�" << endl;
	for (int i = 0; i < 14; i++)
	{
		cout << array[i] << "��";
	}
	cout << endl;
	return 0;
}

//�ϲ�c[n:m]��c[m+1:r]��d[n:r]
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
		MergeSort(a, left, i);//�������� 
		MergeSort(a, i + 1, right);
		Merge(a, b, left, i, right);//�ϲ�������b
		copy(a, b, left, right);//���ƻ�����a
	}
}
