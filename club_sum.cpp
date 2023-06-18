#include"club_analyse.h"

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

int main() {
    clublist clubs = readClubsFromFile("clubs_2.txt");
    clublist c = clubs;
    while (c != NULL) {
        printClub(c);
        c = c->next;
    }
    
    saveClubsToFile("clubs_new1.txt", clubs);
    
    return 0;
}