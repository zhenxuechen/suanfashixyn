#include<iostream>
#include<cstring>
#define XLEN 12
#define YLEN 7
using namespace std;

int c[XLEN + 1][YLEN + 1];//Xi Yj������������еĳ��� ���1��������ų���Ϊ0�����
int s[XLEN + 1][YLEN + 1];//c[i][j]��ֵ������һ��������Ľ�õ���

void lcsLength(string x, string y)
{

	for (int i = 0; i <= XLEN; i++) c[i][0] = 0;
	for (int i = 0; i <= YLEN; i++) c[0][i] = 0;
	for (int i = 1; i <= XLEN; i++)		//xi�ĳ���
	{
		for (int j = 1; j <= YLEN; j++)	//yj�ĳ���
		{
			if (x[i - 1] == y[j - 1])	//x y���� ���һ��Ԫ�����
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				s[i][j] = 1;
			}
			else						//x y���� ���һ��Ԫ�ز����
			{
				if (c[i - 1][j] >= c[i][j - 1])	//xȥ�������������һ��Ԫ�ظ���
				{
					c[i][j] = c[i - 1][j];
					s[i][j] = 2;
				}
				else							//yȥ�������������һ��Ԫ�ظ���
				{
					c[i][j] = c[i][j - 1];
					s[i][j] = 3;
				}
			}
		}
	}
}
void lcs(int i, int j, string x)
{
	if (i == 0 || j == 0)
		return;
	if (s[i][j] == 1) //x[i] == y[j]
	{
		lcs(i - 1, j - 1, x);
		cout << x[i - 1];
	}
	else if (s[i][j] == 2)//c[i - 1][j] >= c[i][j - 1]
	{
		lcs(i - 1, j, x);
	}
	else lcs(i, j - 1, x);//c[i - 1][j] < c[i][j - 1]
}

int main()
{
	string x = "ASAFAGAHAJAK";
	string y = "ASAAAAA";

	lcsLength(x, y);

	lcs(XLEN, YLEN, x);

	cout << endl;
	system("pause");
}
