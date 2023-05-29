//可运行
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;

enum Gender {//枚举 性别
    Male,
    Female,
    Unknown
};

typedef struct member {
    string name;
    int age;
    enum Gender gender;//性别
    int point;
    //int level;
    struct member* next;
} member, *memberlist;

typedef struct sponsor {
    string name;
    //string description;
    //string date;
    struct sponsor* next;
} sponsor, *sponsorlist;

typedef struct club {
    string name;
    string description;
    string slogan;
    string aim;
    string rule;
    string boss;
    memberlist members;
    sponsorlist sponsors;
    struct club* next;
} club, *clublist;

clublist createClubList(string filename);
void insertMember(memberlist* list, member member);
void insertsponsor(sponsorlist* list, sponsor sponsor);
void insertClub(clublist* list, club club);
void printClubList(clublist list);

int main() {
    clublist list = createClubList("club_1.txt");
    printClubList(list);

    return 0;
}

clublist createClubList(string filename)
{
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: File not found!\n";
        exit(1);
    }

    clublist head = NULL;
    club currentClub = {};
    member currentMember = {};
    sponsor currentsponsor = {};

    for (string line; getline(infile, line); ) {
        if (line[0] == 'c') //
        {
            if (head != NULL) {
                insertClub(&head, currentClub);
            }
            currentClub = {};
            string clubName = line.substr(0, 8);
            currentClub.name = line.substr(9, line.length() - 9);
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
            else if (key == "name:") {
                currentsponsor.name = value;
            }
        }
    }

    insertClub(&head, currentClub);

    infile.close();

    return head;
}

void insertMember(memberlist* list, member member) {
    memberlist newMember = (memberlist)malloc(sizeof(member));
    newMember->name = member.name;
    newMember->age = member.age;
    newMember->point = member.point;
    //newMember->level = member.level;
    newMember->next = NULL;

    if (*list == NULL) {
        *list = newMember;
    }
    else {
        memberlist current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newMember;
    }
}

void insertsponsor(sponsorlist* list, sponsor sponsor) {
    sponsorlist newsponsor = (sponsorlist)malloc(sizeof(sponsor));
    newsponsor->name = sponsor.name;
    newsponsor->next = NULL;

    if (*list == NULL) {
        *list = newsponsor;
    }
    else {
        sponsorlist current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newsponsor;
    }
}

void insertClub(clublist* list, club club) {
    clublist newClub = (clublist)malloc(sizeof(club));
    newClub->name = club.name;
    newClub->description = club.description;
    newClub->slogan = club.slogan;
    newClub->aim = club.aim;
    newClub->rule = club.rule;
    newClub->boss = club.boss;
    newClub->members = club.members;
    newClub->sponsors = club.sponsors;
    newClub->next = NULL;

    if (*list == NULL) {
        *list = newClub;
    }
    else {
        clublist current = *list;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newClub;
    }
}

void printClubList(clublist list) {
    while (list != NULL) {
        cout << "Club Name: " << list->name << endl;
        cout << "Description: " << list->description << endl;
        cout << "Slogan: " << list->slogan << endl;
        cout << "Aim: " << list->aim << endl;
        cout << "Rule: " << list->rule << endl;
        cout << "Boss: " << list->boss << endl;
        cout << "Members:\n";
        memberlist m = list->members;
        while (m != NULL) {
            cout << "Name: " << m->name << " Age: " << m->age << " Point: " << m->point  << endl;
            m = m->next;
        }
        cout << "sponsors:\n";
        sponsorlist a = list->sponsors;
        while (a != NULL) {
            cout << "Name: " << a->name  << endl;
            a = a->next;
        }
        cout << endl;
        list = list->next;
    }
}
