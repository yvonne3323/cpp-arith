#include"HL.cpp"
//修改积分
void modifyScore(memberlist *members, string name, int score) 
{
    member *current = *members;
    while (current != NULL) 
	{
        if (current->name == name) 
		{   // 找到指定成员并修改积分
            current->point = score;
            break;
        }
        current = current->next;
    }
    if (current == NULL) 
	{
        printf("没有找到名字为%s的成员\n", name.c_str());
    }
}

//查找成员
int Search_Score(memberlist*members,string name)
{
	member*current=*members;
	while(current!=NULL)
	{
		if(current->name==name)
		{
			return current->point;
		}
		current=current->next;
	}
	printf("没有找到名字为%s的成员\n",name.c_str());
	return -1;
}

//成员增加
void add_member(clublist head) {
    string club_name;
    cout << "请输入所属社团名称：";
    cin >> club_name;
    club* p = head;
    while (p != NULL) {
        if (p->name == club_name) {
            member* new_member = new member;
            cout << "请输入姓名：";
            cin >> new_member->name;
            cout << "请输入年龄：";
            cin >> new_member->age;
            cout << "请输入性别（0表示男，1表示女，2表示未知）：";
            int gender;
            cin >> gender;
            new_member->gender = static_cast<Gender>(gender);
            cout << "请输入积分：";
            cin >> new_member->point;
            cout << "请输入等级：";
            cin >> new_member->level;
            new_member->next = p->members;
            p->members = new_member;
            cout << "添加成功！" << endl;
            return;
        }
        p = p->next;
    }
    cout << "未找到该社团！" << endl;
}

//成员删除
void delete_member(clublist head) {
    string club_name;
    cout << "请输入所属社团名称：";
    cin >> club_name;
    club* p = head;
    while (p != NULL) {
        if (p->name == club_name) {
            string member_name;
            cout << "请输入要删除的成员姓名：";
            cin >> member_name;
            member* p1 = p->members;
            member* pre = NULL;
            while (p1 != NULL) {
                if (p1->name == member_name) {
                    if (pre == NULL) {
                        p->members = p1->next;
                    } else {
                        pre->next = p1->next;
                    }
                    delete p1;
                    cout << "删除成功！" << endl;
                    return;
                }
                pre = p1;
                p1 = p1->next;
            }
            cout << "未找到该成员！" << endl;
            return;
        }
        p = p->next;
    }
    cout << "未找到该社团！" << endl;
}

//对成员的积分进行排序
void Sort_Score(memberlist *members) 
{
    member *p, *q;
    member *maxp;
    for (p = *members; p != NULL; p = p->next) 
	{
        maxp = p;
        for (q = p->next; q != NULL; q = q->next) 
		{
            if (q->point > maxp->point) 
			{
                maxp = q;
            }
        }
        if (maxp != p) 
		{
            swap(maxp->point, p->point);
            swap(maxp->name, p->name);
        }
    }
}

//求积分平均值
double Avg_Score(memberlist *members) 
{
    double sum = 0;
    int count = 0;
    member *p;
    for (p = *members; p != NULL; p = p->next) 
	{
        sum += p->point;
        count++;
    }
    if (count == 0) 
	{   // 如果链表为空，则返回 0
        return 0;
    } 
	else 
	{
        return sum / count;
    }
}
// 定义修改积分等级函数

// 选择指定名称的社团
clublist select_club(clublist head, string name) {
    clublist p = head;
    while (p != NULL) {
        if (p->name == name) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}



// 假设现在有一个成员结构体指针 m，其积分为 250 分，调用如下代码即可更新其等级
//modify_member_level(m);

//成员积分部分完成，接下来开始赞助商部分
//// 查找赞助商


//sponsor* find_sponsor(sponsor* head, string name) 
//{
//    sponsor* p = head;
//    while (p != NULL) 
//	{
//        if (p->name == name) 
//		{
//            return p;
//        }
//        p = p->next;
//    }
//    return NULL; // 未找到赞助商
//}




//// 修改赞助商
//int modify_sponsor(sponsor* head, string oldname, string newname) 
//{
//    sponsor* p = find_sponsor(head, oldname);
//    if (p == NULL) 
//	{
//        return 0; // 未找到需要修改的赞助商
//    }
//    p->name = newname;
//    return 1; // 修改成功
//}
//
//// 删除赞助商
//int delete_sponsor(sponsor** head, string name) 
//{
//    sponsor* p = *head;
//    sponsor* q = NULL;
//    while (p != NULL && p->name != name) 
//	{
//        q = p;
//        p = p->next;
//    }
//    if (p == NULL) 
//	{
//        return 0; // 未找到需要删除的赞助商
//    }
//    if (q == NULL) 
//	{ // 要删除的节点是头节点
//        *head = p->next;
//    } 
//	else 
//	{
//        q->next = p->next;
//    }
//    delete p; // 释放节点内存
//    return 1; // 删除成功
//}
// 查找赞助商函数，输入参数为社团链表头指针和赞助商名称

// 修改赞助商函数，输入参数包括社团链表头指针、原赞助商名称、新赞助商名称
// 1 表示修改成功，0 表示未找到需要修改的赞助商



//int modify_sponsor(club* head, string old_name, string new_name) 
//{
//    sponsor* s = find_sponsor(head, old_name);  // 先查找需要修改的赞助商
//    if (s == NULL) 
//	{
//        return 0;  // 失败
//    } 
//	else 
//	{
//        s->name = new_name;  // 修改
//        return 1;  // 成功
//    }
//}

// 删除赞助商函数，输入参数为社团链表头指针和赞助商名称
// 1 表示成功，0 表示未找到
int delete_sponsor(club* head, string sponsor_name) {
    club* p = head;  // 遍历社团链表
    while (p != NULL) 
	{
        sponsor* s = p->sponsors;  // 遍历赞助商链表
        sponsor* q = NULL;
        while (s != NULL) 
		{
            if (s->name == sponsor_name) 
			{  // 找到需要删除的赞助商
                if (q == NULL) 
				{ 
                    p->sponsors = s->next;
                } 
				else 
				{
                    q->next = s->next;  // 删除该赞助商
                }
                delete s;
                return 1;  //成功
            }
            q = s;
            s = s->next;
        }
        p = p->next;
    }
    return 0;  // 失败
}
   
   
   
   
void sponsor_message(clublist heads) {
	string name1;
    cout<<"请输入社团名称："<<endl;
    cin>>name1;
    
    
    
    
    
    club* p = heads;  // 遍历社团链表
    while (p != NULL) 
	{
        if(p->name==name1){
        	cout<<"社团的赞助商有："<<endl;
			sponsorlist sp=p->sponsors;
			sponsorlist spp=p->sponsors;
			while(sp!=NULL){
				cout<<sp->name<<endl;
				sp = sp->next;
			}
        	int x,x2;
        	cout<<"请选择你的操作:1删除，2增加"<<endl;
        	cin>>x;
        	switch(x){
        		case 1:
        			{
        				cout<<"你要删除第几个？"<<endl;
						cin>>x2;
						if(x2==1){
							p->sponsors=p->sponsors->next;
							free(spp);
						}else{
							for(x2-=2;x2>0 && spp != NULL;x2--){
								spp=spp->next;	
							}
							if(spp==NULL){
							cout<<"该社团没有那么多赞助商！"<<endl;
							}else{
								sponsorlist sppp=spp->next;
								spp->next=sppp->next;
								free(sppp);
							}
							
						}cout<<"删除成功"<<endl;
        			break;
					}
				case 2:
					{
					    string sponsor_name;
                        cout<<"请输入要增加的赞助商名称："<<endl;
                        cin>>sponsor_name;
                        sponsorlist new_sponsor = new sponsor;  
                        new_sponsor->name = sponsor_name;   
                        new_sponsor->next = NULL;

                        if(p->sponsors == NULL) {  
                            p->sponsors = new_sponsor;
                        }
                        else {  
                            sponsorlist cur = p->sponsors;
                            while(cur->next != NULL) {
                                    cur = cur->next;
                                }
                            cur->next = new_sponsor;
                           }
                        cout<<"增加成功"<<endl;
                        break;	
					}
					break;	   
        	}
		}
        p = p->next;
    }
   if(p == NULL )cout<<"找不到该社团！"<<endl;

    
}
void findclub(clublist clubs,string name1){
	int bool1=1;
	while(clubs != NULL && bool1==1){
		sponsorlist p1=clubs->sponsors;
		while(p1!=NULL && bool1==1){
			if(p1->name == name1){
				cout<<"赞助商 "<<name1<<" 赞助的社团是："<<clubs->name<<endl;
				bool1=0;
			}
			p1=p1->next;
		}

	
		clubs=clubs->	next;
	}
	if(bool1==1)cout <<"很抱歉，没有找到此赞助商赞助的社团"<<endl;
}

void sponser_modify(clublist head){
	int choice;
    int bool1=1;
    while (bool1==1) {
        cout << "请选择赞助商操作：1.查询 2.修改 3.返回上一层" << endl;
        cin >> choice;
        switch (choice) {
            case 1:
            	{
            	string name;
            	cout<<"请输入赞助商名称"<<endl;
            	cin>>name;
                findclub(head,name);
                break;
				}
            case 2:
            	{
            		sponsor_message(head);
            		 break;
				}
                
            case 3:
                {
					bool1=0;
                	break;
				}
            default:
                cout << "输入错误，请重新输入！" << endl;
        }
    }
}
void members_modify(clublist heads){
	int choice;
    int bool1=1;
    while (bool1==1) {
        cout << "请选择成员操作：1.查询 2.修改 3.增加 4.积分排序 5.删除 6.返回上一层 " << endl;
        cin >> choice;
        switch (choice) {
            case 1:
            	{	string name2;
            		cout<<"请输入成员姓名："<<endl;
            		cin>>name2;
            		findMember(heads,name2);
                	break;
				}
            case 2:{
            	string name2;
            	cout<<"请输入成员姓名："<<endl;
            	cin>>name2;
            	modifyMember(heads,name2);
            	
                break;
			}	
            case 3:
            	{
                     add_member(heads);
                    //调用增加成员函数

                	break;	
				}
            	
            case 4:
                {
                    string club_name;
                    cout << "请输入社团名称：";
                    cin >> club_name;
                    // 选择指定名称的社团
                    clublist target_club = select_club(heads, club_name);
                    if (target_club == NULL) {
                        cout << "该社团不存在！" << endl;
                        break;
                    }
                    // 对该社团的成员链表进行积分排序
                    Sort_Score(&(target_club->members));
                    cout << "积分排序完成！" << endl;
                    break;	
				}
               
            case 5:
			{
                delete_member(heads);
                break;
				
			}
            case 6:
            {
                bool1=0;
                break;
            }
            default:
                cout << "输入错误，请重新输入！" << endl;
        }
    }
}
