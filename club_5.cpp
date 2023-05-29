#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
    string filename = "test.txt"; // 文件名
    ifstream infile(filename); // 打开文件
    if (!infile) { // 检查文件是否成功打开
        cerr << "Error: File not found!\n";
        exit(1);
    }
    // 文件已经成功打开，可以进行其他操作
    cout << "File opened successfully!\n";
    infile.close(); // 关闭文件
    return 0;
}
