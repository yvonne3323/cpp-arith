//实现冒泡排序

#include <iostream>
using namespace std;


void maopao(int a[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) { // 交换两数位置
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }

    }
}

int main() 
{
    //输入数据
    int n;
    cout << "请输入要排序的数的个数：";
    cin >> n;
    int a[n];
    cout << "请输入要排序的数：";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //排序
    maopao(a, n);
    //输出结果
    cout << "排序后的结果为：";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
