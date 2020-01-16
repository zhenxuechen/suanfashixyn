#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

#define MAX_VALUE 20
#define random() rand()%MAX_VALUE
#define N 20
int a[N];
//��������
//int a[N] = {0,5,1,4,4,4,4,3,2};
//int a[N] = {5,5,5,5,5,5,5,5,5};

class Find {
public:
	void bubble(int first, int end) //ð������
	{
		for (int flag = first; flag < end; flag++)
		{
			for (int i = end; i > flag; i--)
			{
				if (a[i] < a[i - 1])
				{
					int t = a[i];
					a[i] = a[i - 1];
					a[i - 1] = t;
				}
			}
		}
	}

	//��ȡ��С��k����
	//����a�д�a[p]��a[r]��Ԫ�ذ���x����,���ڻ��ߵ���x�����ұ�,С��x�������
	int partitionModify(int p, int r, int x) 
	{
		int i, j;

		for (i = p, j = r; i < j; i++)
		{
			if (a[i] >= x)
			{
				while (i < j && a[j] >= x) {
					j--;
				}

				if (i != j) {
					int t = a[i];
					a[i] = a[j];
					a[j] = t;
					j--;
				}
				else
				{
					break;
				}
			}
		}
		
/*�����ѭ��������Ϊ�������
	1 i > j ��ʱ�ض��� a[i] >= x������ a[j+1] = a[i] < x �� a[j+1] >= x ì�� ,������Ǳ߽磬����if���
	2 i = j ��ʱ��� a[i] < x ��a[i+1] = a[j+1] >x ���� i
	3 ��i==p,��ʱֱ�ӷ��ر߽�Ԫ���±�
	4 ��i == r,��ʱΪ�ұ߽磬��ʱa[i]�϶�Ϊx������i - 1��Ҳ��r - 1
	*/
		if (a[i] >= x && i > p)
		{
			return i - 1;
		}
		return i;
	}

	//��r-p+1�����ݰ����Ԫ�ط�Ϊһ�飬�ֱ��ҳ��������λ����
	//�ٽ��������λ�������鿪ͷ�����������˳�����ν���������Щ�������λ��
	//��ͬ���ķ������������λ�������ó��������������λ����������λ���Ϳ��Խ����ݰ�������λ���ıȽ�
	//������
	int selectModify(int p, int r, int k) //Ѱ����λ��
	{
		int i;

		if (r - p + 1 <= 5)
		{
			bubble(p, r);
			return a[p + k - 1];
		}

		//��r-p+1�����ݰ����Ԫ�ط�Ϊһ�飬���Է�Ϊ(r - p + 1) / 5��
		//�ֱ��ҳ��������λ�����ٽ��������λ�������鿪ͷ�����ݰ����˳�����ν���
		for (i = 0; i < (r - p + 1) / 5; i++)
		{
			int s = p + 5 * i, t = s + 4;
			bubble(s, t);
			int temp = a[p + i];
			a[p + i] = a[s + 2];
			a[s + 2] = temp;
		}

		//����Щ�������λ��
		//��ͬ���ķ������������λ�������ó��������������λ�� x
		int x = selectModify(p, p + (r - p + 1) / 5 - 1, (r - p + 6) / 10);

		i = partitionModify(p, r, x);
		int j = i - p + 1;

		if (k <= j) {
			return selectModify(p, i, k);
		}
		else {
			return selectModify(i + 1, r, k - j);
		}
	}
}; 

int main()
{
    clock_t start,end;
    double elapsed;
     srand((int)time(NULL));
     for (int k = 0; k < N; k++)
     {
	      a[k] = random();
          cout << a[k] << " ";
    }
 	cout << endl;
    start=clock();
	Find f;
	int n = 4;
	cout << "The No." << n << " is :" << f.selectModify(0, N - 1, n) << endl;
	end=clock();
	elapsed=((double)(end-start));
	//CLOCKS_PER_SEC;
	cout<<"Time: "<<elapsed<<endl;
	cout << "��С��" << n << "��Ԫ��Ϊ��" << endl;

	for (int k = 0; k < n; k++)
	{
		cout << a[k] << " ";
	}

	return 0;
}
