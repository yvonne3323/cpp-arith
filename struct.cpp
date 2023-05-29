#include<iostream>
#include<string>
using namespace std;

struct Stu
{
    int age;
    string name;
}stu;

int main()
{
    stu={.age=10,.name="zfq"};//顺序不能反
    cout<<stu.name<<endl;
    return 0;
}