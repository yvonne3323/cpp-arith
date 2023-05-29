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

void insertMember(memberlist* list, member member) 
{
    memberlist newMember = (memberlist)malloc(sizeof(member));
    *newMember = member;
    newMember->next = *list;
    *list = newMember;
}

void insertSponsor(sponsorlist* list, sponsor sponsor)
{
    sponsorlist newSponsor = (sponsorlist)malloc(sizeof(sponsor));
    *newSponsor = sponsor;
    newSponsor->next = *list;
    *list = newSponsor;
}

void insertClub(clublist* list, club club) 
{
    clublist newClub = (clublist)malloc(sizeof(club));//分配内存
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

//解析社团成员信息
// club parseClubInfo(ifstream& infile, club currentClub) {
//     string line;
//     while (getline(infile, line)) 
//     {
//         if (line.empty()) 
//         {
//             // 空行，终止循环
//             break;
//         }
//         memberlist newMember = new member();
//         for (; line[0] == ' '; getline(infile, line)) {
//             string memberInfo = line.substr(8, line.find(":") - 8);
//             string memberInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
//             if (memberInfo == "name") {
//                 newMember->name = memberInfoContent;
//             }
//             else if (memberInfo == "age") {
//                 newMember->age = stoi(memberInfoContent);
//             }
//             else if (memberInfo == "gender") {
//                 if (memberInfoContent == "Male") {
//                     newMember->gender = Gender::Male;
//                 }
//                 else if (memberInfoContent == "Female") {
//                     newMember->gender = Gender::Female;
//                 }
//                 else {
//                     newMember->gender = Gender::Unknown;
//                 }
//             }
//             else if (memberInfo == "point") {
//                 newMember->point = stoi(memberInfoContent);
//             }
//         }
//         newMember->next = currentClub.members;
//         currentClub.members = newMember;
//     }
//     return currentClub;
// }

//解析社团member和sponsor信息
club parseClubInfo2(ifstream& infile, club currentClub) {
    string line;
    while (getline(infile, line)) 
    {
        if (line.empty()) 
        {
            // 空行，终止循环
            continue;
        }
        
        if (line!="sponsor:") 
        {
            // 读取 member 信息
            memberlist newMember = new member();
            while (getline(infile, line) && !line.empty())
            {
                string memberInfo = line.substr(8, line.find(":")-8);
                string memberInfoContent = line.substr(line.find(":") + 1);
                if (memberInfo == "name") {
                    newMember->name = memberInfoContent;
                }
                else if (memberInfo == "age") {
                    newMember->age = stoi(memberInfoContent);
                }
                else if (memberInfo == "gender") {
                    if (memberInfoContent == "Male") {
                        newMember->gender = Gender::Male;
                    }
                    else if (memberInfoContent == "Female") {
                        newMember->gender = Gender::Female;
                    }
                    else {
                        newMember->gender = Gender::Unknown;
                    }
                }
                else if (memberInfo == "point") {
                    newMember->point = stoi(memberInfoContent);
                }
            }
            newMember->next = currentClub.members;
            currentClub.members = newMember;
        }
        else if (line == "sponsor:") 
        {
            // 读取 sponsor 信息
            sponsorlist newSponsor = new sponsor();
            while (getline(infile, line) && !line.empty()) 
            {
                string sponsorInfo = line.substr(0, line.find(":"));
                string sponsorInfoContent = line.substr(line.find(":") + 1);
                if (sponsorInfo == "name") {
                    newSponsor->name = sponsorInfoContent;
                }

            }
            newSponsor->next = currentClub.sponsors;
            currentClub.sponsors = newSponsor;
        }

    }
    return currentClub;
}


//解析社团赞助商信息
// club parseClubSponsor(ifstream& infile, club currentClub) {
//     string line;
//     while (getline(infile, line)) {
//         if (line.empty()) {
//             // 空行，终止循环
//             break;
//         }
//         sponsorlist newSponsor = new sponsor();
//         for (; line[0] == ' '; getline(infile, line)) {
//             string sponsorInfo = line.substr(8, line.find(":") - 8);
//             string sponsorInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
//             if (sponsorInfo == "name") {
//                 newSponsor->name = sponsorInfoContent;
//             }
//         }
//         newSponsor->next = currentClub.sponsors;
//         currentClub.sponsors = newSponsor;
//     }
//     return currentClub;
// }


//解析社团信息
void parseClubInfo1(string clubInfo, string clubInfoContent, club& currentClub, ifstream& infile)
{
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
    else if(clubInfo == "member")
    {
        currentClub = parseClubInfo2(infile, currentClub);
    }


}



    // else if (clubInfo == "member")
    // {
    //     currentClub = parseClubInfo(infile, currentClub);
    // }
    // else if (clubInfo == "sponsor")
    // {
                // 解析赞助商信息
                // 解析赞助商信息


//     sponsorlist newSponsor = new sponsor();
//     for (string line; getline(infile, line) && line[0] == ' '; )
//     {
//         string sponsorInfo = line.substr(8, line.find(":") - 8);
//         string sponsorInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
//         if (sponsorInfo == "name")
//         {
//             newSponsor->name = sponsorInfoContent;
        
    
//     newSponsor->next = currentClub.sponsors;
//     currentClub.sponsors = newSponsor;
// }
//     }
//                 currentClub = parseClubSponsor(infile, currentClub);
//             }
// }


//解析整体社团信息
clublist createClubList(string filename) 
{
    ifstream infile(filename); // 打开文件
    //通过 filename 参数打开一个输入文件流 infile，ifstream 是 C++ 标准库提供的输入文件流类，可以用来从文件中读取数据。
    //在使用 ifstream 时，需要包含头文件 <fstream>。
    if (!infile) 
    { // 检查文件是否成功打开
        cerr << "Error: File not found!\n";
        exit(1);
    }

    clublist head = NULL;//头指针
    club currentClub = {};//当前社团
    member currentMember = {};//当前成员
    sponsor currentSponsor = {};//当前赞助商
    currentClub.members = NULL;
    currentClub.sponsors = NULL;


    for (string line; getline(infile, line); ) // 逐行读取文件
    {
        
        if (line[0] == 'c') 
        {
            if (head != NULL) // 如果不是第一个社团，插入链表
            {
                insertClub(&head, currentClub);
            }
            currentClub = {};
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
            parseClubInfo1(clubInfo, clubInfoContent, currentClub, infile);//解析社团信息

        }

    }
    insertClub(&head, currentClub);
    return head;

}

int main() {
    clublist list = createClubList("club_1.txt");
    printClubList(list);
//已完成社团和成员工作，接下来是赞助商，赞助商还未完成，仍然有问题
    return 0;
}
