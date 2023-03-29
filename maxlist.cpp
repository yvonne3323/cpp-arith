//给定n个整数的序列，求出子序列的最大和。
//例如，给定序列{ -2, 11, -4, 13, -5, -2 }，其最大子序列和为20，对应的子序列为{ 11, -4, 13 }。
#include <iostream>
using namespace std;

//算法一：o(n^3)
//1-1+2-1+2+3-...+2-2+3-...+n
int maxSubSum1(int a[], int n)
{
    int maxSum = 0;
    for (int i = 0; i < n; i++)//i是子序列的起始位置
    {
        for (int j = i; j < n; j++)//j是子序列的结束位置
        {
            int thisSum = 0;//thisSum是从a[i]到a[j]的子序列的和
            for (int k = i; k <= j; k++)
                thisSum += a[k];
            if (thisSum > maxSum)//如果thisSum大于maxSum，则更新maxSum
                maxSum = thisSum;
        }//for j
    }//for i
    return maxSum;
}

//算法二：o(n^2)
int maxSubSum2(int a[], int n)
{
    int maxSum = 0;
    for (int i = 0; i < n; i++)//i是子序列的起始位置
    {
        int thisSum = 0;//thisSum是从a[i]到a[j]的子序列的和
        for (int j = i; j < n; j++)//j是子序列的结束位置
        {
            thisSum += a[j];//对于相同的i，不同的j，只要在j-1次循环的基础上加上a[j]即可
            if (thisSum > maxSum)//如果thisSum大于maxSum，则更新maxSum
                maxSum = thisSum;
        }//for j
    }//for i
    return maxSum;
}

//算法三：o(nlogn)——分治法

int max3(int a, int b, int c)
{//返回三个整数中的最大值
    return a > b ? a > c ? a : c : b > c ? b : c;
}

int DivideAndConquer (int a[], int left, int right)
{
    if (left == right)//递归的终止条件，子序列只有一个数字
        if (a[left] > 0)
            return a[left];
        else
            return 0;
    int center = (left + right) / 2;//将子序列平分
    int maxLeftSum = DivideAndConquer (a, left, center);//递归求得左边子序列的最大和
    int maxRightSum = DivideAndConquer (a, center + 1, right);//递归求得右边子序列的最大和
    int maxLeftBorderSum = 0, leftBorderSum = 0;
    for (int i = center; i >= left; i--)//从中线向左扫描
    {
        leftBorderSum += a[i];
        if (leftBorderSum > maxLeftBorderSum)
            maxLeftBorderSum = leftBorderSum;
    }
    int maxRightBorderSum = 0, rightBorderSum = 0;
    for (int i = center + 1; i <= right; i++)//从中线向右扫描
    {
        rightBorderSum += a[i];
        if (rightBorderSum > maxRightBorderSum)
            maxRightBorderSum = rightBorderSum;
    }
    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}

//若要保持相同的接口，可以这样写
int MaxSubseqSum3 (int a[], int n)
{
    return DivideAndConquer (a, 0, n - 1);
}

//算法四：o(n)
int maxSubSum4(const int a[], int n)
{
    int maxSum = 0, thisSum = 0;
    for (int i = 0; i < n; i++)
    {
        thisSum += a[i];
        if (thisSum > maxSum)
            maxSum = thisSum;
        else if (thisSum < 0)
            thisSum = 0;
    }
    return maxSum;
}

//不仅输出最大和，而且输出的那个子序列的首尾
int MaximumSubsequenceSum(int a[], int n)
{
    int maxSum = 0, thisSum = 0;
    int start = 0, end = 0, temp = 0;
    for (int i = 0; i < n; i++)
    {
        thisSum += a[i];
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
            start = temp;
            end = i;
        }
        else if (thisSum < 0)
        {
            thisSum = 0;
            temp = i + 1;
        }
    }
    cout << "start = " << start << " end = " << end << endl;//要具体数字自己加角标
    return maxSum;
}

int main()
{
    int a[] = { -2, 11, -4, 13, -5, -2 };
    int n = sizeof(a) / sizeof(int);
    cout << "maxSubSum1 = " << maxSubSum1(a, n) << endl;
    cout << "maxSubSum2 = " << maxSubSum2(a, n) << endl;
    cout << "maxSubSum3 = " << MaxSubseqSum3(a, n) << endl;
    cout << "maxSubSum4 = " << maxSubSum4(a, n) << endl;

    cout << MaximumSubsequenceSum(a, n) << endl;
    return 0;
}