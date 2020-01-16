#include <stdio.h>
void QuickSort(int *, int, int); /*现在只需要定义一个函数, 不用交换还省了一个函数, 减少了代码量*/ 
int main(void)
{
    int i; //循环变量
    int a[] = {900, 2, -58, 3, 34, 5, 76, 7, 32, 4, 43, 9, 1, 56, 8,-70, 635, -234, 532, 543, 2500};
    QuickSort(a, 0, 20); /*引用起来很简单, 0为第一个元素的下标, 20为最后一个元素的下标*/
    printf("最终排序结果为:\n");
    
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
    if (low >= high) //如果low >= high说明排序结束了
    {
        return ;
    }
    while (low < high) //该while循环结束一次表示比较了一轮
    {
        while (low < high && key <= a[high])
        {
            --high; //向前寻找
        }
        if (key > a[high])
        {
            a[low] = a[high]; //直接赋值, 不用交换
            ++low;
        }
        while (low < high && key >= a[low])
        {
            ++low; //向后寻找
        }
        if (key < a[low])
        {
            a[high] = a[low]; //直接赋值, 不用交换
            --high;
        }
    }
    a[low] = key; //查找完一轮后key值归位, 不用比较一次就互换一次。此时key值将序列分成左右两部分
    QuickSort(a, i, low-1); //用同样的方式对分出来的左边的部分进行同上的做法
    QuickSort(a, low+1, j); //用同样的方式对分出来的右边的部分进行同上的做法
}
