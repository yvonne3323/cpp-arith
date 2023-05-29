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

    //初始化
    clublist head = NULL;
    club currentClub = {};


    for (string line; getline(infile, line); ) // 逐行读取文件
    {
        
        if (line[0] == 'c') 
        {
            //新建社团
            if (head == NULL) 
            {
                head = club_init();
            }
            else 
            {
                insertClub(&head, currentClub);
            }

            string clubName = line.substr(0, line.find(":"));
            currentClub.name = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
            cout << currentClub.name << endl;
        }
        else if (line[0] == ' ') 
        {
            //空格跳过 line
            if (line.empty())
            {
                continue;
            }
            string clubInfo = line.substr(4,line.find(":")-4);//substr()函数用于返回字符串的子串
            string clubInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
            if (clubInfo == "description") 
    {
        currentClub.description = clubInfoContent;
    }
    else if (clubInfo == "slogan") 
    {
        currentClub.slogan = clubInfoContent;
    }
    else if (clubInfo == "aim") 
    {
        currentClub.aim = clubInfoContent;
    }
    else if (clubInfo == "rule") 
    {
        currentClub.rule = clubInfoContent;
    }
    else if (clubInfo == "boss") 
    {
        currentClub.boss = clubInfoContent;
        
    }
    else if (clubInfo == "member")
{
    memberlist currentMember = nullptr;
    while (getline(infile, line) && line!="    sponsor:")
    {
        if(line.empty())//空格
        {
            continue;
        }
        
        
        if (line.substr(8, 5) == "name:")
        {
            memberlist newMember = new member();
            newMember->next = nullptr;

            string memberInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
            cout << memberInfoContent << endl;
            newMember->name = memberInfoContent;

            getline(infile, line);
            memberInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
            newMember->age = stoi(memberInfoContent);

            getline(infile, line);
            memberInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
            if (memberInfoContent == "Male") {
                newMember->gender = Gender::Male;
            }
            else if (memberInfoContent == "Female") {
                newMember->gender = Gender::Female;
            }
            else {
                newMember->gender = Gender::Unknown;
            }

            getline(infile, line);
            memberInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
            newMember->point = stoi(memberInfoContent);

            if (currentMember == nullptr) {
                currentClub.members = newMember;
                currentMember = newMember;
            }
            else {
                currentMember->next = newMember;
                currentMember = newMember;
            }
        }

    }
    sponsorlist currentSponsor = nullptr;
    while (getline(infile, line))
    {
        if (line.empty())
        {
            break;
        }

        if (line.substr(8, 5) == "name:")
        {
            sponsorlist newSponsor = new sponsor();
            newSponsor->next = nullptr;

            string sponsorInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
            cout << sponsorInfoContent << endl;
            newSponsor->name = sponsorInfoContent;

            if (currentSponsor == nullptr) {
                currentClub.sponsors = newSponsor;
                currentSponsor = newSponsor;
            }
            else {
                currentSponsor->next = newSponsor;
                currentSponsor = newSponsor;
            }
        }
    }
insertClub(&head, currentClub);
}

    }

    }


    infile.close();

    return head;

 }

int main() 
{
    clublist list = createClubList("club_1.txt");
    printClubList(list);
    return 0;
}