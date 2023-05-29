//目标：文件变成链表
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


void insertMember(memberlist* list, member member);
void insertSponsor(sponsorlist* list, sponsor sponsor);
void insertClub(clublist* list, club club);
void printClubList(clublist list);

clublist createClubList(string filename)
{
    //string filename = "club_1.txt"; // 文件名
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
            if (head != NULL) {
                insertClub(&head, currentClub);
            }
            currentClub = {};
            string clubName = line.substr(0, 8);//
            currentClub.name = line.substr(9, line.length() - 9);//
            //另一种方法，分割为两部分，后一部分放入信息
            // string clubName = line.substr(0, line.find(":"));
            // currentClub.name = line.substr(line.find(":") + 1, line.length() - line.find(":") - 1);
            

        }
        else if (line[0] == ' ') {
            istringstream iss(line);
            string key, value;
            iss >> key >> value;
            if (key == "description:") {
                currentClub.description = value;
            }
            else if (key == "slogan:") {
                currentClub.slogan = value;
            }
            else if (key == "aim:") {
                currentClub.aim = value;
            }
            else if (key == "rule:") {
                currentClub.rule = value;
            }
            else if (key == "boss:") {
                currentClub.boss = value;
            }
            else if (key == "name:") {
                currentMember.name = value;
            }

            else if (key == "age:") {
                currentMember.age = stoi(value);
            }
            else if (key == "point:") {
                currentMember.point = stoi(value);
            }
            // else if (key == "level:") {
            //     currentMember.level = stoi(value);
            //     insertMember(&(currentClub.members), currentMember);
            //     currentMember = {};
            // }
            else if (key == "sponsor:") {
                currentSponsor.name = value;
                insertSponsor(&(currentClub.sponsors), currentSponsor);
                currentSponsor = {};
            }

        }
    }

    insertClub(&head, currentClub);

    infile.close();

    return head;

    return 0;
}

int main()
{
    clublist list = createClubList("club_1.txt");
    printClubList(list);

    return 0;
}