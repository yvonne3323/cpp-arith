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
typedef struct member {
    string name;//姓名
    int age;//年龄
    enum Gender gender;//性别
    int point;//积分
    struct member *next;
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

void insertClub(clublist* list, club club) {
    
    clublist newClub = (clublist)malloc(sizeof(club));
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

clublist createClubList(string filename) {
    ifstream infile(filename); // 打开文件
    if (!infile) { // 检查文件是否成功打开
        cerr << "Error: File not found!\n";
        exit(1);
    }

    clublist head = NULL;//头指针
    club currentClub = {};//当前社团
    member currentMember = {};//当前成员
    sponsor currentSponsor = {};//当前赞助商

    for (string line; getline(infile, line); ) 
    {
        
        if (line[0] == 'c') 
        {
            if (head != NULL) 
            {
                insertClub(&head, currentClub);
            }
            currentClub = {};
            string clubName = line.substr(0, line.find(":"));
            currentClub.name = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
            cout << clubName << endl;
            cout << currentClub.name << endl;
        }
        else if (line[0] == ' ') 
        {
            //空格跳过 line
            if (line.empty())
            {
                // 空行，跳过
                continue;
            }
            string clubInfo = line.substr(4,line.find(":")-4);//slogan
            string clubInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
            if (clubInfo == "description") 
            {
                currentClub.description = clubInfoContent;
                cout << currentClub.description << endl;
            }
            else if (clubInfo == "slogan") 
            {
                currentClub.slogan = clubInfoContent;
                cout << currentClub.slogan << endl;
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
                // 解析成员信息
            memberlist newMember = new member();
            for (string line; getline(infile, line) && line[0] == ' '; )
            {
        string memberInfo = line.substr(8, line.find(":") - 8);
        string memberInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
        if (memberInfo == "name")
        {
            newMember->name = memberInfoContent;
        }
        else if (memberInfo == "age")
        {
            newMember->age = stoi(memberInfoContent);
        }
        else if (memberInfo == "gender")
        {
            if (memberInfoContent == "Male")
            {
                newMember->gender = Gender::Male;
            }
            else if (memberInfoContent == "Female")
            {
                newMember->gender = Gender::Female;
            }
            else
            {
                newMember->gender = Gender::Unknown;
            }
        }
        else if (memberInfo == "point")
        {
            newMember->point = stoi(memberInfoContent);
        }
    }
    newMember->next = currentClub.members;
    currentClub.members = newMember;
}
else if (clubInfo == "sponsor")
{
    // 解析赞助商信息
    sponsorlist newSponsor = new sponsor();
    for (string line; getline(infile, line) && line[0] == ' '; )
    {
        string sponsorInfo = line.substr(8, line.find(":") - 8);
        string sponsorInfoContent = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
        if (sponsorInfo == "name")
        {
            newSponsor->name = sponsorInfoContent;
        }
    }
    newSponsor->next = currentClub.sponsors;
    currentClub.sponsors = newSponsor;
}
        }
    }
    insertClub(&head, currentClub);

    infile.close();

    return head;
    
}

int main() {
    clublist list = createClubList("club_1.txt");
    printClubList(list);

    return 0;
}
