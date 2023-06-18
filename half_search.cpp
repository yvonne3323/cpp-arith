//折半查找
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
typedef struct
{
    int key;
}ElemType;

typedef struct
{
    ElemType *R;
    int length;
}SSTable;

void Create(SSTable *ST)
{
    int i;
    ST->R=(ElemType *)malloc((MAXSIZE+1)*sizeof(ElemType));
    if(!ST->R)
        exit(0);
    ST->length=MAXSIZE;
    printf("请输入%d个数：\n",MAXSIZE);
    for(i=1;i<=ST->length;i++)
        scanf("%d",&ST->R[i].key);
}

int Search_Bin(SSTable ST,int key)//折半查找的关键
{
    int low,high,mid;
    low=1;
    high=ST.length;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key==ST.R[mid].key)
            return mid;
        else if(key<ST.R[mid].key)
            high=mid-1;
        else
            low=mid+1;
    }
    return 0;
}

int main()
{
    SSTable ST;
    int key;
    Create(&ST);
    printf("请输入要查找的数：");
    scanf("%d",&key);
    if(Search_Bin(ST,key))
        printf("查找成功！\n");
    else
        printf("查找失败！\n");
    return 0;
}

