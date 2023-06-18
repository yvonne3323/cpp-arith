#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

enum Gender {//枚举 性别
    Male,
    Female,
    Unknown
};

typedef struct member 
{
    string name;//姓名
    int age;//年龄
    enum Gender gender;//性别
    int point;//积分
    int level;//等级
    struct member *next;//
} member, *memberlist;

//赞助商
typedef struct sponsor {
    string name;//姓名
    struct sponsor *next;
} sponsor, *sponsorlist;

//社团
typedef struct club {
    string name;//名称
    string description;//社团性质
    string slogan;//口号
    string aim;//宗旨
    string rule;//章程
    string boss;//发起人
    memberlist members;
    sponsorlist sponsors;
    struct club* next;
} club, *clublist;

//将一行数据转换成club结构体
club* lineToClub(string line, ifstream& infile);

//读取文件中的所有社团数据，并存储到链表中
clublist readClubsFromFile(string filename);


//将社团链表中的数据存储到文件中
void saveClubsToFile(string filename, clublist clubs);