#include <stdio.h>
void QuickSort(int *, int, int); /*����ֻ��Ҫ����һ������, ���ý�����ʡ��һ������, �����˴�����*/ 
int main(void)
{
    int i; //ѭ������
    int a[] = {900, 2, -58, 3, 34, 5, 76, 7, 32, 4, 43, 9, 1, 56, 8,-70, 635, -234, 532, 543, 2500};
    QuickSort(a, 0, 20); /*���������ܼ�, 0Ϊ��һ��Ԫ�ص��±�, 20Ϊ���һ��Ԫ�ص��±�*/
    printf("����������Ϊ:\n");
    
    for (i=0; i<21; ++i)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}

void QuickSort(int *a, int low, int high)
{
    int i = low;
    int j = high;
    int key = a[low];
    if (low >= high) //���low >= high˵�����������
    {
        return ;
    }
    while (low < high) //��whileѭ������һ�α�ʾ�Ƚ���һ��
    {
        while (low < high && key <= a[high])
        {
            --high; //��ǰѰ��
        }
        if (key > a[high])
        {
            a[low] = a[high]; //ֱ�Ӹ�ֵ, ���ý���
            ++low;
        }
        while (low < high && key >= a[low])
        {
            ++low; //���Ѱ��
        }
        if (key < a[low])
        {
            a[high] = a[low]; //ֱ�Ӹ�ֵ, ���ý���
            --high;
        }
    }
    a[low] = key; //������һ�ֺ�keyֵ��λ, ���ñȽ�һ�ξͻ���һ�Ρ���ʱkeyֵ�����зֳ�����������
    QuickSort(a, i, low-1); //��ͬ���ķ�ʽ�Էֳ�������ߵĲ��ֽ���ͬ�ϵ�����
    QuickSort(a, low+1, j); //��ͬ���ķ�ʽ�Էֳ������ұߵĲ��ֽ���ͬ�ϵ�����
}
