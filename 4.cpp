#include <iostream>
#include <string>
using namespace std;

// 定义社团结构体


// 创建新的社团信息
club* create_club() {
    club* new_club = new club;
    cout << "请输入社团名称：";
    cin >> new_club->name;
    cout << "请输入社团性质：";
    cin >> new_club->description;
    cout << "请输入社团口号：";
    cin >> new_club->slogan;
    cout << "请输入社团宗旨：";
    cin >> new_club->aim;
    cout << "请输入社团章程：";
    cin >> new_club->rule;
    cout << "请输入社团发起人：";
    cin >> new_club->boss;
    new_club->next = NULL;
    return new_club;
}
//输出社团信息
void print_club(club* c) {
    cout << "社团名称：" << c->name << endl;
    cout << "社团性质：" << c->description << endl;
    cout << "社团口号：" << c->slogan << endl;
    cout << "社团宗旨：" << c->aim << endl;
    cout << "社团章程：" << c->rule << endl;
    cout << "社团发起人：" << c->boss << endl;
}
// 查询社团信息
void query_club(clublist head) {
    string name;
    cout << "请输入要查询的社团名称：";
    cin >> name;
//    club* p = head->next;
    club* p = head;
    while (p != NULL) {
        if (p->name == name) {
            print_club(p);
            return;
        }
        p = p->next;
    }
    cout << "未找到该社团！" << endl;
}

// 修改社团信息
void modify_club(clublist head) {
    string name;
    cout << "请输入要修改的社团名称：";
    cin >> name;
    club* p = head;
    while (p != NULL) {
        if (p->name == name) {
            print_club(p);
            cout << "请输入新的社团信息：" << endl;
            
//            cin >> p->description >> p->slogan >> p->aim >> p->rule >> p->boss;
            
             cout << "请输入社团名称：";
    		cin >> p->name;
    		cout << "请输入社团性质：";
    		cin >> p->description;
    		cout << "请输入社团口号：";
    		cin >> p->slogan;
    		cout << "请输入社团宗旨：";
    		cin >> p->aim;
    		cout << "请输入社团章程：";
    		cin >>p->rule;
    		cout << "请输入社团发起人：";
    		cin >> p->boss;
            
            
            cout << "修改成功！" << endl;
            return;
        }
        p = p->next;
    }
    cout << "未找到该社团！" << endl;
}

//修改社团信息二版
void modify_club2(clublist head) {
    string name;
    cout << "请输入要修改的社团名称：";
    cin >> name;
    club* p = head;
    while (p != NULL) {
        if (p->name == name) {
            print_club(p);
            cout << "请选择要修改的内容：" << endl;
            cout << "1. 社团名称" << endl;
            cout << "2. 社团性质" << endl;
            cout << "3. 社团口号" << endl;
            cout << "4. 社团宗旨" << endl;
            cout << "5. 社团章程" << endl;
            cout << "6. 社团发起人" << endl;
            cout << "7. 全部修改" << endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "请输入新的社团名称：";
                    cin >> p->name;
                    break;
                case 2:
                    cout << "请输入新的社团性质：";
                    cin >> p->description;
                    break;
                case 3:
                    cout << "请输入新的社团口号：";
                    cin >> p->slogan;
                    break;
                case 4:
                    cout << "请输入新的社团宗旨：";
                    cin >> p->aim;
                    break;
                case 5:
                    cout << "请输入新的社团章程：";
                    cin >> p->rule;
                    break;
                case 6:
                    cout << "请输入新的社团发起人：";
                    cin >> p->boss;
                    break;
                case 7:
                    cout << "请输入新的社团信息：" << endl;
                    cout << "请输入社团名称：";
                    cin >> p->name;
                    cout << "请输入社团性质：";
                    cin >> p->description;
                    cout << "请输入社团口号：";
                    cin >> p->slogan;
                    cout << "请输入社团宗旨：";
                    cin >> p->aim;
                    cout << "请输入社团章程：";
                    cin >> p->rule;
                    cout << "请输入社团发起人：";
                    cin >> p->boss;
                    break;
                default:
                    cout << "无效的选择！" << endl;
                    break;
            }
            cout << "修改成功！" << endl;
            return;
        }
        p = p->next;
    }
    cout << "未找到该社团！" << endl;
}

// 增加社团信息
void add_club(clublist head) {
	clublist p1=head;
    club* new_club = new club;
    while(p1->next != NULL)p1=p1->next;
    p1->next=new_club;

    cout << "添加成功！" << endl;
    cout << "请输入社团名称：";
    cin >> new_club->name;
    cout << "请输入社团性质：";
    cin >> new_club->description;
    cout << "请输入社团口号：";
    cin >> new_club->slogan;
    cout << "请输入社团宗旨：";
    cin >> new_club->aim;
    cout << "请输入社团章程：";
    cin >> new_club->rule;
    cout << "请输入社团发起人：";
    cin >> new_club->boss;
    new_club->next = NULL;
    
}


//增加社团信息二版
void add_club2(clublist head) {
    clublist p1 = head;
    club* new_club = new club;
    new_club->members = NULL;
    new_club->sponsors = NULL;

    cout << "请输入社团名称：";
    cin >> new_club->name;
    cout << "请输入社团性质：";
    cin >> new_club->description;
    cout << "请输入社团口号：";
    cin >> new_club->slogan;
    cout << "请输入社团宗旨：";
    cin >> new_club->aim;
    cout << "请输入社团章程：";
    cin >> new_club->rule;
    cout << "请输入社团发起人：";
    cin >> new_club->boss;
    new_club->next = NULL;

    // 添加社团成员信息
    cout << "请输入社团成员信息（输入end结束）：" << endl;
    while (true) {
        string member_name;
        cout << "请输入成员姓名：";
        cin >> member_name;
        if (member_name == "end") break;
        member* new_member = new member;
        new_member->name = member_name;
        cout << "请输入成员年龄：";
        cin >> new_member->age;
        cout << "请输入成员性别（Male/Female/Unknown）：";
        string gendern;
        cin >> gendern;
        if (gendern == "Male") {
            new_member->gender = Male;
        } else if (gendern == "Female") {
            new_member->gender = Female;
        } else {
            new_member->gender = Unknown;
        }
        cout << "请输入成员积分：";
        cin >> new_member->point;
        cout << "请输入成员等级：";
        cin >> new_member->level;
        new_member->next = NULL;
        if (new_club->members == NULL) {
            new_club->members = new_member;
        } else {
            member* p2 = new_club->members;
            while (p2->next != NULL) p2 = p2->next;
            p2->next = new_member;
        }
    }

    // 添加赞助商信息
    cout << "请输入赞助商信息（输入end结束）：" << endl;
    while (true) {
        string sponsor_name;
        cout << "请输入赞助商名称：";
        cin >> sponsor_name;
        if (sponsor_name == "end") {
            break;
        }
        sponsor* new_sponsor = new sponsor;
        new_sponsor->name = sponsor_name;
        new_sponsor->next = NULL;
        if (new_club->sponsors == NULL) {
            new_club->sponsors = new_sponsor;
        } else {
            sponsor* p3 = new_club->sponsors;
            while (p3->next != NULL) p3 = p3->next;
            p3->next = new_sponsor;
        }
    }

    if (p1->next == NULL) {
        p1->next = new_club;
    } else {
        while (p1->next != NULL) {
            p1 = p1->next;
        }
        p1->next = new_club;
    }

    cout << "添加成功！" << endl;
}

// 删除社团信息
void delete_club(clublist head) {
    string name;
    cout << "请输入要删除的社团名称：";
    cin >> name;
    club* p = head;
    club* pre = head;
    while (p != NULL) {
        if (p->name == name) {
            pre->next = p->next;
            delete p;
            cout << "删除成功！" << endl;
            return;
        }
        pre = p;
        p = p->next;
    }
    cout << "未找到该社团！" << endl;
}




// 主函数
void club_modify(clublist head) {
//    clublist head = new club;
//    head->next = NULL;
    int choice;
    int bool1=1;
    while (bool1==1) {
        cout << "请选择社团操作：1.查询 2.修改 3.增加 4.删除 5.返回上一层" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
                query_club(head);
                break;
            case 2:
                modify_club2(head);
                break;
            case 3:
                add_club2(head);
                break;
            case 4:
                delete_club(head);
                break;
            case 5:
                bool1=0;
                break;
            default:
                cout << "输入错误，请重新输入！" << endl;
        }
    }
}