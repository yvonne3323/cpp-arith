#include"club_analyse.h"

#include"4.cpp"
#include"3.cpp"

//将一行数据转换成club结构体
club* lineToClub(string line, ifstream& infile)
{
    //读取社团
    club* c = new club;
    c->members = NULL;
    c->sponsors = NULL;
    c->next = NULL;
    //以上是初始化
    int pos = line.find(":");//找到冒号的位置
    c->name = line.substr(pos + 1);//截取冒号后面的字符串
    getline(infile, line);//读取下一行
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
    getline(infile, line);
    pos = line.find(":");
    c->description = line.substr(pos + 1);
    //读取成员
    memberlist ml = NULL;
    memberlist tail1 = NULL;
    while (getline(infile, line) && line != "sponsor:") 
    {
        if (line == "member:") 
        {
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
        if (line.substr(pos + 1) == "Male") 
        {
            m->gender = Male;
        } 
        else if (line.substr(pos + 1) == "Female") 
        {
            m->gender = Female;
        } 
        else 
        {
        m->gender = Unknown;
        }
        getline(infile, line);
        pos = line.find(":");
        stringstream ss2(line.substr(pos + 1));
        ss2 >> m->point;
        //level
        getline(infile, line);
        pos = line.find(":");
        stringstream ss3(line.substr(pos + 1));
        ss3 >> m->level;
        
        m->next = NULL;
        if (tail1 == NULL) {
            ml = m;
            tail1 = m;
        } 
        else 
        {
            tail1->next = m;
            tail1 = m;
        }
    }
    c->members = ml;
    //读取赞助商
    sponsorlist sl = NULL;
    sponsorlist tail2 = NULL;
    while (getline(infile, line)&&line!="end") 
    {
        sponsorlist s = new sponsor;
        pos = line.find(":");
        s->name = line.substr(pos + 1);
        s->next = NULL;
        if (tail2 == NULL) 
        {
            sl = s;
            tail2 = s;
        } 
        else 
        {
            tail2->next = s;
            tail2 = s;
        }
    }
    c->sponsors = sl;
    return c;
}

//读取文件中的所有社团数据，并存储到链表中
clublist readClubsFromFile(string filename)
{
    ifstream infile(filename);//打开文件
    clublist head = NULL;//头指针
    clublist tail = NULL;//尾指针
    for (string line; getline(infile, line); ) 
    {
        if (line != "") 
        {
            club* c = lineToClub(line, infile);
            if (head == NULL) 
            {
                head = c;
                tail = c;
            } else 
            {
                tail->next = c;
                tail = c;
            }
        }
    }
    infile.close();
    return head;
}

//将社团链表中的数据存储到文件中
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


void printClubInfo(clublist c) {
    cout << "Club Name: " << c->name << endl;
    cout << "Description: " << c->description << endl;
    cout << "Slogan: " << c->slogan << endl;
    cout << "Aim: " << c->aim << endl;
    cout << "Rule: " << c->rule << endl;
    cout << "Boss: " << c->boss << endl;
    cout << "Members: " << endl;
    memberlist m = c->members;
    while (m != NULL) {
        cout << "Name: " << m->name << ", Age: " << m->age << ", Gender: " << (m->gender == Male ? "Male" : "Female") << ", Point: " << m->point << ", Level: " << m->level << endl;
        m = m->next;
    }
    cout << "Sponsors: " << endl;
    sponsorlist s = c->sponsors;
    while (s != NULL) {
        cout << "Name: " << s->name << endl;
        s = s->next;
    }
}

int main()
{
    clublist clubs = readClubsFromFile("clubs_2.txt");
    int choice;
    int bool1=1;
    while (bool1==1) {
        cout << "请选择操作：1.社团操作 2.成员操作 3.赞助商操作 4.删除 5.退出" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                club_modify(clubs);
                break;
            case 2:
                members_modify(clubs);
                break;
            case 3:
                sponser_modify(clubs);
                break;
            case 4:
                break;
            case 5:
                bool1=0;
                break;
            default:
                cout << "输入错误，请重新输入！" << endl;
        }
    }

    saveClubsToFile("clubs_new1.txt", clubs);
    return 0;
}