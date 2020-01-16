#include<stdio.h>
int main()
{
   int g,i,k,s,a[10];
   long m1,m2,m3;
   printf("桥本分数式有:\n");
   i=1;
   a[1]=1;// 数组元素赋初值取1 
   s=0;
   while(1)
   {
      g=1;
      for(k=i-1;k>=1;k--)
         if(a[i]==a[k])
         {
            g=0;           /*两数相同,标记g=0*/
            break;
         }
      if(i==9 && g==1 && a[1]<a[4])
      {
         m1=a[2]*10+a[3];
         m2=a[5]*10+a[6];
         m3=a[8]*10+a[9];
         if(a[1]*m2*m3+a[4]*m1*m2==a[7]*m1*m2)
         {
            s++;
            printf("(%2d)",s);
            printf("%d/%d+%d/",a[1],m1,a[4]);
            printf("%ld=%d/%ld  ",m2,a[7],m3);
            if(s%2==0)
               printf("\n");
         }
      }
      if(i<9 && g==1)
      {
         i++;
         a[i]=1; // 取值点：各元素从1开始赋值继续 
         continue;          /*不到9个数,往后继续*/
      }
      while(a[i]==9 && i>1)  // a[i]=9就是回溯点，各元素取值至9后回溯 
         i--;               /*往前回溯*/
      if(a[i]==9 && i==1)
         break;
      else
         a[i]++;            /*至第1个数为9结束*/
   }
   printf("共以上%d个解\n",s);
} 
