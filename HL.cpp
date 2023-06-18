
#include <iostream>
#include <string>

using namespace std;


// 根据社团名称查找社团

//clublist findClub(clublist head, string name) {
//    clublist p = head;
//    while (p != NULL) {
//        if (p->name == name) {
//            return p;
//        }
//        p = p->next;
//    }
//    return NULL;
//}

int modify_member_level(member* m) {
    // 根据积分计算等级
    int a;
    int level = m->point / 100 + 1;
    if (level > 10) {  // 如果超过了最高等级，则设置为 10
        level = 10;
    }
    m->level = level;  // 设置等级
    a=m->level;
    return a;
}

// 根据姓名查找学生
void findMember(clublist clubs, string name1) {
	memberlist p2=clubs->members;
	int bool1=1;
	int x;
	x=modify_member_level(p2);
	while(clubs != NULL && bool1==1){
		memberlist p1=clubs->members;
		while(p1!=NULL && bool1==1){
			if(p1->name == name1){
				cout<<"成员 "<<name1<<" 所在的社团是："<<clubs->name<<endl;
				cout<<"成员 "<<name1<<" 的年龄为"<<p1->age<<"   积分"<<p1->point<<"分"<<endl;
//				cout<<"修改成功"<<endl;
				cout<<"成员 "<<name1<<" 的等级为"<<x<<" 级"<<endl;
				bool1=0;
			}
			p1=p1->next;
		}

	
		clubs=clubs->	next;
	}
	if(bool1==1)cout <<"很抱歉，没有找到该成员"<<endl;
	

}

// 删除学生
void deleteMember(memberlist head, string name) {
    memberlist p = head;
    memberlist pre = NULL;
    while (p != NULL) {
        if (p->name == name) {
            if (pre == NULL) {
                head = p->next;
            } else {
                pre->next = p->next;
            }
            delete p;
            return;
        }
        pre = p;
        p = p->next;
    }
}

// 修改学生信息
//void modifyMemberAI(memberlist head, string name) {
//    memberlist p = findMember(head, name);
//    if (p == NULL) {
//        cout << "学生不存在" << endl;
//        return;
//    }
//    cout << "请输入学生姓名：" << endl;
//    cin >> p->name;
//    cout << "请输入学生年龄：" << endl;
//    cin >> p->age;
//    cout << "请输入学生性别（0表示男，1表示女）：" << endl;
//    int gender;
//    cin >> gender;
//    p->gender = (gender == 0) ? Male : Female;
//    cout << "请输入学生积分：" << endl;
//    cin >> p->point;
//    cout << "请输入学生等级：" << endl;
//    cin >> p->level;
//}








void modifyMember(clublist clubs, string name1) {
	
	int bool1=1;
	while(clubs != NULL && bool1==1){
		memberlist p1=clubs->members;
		while(p1!=NULL && bool1==1){
			if(p1->name == name1){
				cout<<"已找到"<<clubs->name<<"的成员"<<p1->name<<endl;
				
				
				
				cout << "成员改名：";
    			cin >> p1->name;
    			cout << "成员年龄修改：";
    			cin >> p1->age;
    			cout << "成员改分：";
    			cin >> p1->point;				
				bool1=0;
			}
			p1=p1->next;
		}

	
		clubs=clubs->	next;
	}
	if(bool1==1)cout <<"很抱歉，没有找到该成员"<<endl;
	

}








// 增加学生







//void fakemain3(clublist head)
//{
////	创建社团及其中的学生信息
////    clublist head = new club;
////    head->next = NULL;
////    clublist c = new club;s
////    c->name = "计算机协会";
////    c->description = "学习计算机知识";
////    c->slogan = "编程改变世界";
////    c->aim = "提高计算机技能";
////    c->rule = "遵守社团章程";
////    c->boss = "张三";
////    c->members = new member;
////    c->members->next = NULL;
////    memberlist m1 = new member;
////    m1->name = "李四";
////    m1->age = 20;
////    m1->gender = Male;
////    m1->point = 100;
////    m1->level = 1;
////    m1->next = c->members->next;
////    c->members->next = m1;
////    memberlist m2 = new member;
////    m2->name = "王五";
////    m2->age = 19;
////    m2->gender = Female;
////    m2->point = 80;
////    m2->level = 2;
////    m2->next = c->members->next;
////    c->members->next = m2;
////    c->sponsors = new sponsor;
////    c->sponsors->next = NULL;
////    c->next = head->next;
////    head->next = c;
////    clublist head = NULL;
//
//
////    while (true)
////	{
//        cout << "请选择操作：" << endl;
//        cout << "1.查找学生信息" << endl;
//        cout << "2.删除学生信息" << endl;
//        cout << "3.修改学生信息" << endl;
//        cout << "4.增加学生" << endl;
//        int choice;
//        cin >> choice;
//        if (choice == 1)
//		{
//            cout << "请输入社团名称：" << endl;
//            string name;
//            cin >> name;
//            clublist c = findClub(head, name);
//            if (c == NULL)
//			{
//                cout << "社团不存在" << endl;
//            } 
//			else
//			{
//                cout << "请输入学生姓名：" << endl;
//                string name;
//                cin >> name;
//                memberlist m = findMember(c->members, name);
//                if (m == NULL) 
//				{
//                    cout << "学生不存在" << endl;
//                }
//				else
//				{
//                    cout << "姓名：" << m->name << endl;
//                    cout << "年龄：" << m->age << endl;
//                    cout << "性别：" << ((m->gender == Male) ? "男" : "女") << endl;
//                    cout << "积分：" << m->point << endl;
//                    cout << "等级：" << m->level << endl;
//                }
//            }
//        }
//		else if (choice == 2)
//		{
//            cout << "请输入社团名称：" << endl;
//            string name;
//            cin >> name;
//            clublist c = findClub(head, name);
//            if (c == NULL)
//			{
//                cout << "社团不存在" << endl;
//            }
//			else
//			{
//                cout << "请输入学生姓名：" << endl;
//                string name;
//                cin >> name;
//                deleteMember(c->members, name);
//                cout << "删除成功" << endl;
//            }
//        }
//		else if (choice == 3) 
//		{
//            cout << "请输入社团名称：" << endl;
//            string name;
//            cin >> name;
//            clublist c = findClub(head, name);
//            if (c == NULL)
//			{
//                cout << "社团不存在" << endl;
//            } 
//			else 
//			{
//                cout << "请输入学生姓名：" << endl;
//                string name;
//                cin >> name;
//                modifyMember(c->members, name);
//                cout << "修改成功" << endl;
//            }
//        } 
//		else if (choice == 4) 
//		{
//            cout << "请输入社团名称：" << endl;
//            string name;
//            cin >> name;
//            clublist c = findClub(head, name);
//            if (c == NULL) 
//			{
//                cout << "社团不存在" << endl;
//            } 
//			else 
//			{
//                addMember(c->members);
//                cout << "添加成功" << endl;
//            }
//        } 
//		else 
//		{
//            cout << "无效操作" << endl;
//        }
////    }
//}
