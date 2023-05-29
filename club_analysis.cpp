
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

//成员
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
    string slogan;//口号
    string aim;//宗旨
    string rule;//章程
    string boss;//发起人
    string description;//社团性质
    memberlist members;
    sponsorlist sponsors;
    struct club* next;
} club, *clublist;

//将一行数据转换成club结构体
club* lineToClub(string line, ifstream& infile) {
    club* c = new club;
    c->members = NULL;
    c->sponsors = NULL;
    c->next = NULL;
    int pos = line.find(":");
    c->name = line.substr(pos + 1);
    getline(infile, line);
    pos = line.find(":");
    c->description = line.substr(pos + 1);
    getline(infile, line);
    pos = line.find(":");
    c->slogan = line.substr(pos + 1);
    getline(infile, line);
    pos = line.find(":");
    c->aim = line.substr(pos + 1);
    getline(infile, line);
    pos = line.find(":");
    c->rule = line.substr(pos + 1);
    getline(infile, line);
    pos = line.find(":");
    c->boss = line.substr(pos + 1);




     memberlist ml = NULL;
memberlist tail = NULL;
while (getline(infile, line) && line != "sponsor:") {
    if (line == "member:") {
        continue;
    }
    memberlist m = new member;
    pos = line.find(":");
    m->name = line.substr(pos + 1);
    getline(infile, line);
    pos = line.find(":");
    stringstream ss(line.substr(pos + 1));
    ss >> m->age;
    getline(infile, line);
    pos = line.find(":");
    if (line.substr(pos + 1) == "Male") {
        m->gender = Male;
    } else if (line.substr(pos + 1) == "Female") {
        m->gender = Female;
    } else {
        m->gender = Unknown;
    }
    getline(infile, line);
    pos = line.find(":");
    stringstream ss2(line.substr(pos + 1));
    ss2 >> m->point;
    getline(infile, line);
    pos = line.find(":");
    stringstream ss3(line.substr(pos + 1));
    ss3 >> m->level;
    m->next = NULL;
    if (tail == NULL) {
        ml = m;
        tail = m;
    } else {
        tail->next = m;
        tail = m;
    }
}
c->members = ml;


    //读取赞助商
    sponsorlist sl = NULL;
sponsorlist tail2 = NULL;
while (getline(infile, line)&&line!="end") {
    sponsorlist s = new sponsor;
    pos = line.find(":");
    s->name = line.substr(pos + 1);
    s->next = NULL;
    if (tail2 == NULL) {
        sl = s;
        tail2 = s; 
    } else {
        tail2->next = s;
        tail2 = s;
    }
}
c->sponsors = sl;
    return c;
}

//读取文件中的所有社团数据，并存储到链表中
clublist readClubsFromFile(string filename) {
    ifstream infile(filename);
    clublist head = NULL;
    clublist tail = NULL;
    for (string line; getline(infile, line); ) {
        if (line != "") {
            club* c = lineToClub(line, infile);
            if (head == NULL) {
                head = c;
                tail = c;
            } else {
                tail->next = c;
                tail = c;
            }
        }
    }
    infile.close();
    return head;
}

//打印社团信息
void printClub(club* c) {
    cout << "名称：" << c->name << endl;
    cout << "口号：" << c->slogan << endl;
    cout << "宗旨：" << c->aim << endl;
    cout << "章程：" << c->rule << endl;
    cout << "发起人：" << c->boss << endl;
    cout << "社团性质：" << c->description << endl;
    cout << "成员列表：" << endl;
    memberlist ml = c->members;
    while (ml != NULL) {
        cout << "姓名：" << ml->name << "，年龄：" << ml->age << "，性别：";
        if (ml->gender == Male) {
            cout << "男";
        } else if (ml->gender == Female) {
            cout << "女";
        } else {
            cout << "未知";
        }
        cout << "，积分：" << ml->point << endl;
        cout << "等级：" << ml->level << endl;
        ml = ml->next;
    }
    cout << "赞助商列表：" << endl;
    sponsorlist sl = c->sponsors;
    while (sl != NULL) {
        cout << sl->name << endl;
        sl = sl->next;
    }
    cout << endl;
}

void saveClubsToFile(string filename, clublist clubs) {
    ofstream outfile(filename);
    clublist c = clubs;
    while (c != NULL) {
        outfile << "name:" << c->name << endl;
        outfile << "slogan:" << c->slogan << endl;
        outfile << "aim:" << c->aim << endl;
        outfile << "rule:" << c->rule << endl;
        outfile << "boss:" << c->boss << endl;
        outfile << "description:" << c->description << endl;
        outfile << "member:" << endl;
        memberlist ml = c->members;
        while (ml != NULL) {
            outfile << "name:" << ml->name << endl;
            outfile << "age:" << ml->age << endl;
            outfile << "gender:";
            if (ml->gender == Male) {
                outfile << "Male" << endl;
            } else if (ml->gender == Female) {
                outfile << "Female" << endl;
            } else {
                outfile << "Unknown" << endl;
            }
            outfile << "point:" << ml->point << endl;
            outfile << "level:" << ml->level << endl;
            ml = ml->next;
        }
        outfile << "sponsor:" << endl;
        sponsorlist sl = c->sponsors;
        while (sl != NULL) {
            outfile << "name:" << sl->name << endl;
            sl = sl->next;
        }
        outfile << "end" << endl;
        c = c->next;
    }
    outfile.close();
}




int main() {
    clublist clubs = readClubsFromFile("clubs_2.txt");
    clublist c = clubs;
    while (c != NULL) {
        printClub(c);
        c = c->next;
    }
    
    saveClubsToFile("clubs_new.txt", clubs);
    
    return 0;
}