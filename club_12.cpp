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


void insertMember(memberlist* list, member member);
void insertSponsor(sponsorlist* list, sponsor sponsor);
void insertClub(clublist* list, club club);
club parseClubInfo(ifstream& infile, club currentClub);
club parseClubInfo2(ifstream& infile, club currentClub);
void printClubList(clublist list);
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
    head->members = member_init();
    head->sponsors = sponsor_init();
    head->next = NULL;
    return head;
}

int main()
{
    ifstream infile(""); // 打开文件
    
    if (!infile) // 检查文件是否成功打开
    { 
        cerr << "Error: File not found!\n";
        exit(1);
    }
    
    //所有链表初始化
    clublist clubList = club_init();
    club currentClub = *clubList;
    memberlist memberList = member_init();
    member currentMember = *memberList;
    sponsorlist sponsorList = sponsor_init();
    sponsor currentSponsor = *sponsorList;

    // 读取文件
    while (infile)
    {
        string line;
        getline(infile, line);
        if (line == "")
        {
            continue;
        }
        else if (line[0] == 'c') 
        {
            if(head == NULL)//如果是第一个社团
            {
                head = (clublist)malloc(sizeof(club));
                *head = currentClub;

                head->next = NULL;
            }
            else//如果不是第一个社团
            {
                insertClub(&head, currentClub);
            }
            
            insertClub(&clubList, currentClub);
        }
        else if (line == "成员")
        {
            currentMember = parseClubInfo2(infile, currentMember);
            insertMember(&memberList, currentMember);
        }
        else if (line == "赞助商")
        {
            currentSponsor = parseClubInfo2(infile, currentSponsor);
            insertSponsor(&sponsorList, currentSponsor);
        }
    }


















    return 0;
}
