#include"club_analyse.h"

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
void saveClubsToFile(string filename, clublist clubs)
{
    ofstream outfile(filename);//打开文件
    clublist c = clubs;
    while (c != NULL) 
    {
        outfile << "name:" << c->name << endl;
        outfile << "slogan:" << c->slogan << endl;
        outfile << "aim:" << c->aim << endl;
        outfile << "rule:" << c->rule << endl;
        outfile << "boss:" << c->boss << endl;
        outfile << "description:" << c->description << endl;
        outfile << "members:" << endl;
        memberlist ml = c->members;
        while (ml != NULL) 
        {
            outfile << "member:" << endl;
            outfile << "name:" << ml->name << endl;
            outfile << "age:" << ml->age << endl;
            outfile << "gender:";
            if (ml->gender == Male) 
            {
                outfile << "Male" << endl;
            } 
            else if (ml->gender == Female) 
            {
                outfile << "Female" << endl;
            } 
            else 
            {
                outfile << "Unknown" << endl;
            }
            outfile << "point:" << ml->point << endl;
            outfile << "level:" << ml->level << endl;
            ml = ml->next;
        }
        outfile << "sponsor:" << endl;
        sponsorlist sl = c->sponsors;
        while (sl != NULL) 
        {
            outfile << "name:" << sl->name << endl;
            sl = sl->next;
        }
        outfile << "end" << endl;
        c = c->next;
    }
    outfile.close();
}