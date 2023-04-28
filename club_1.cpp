#include<iostream>
using namespace std;
#include<fstream>
#include<string>
#include<sstream>
#include<vector>

struct Member
{
    string name;
    string id;
    int age;
    int point;
    int level;
    Member* nextMember;
};

struct Activity
{
    string name;
    string organizer;
    string date;
    string address;
    string description;
    Activity* nextActivity;
};

struct Club
{
    string name;
    string description;
    string slogan;
    string aim;
    string rule;
    string boss;
    Member* memberList;
    Activity* activityList;
    Club* nextClub;
};


Club* readClubFile(string filePath)
{
    ifstream fi(filePath);
    if (!fi)
    {
        cerr << "Failed to open file: " << filePath << endl;
        return nullptr;
    }

    Club* head = nullptr;
    Club* tail = nullptr;

    string line;
    Club* cur = nullptr;
    while (getline(fi, line))
    {
        // 新的社团信息开始
        if (line.find("club_") != std::string::npos)
        {
            cur = new Club();
            cur->memberList = nullptr;
            cur->activityList = nullptr;

            // 将新创建的结构体插入到链表末尾
            if (tail == nullptr)
            {
                head = cur;
                tail = cur;
            }
            else
            {
                tail->nextClub = cur;
                tail = cur;
            }
        }

        if (cur)
        {
            if (line.find("name: ") != std::string::npos)
            {
                cur->name = line.substr(6);
            }
            else if (line.find("description: ") != std::string::npos)
            {
                cur->description = line.substr(13);
            }
            else if (line.find("slogan: ") != std::string::npos)
            {
                cur->slogan = line.substr(8);
            }
            else if (line.find("aim: ") != std::string::npos)
            {
                cur->aim = line.substr(5);
            }
            else if (line.find("rule: ") != std::string::npos)
            {
                cur->rule = line.substr(6);
            }
            else if (line.find("boss: ") != std::string::npos)
            {
                cur->boss = line.substr(6);
            }
            else if (line.find("members:") != std::string::npos)
            {
                Member* member = new Member();
                member->nextMember = cur->memberList;
                cur->memberList = member;
            }
            else if (line.find("name: ") != std::string::npos)
            {
                cur->memberList->name = line.substr(6);
            }
            else if (line.find("id: ") != std::string::npos)
            {
                cur->memberList->id = line.substr(4);
            }
            else if (line.find("age: ") != std::string::npos)
            {
                cur->memberList->age = stoi(line.substr(5));
            }
            else if (line.find("point: ") != std::string::npos)
            {
                cur->memberList->point = stoi(line.substr(7));
            }
            else if (line.find("level: ") != std::string::npos)
            {
                cur->memberList->level = stoi(line.substr(7));
            }
            else if (line.find("activities:") != std::string::npos)
            {
                Activity* activity = new Activity();
                activity->nextActivity = cur->activityList;
                cur->activityList = activity;
            }
            else if (line.find("name: ") != std::string::npos)
            {
                cur->activityList->name = line.substr(6);
            }
            else if (line.find("description: ") != std::string::npos)
            {
                cur->activityList->description = line.substr(13);
            }
            else if (line.find("date: ") != std::string::npos)
            {
                cur->activityList->date = line.substr(6);
            }
        }
    }

    fi.close();
    return head;
}

int main() {
    Club* head = readClubFile("club.txt");

    // 输出第一个社团的成员信息
    if (head != nullptr) {
        Member* curMember = head->memberList;
        while (curMember != nullptr) {
            std::cout << "Name: " << curMember->name << std::endl;
            std::cout << "ID: " << curMember->id << std::endl;
            std::cout << "Age: " << curMember->age << std::endl;
            std::cout << "Point: " << curMember->point << std::endl;
            std::cout << "Level: " << curMember->level << std::endl;
            std::cout << std::endl;
            curMember = curMember->nextMember;
        }
    }

    return 0;
}
