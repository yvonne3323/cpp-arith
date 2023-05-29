//求出wj002.txt文件里的前1000个数中个位，十位，百位数字的和是奇数的数的个数
//不能用！=，只能用==
#include<stdio.h>
int main()
{
   int x,i,t=0,xb,xs,xg;
   FILE *fp = fopen("wj002.txt", "r");
    if (fp == NULL) {
         printf("Error: Cannot open file %s\n", "wj002.txt");
         return 0;
    }
    else
    {
        for(i=0;i<1000;i++)
        {
            fscanf(fp,"%d",&x);
            xb=x/100;
            xs=x/10%10;
            xg=x%10;
            if((xb+xs+xg)%2==1)
            {
                t++;
            }
        }
        printf("%d",t);
    }
    return 0;
}