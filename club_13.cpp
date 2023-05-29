//定结构体(已知)
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>

using namespace std;

enum Gender {//枚举 性别
    Male,
    Female,
    Unknown
};

//成员
typedef struct member 
{
    string name;//姓名
    int age;//年龄
    enum Gender gender;//性别
    int point;//积分
    //应该缺一个等级，待定
    struct member *next;//
} member, *memberlist;
//基础知识点
//member aMember;  // 定义一个 member 类型的结构体变量 aMember
//memberlist pMember;  // 定义一个指向 member 类型结构体的指针变量

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

// 成员链表初始化
memberlist member_init()
{
    memberlist head = new member;
    head->next = NULL;
    return head;
}

// 赞助商链表初始化
sponsorlist sponsor_init()
{
    sponsorlist head = new sponsor;
    head->next = NULL;
    return head;
}

// 社团链表初始化
clublist club_init()
{
    clublist head = new club;
    head->next = NULL;
    return head;
}

//插入成员
void insertMember(memberlist* list, member member) 
{
    memberlist newMember = (memberlist)malloc(sizeof(member));
    *newMember = member;
    newMember->next = *list;
    *list = newMember;
}

//插入赞助商
void insertSponsor(sponsorlist* list, sponsor sponsor)
{
    sponsorlist newSponsor = (sponsorlist)malloc(sizeof(sponsor));
    *newSponsor = sponsor;
    newSponsor->next = *list;
    *list = newSponsor;
}

//插入社团
void insertClub(clublist* list, club club) 
{
    clublist newClub = (clublist)malloc(sizeof(club));
    *newClub = club;
    newClub->next = *list;
    *list = newClub;
}


void printClubList(clublist list) {
    while (list) {
        cout << "Club name: " << list->name << endl;
        cout << "Description: " << list->description << endl;
        cout << "Slogan: " << list->slogan << endl;
        cout << "Aim: " << list->aim << endl;
        cout << "Rule: " << list->rule << endl;
        cout << "Boss: " << list->boss << endl;
        cout << "Members: " << endl;
        memberlist memberList = list->members;
        while (memberList) {
            cout << "Name: " << memberList->name << ", Age: " << memberList->age << ", Gender: " << memberList->gender << ", Point: " << memberList->point << endl;
            memberList = memberList->next;
        }
        cout << "Sponsors: " << endl;
        sponsorlist sponsorList = list->sponsors;
        while (sponsorList) {
            cout << "Name: " << sponsorList->name << endl;
            sponsorList = sponsorList->next;
        }
        cout << endl;
        list = list->next;
    }
}


clublist createClubList(string filename) 
{
    ifstream infile(filename); // 打开文件
    
    if (!infile) 
    { // 检查文件是否成功打开
        cerr << "Error: File not found!\n";
        exit(1);
    }
    //循环读取每个社团数据
    while(1)
    {
        //跳出
        if(infile.eof())//判断是否到文件尾
        {
            break;
        }
        //创建新的社团结点
        clublist currentClub = club_init();
        //循环读取社团信息
         for (string line; getline(infile, line); )
         {
            string clubName = line.substr(0, line.find(":"));
            currentClub.name = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
         }

    }
}