#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <windows.h>

void Main_Menu();
void AddressBook_management();

// 成员信息
typedef struct student
{
	char name[10];//姓名
	char num[30];//学号 
	char sex[5];//性别 
	char class1[20];//专业班级
	int age;//年龄 
	double score;//分数 
	char grade;//所处等级
	int Increase_score;//学生添加积分的次数
	int Deacrease_score;//学生减少积分的次数  
}Stu;

// 结点信息
typedef struct _Node
{
	Stu student;
	struct _Node* next;
}Node;

void Sort_Information(Node* L);
Node* initNode(); //创建成员信息节点
void insertNode(Node* L, Stu e);//添加成员信息节点
void delNode(Node* L, Stu e); //删除成员信息节点
Node* getNode(Node* L, Stu e);//根据成员学号得到节点
int getLength(Node* L);//得到成员信息的个数
void load_S(Node* L);//导入文件中成员信息节点
void save_S(Node* L);//保存成员信息节点到文件中
void AddressBook_management(Node* L);//成员信息的管理 
void AddressBook_management(Node* L);

void Add_management(Node* L)//学生信息的录入 
{
	char f[10];
	Stu e;

	while (true)
	{
		printf("\n"); 
		printf("请输入成员的姓名： ");
		scanf("%s", e.name);

		printf("请输入成员的七位数学号： ");
		scanf("%s", e.num);

		printf("请输入成员的性别： ");
		scanf("%s", e.sex);

		printf("请输入成员的专业班级： ");
		scanf("%s", e.class1);

		printf("请输入成员的年龄： ");
		scanf("%d", &e.age);

		printf("请输入成员的积分： ");
		scanf("%lf", &e.score);

		if (e.score >= 80.00) e.grade = 'A';
		else if (e.score >= 70.00 && e.score < 80.00) e.grade = 'B';
		else if (e.score >= 60.00 && e.score < 70.00) e.grade = 'C';
		else e.grade = 'D';
		
		e.Increase_score = 0;//学生添加积分的次数
		e.Deacrease_score = 0;//学生减少积分的次数  

		insertNode(L, e);
		printf("\n\t\t\t\t\t    是否继续输入？(y/n):  ");
		scanf("%s", f);
		if (f[0] == 'n' || f[0] == 'N')  break; //判断是否退出
	}
	printf("\n\t\t\t\t\t    温馨提示：该成员信息录入成功 ！             \n\n");
	save_S(L);//保存成员信息节点到文件中
}

void Print_Information(Node* L)//打印文件中所有成员的信息 
{
	system("cls"); // 清屏
	printf("\n");
	printf("\t\t\t\t\t     * 成 员 信 息 展 示  *\n\n");
	printf("** 姓名\t     学号\t 性别\t     专业班级\t  年龄\t     积分\t  等级\t   成员加分次数\t   成员减分次数 **\n");

	// 遍历链表
	Node* p = L->next;
	while (p != NULL)
	{
		printf("   %s\t   %s\t  %s\t\t%s\t   %d\t     %.2lf\t   %c\t        %d\t\t  %d \n",
			p->student.name,
			p->student.num,
			p->student.sex,
			p->student.class1,
			p->student.age,
			p->student.score,
			p->student.grade,
			p->student.Increase_score,
			p->student.Deacrease_score);
		    p = p->next;
	}
	printf("\n\n");
}

void Check_Deleteinformation(Node* L)//打印文件中所有成员的信息 
{
	printf("\n");
	printf("\t\t\t\t\t     * 成 员 信 息 展 示  *\n\n");
	printf("** 姓名\t     学号\t 性别\t     专业班级\t  年龄\t     积分\t  等级\t   成员加分次数\t   成员减分次数 **\n");

	// 遍历链表
	Node* p = L->next;
	while (p != NULL)
	{
		printf("   %s\t   %s\t  %s\t\t%s\t   %d\t     %.2lf\t   %c\t        %d\t\t  %d \n",
			p->student.name,
			p->student.num,
			p->student.sex,
			p->student.class1,
			p->student.age,
			p->student.score,
			p->student.grade,
			p->student.Increase_score,
			p->student.Deacrease_score);
		    p = p->next;
	}
	printf("\n\n");
}

void Check_Information(Node* L)//学生信息查询 
{
	int op,f;
	char na[15];
	char nu[15];
	while (true)
	{
		system("cls");
		printf("\n");
		printf("\t\t\t\t\t     * 成 员 信 息 的 查 询 *\n\n");
		printf("\t\t\t\t\t       1、全部成员的输出\n\n");
		printf("\t\t\t\t\t       2、按姓名输出\n\n");
		printf("\t\t\t\t\t       3、按学号输出\n\n");
		printf("\t\t\t\t\t       4、返回上一界面\n\n\n");

		printf("请选择功能： ");
		scanf("%d", &op);
		if (op == 1)
		{
			Print_Information(L);
			system("pause");
		}
		else if (op == 2)
		{
			f = 0;
			printf("\n");
			printf("请输入姓名： ");
			scanf("%s", na);
			printf("\n");
			printf("\t\t\t\t\t     * 该 成 员 信 息 如 下 *\n\n");
			printf("** 姓名\t     学号\t 性别\t     专业班级\t  年龄\t     积分\t  等级\t   成员加分次数\t   成员减分次数 **\n");
			Node* temp1 = L->next;
			while (temp1 != NULL)
			{
				if (strcmp(na, temp1->student.name) == 0)//strcmp判断字符串是否匹配 
				{
					printf("   %s\t   %s\t  %s\t\t%s\t   %d\t     %.2lf\t   %c\t        %d\t\t  %d \n\n",
						temp1->student.name,
						temp1->student.num,
						temp1->student.sex,
						temp1->student.class1,
						temp1->student.age,
						temp1->student.score,
						temp1->student.grade,
						temp1->student.Increase_score,
						temp1->student.Deacrease_score);
					f = 1;
				}
				temp1 = temp1->next;
			}
			if (f == 0)
			{
				printf("\t\t\t\t\t    温馨提示：该成员信息不存在 ！             \n\n");
			}
			system("pause");
		}
		else if (op == 3)
		{
			f = 0;
			printf("\n");
			printf("请输入七位数学号： ");
			scanf("%s", nu);
			printf("\n");
			printf("\t\t\t\t\t     * 该 成 员 信 息 如 下 *\n\n");
			printf("** 姓名\t     学号\t 性别\t     专业班级\t  年龄\t     积分\t  等级\t   成员加分次数\t   成员减分次数 **\n");
			Node* temp2 = L->next;
			while (temp2 != NULL)
			{
				if (strcmp(nu, temp2->student.num) == 0)//strcmp判断字符串是否匹配 
				{
					printf("   %s\t   %s\t  %s\t\t%s\t   %d\t     %.2lf\t   %c\t        %d\t\t  %d \n\n",
								temp2->student.name,
								temp2->student.num,
								temp2->student.sex,
								temp2->student.class1,
								temp2->student.age,
								temp2->student.score,
								temp2->student.grade,
								temp2->student.Increase_score,
								temp2->student.Deacrease_score
						);
					f = 1;
				}
				temp2 = temp2->next;
			}
			if (f == 0)
			{
				printf("\n"); 
				printf("\t\t\t\t\t    温馨提示：该成员信息不存在 ！             \n\n");
			}
			system("pause");
		}
		else AddressBook_management(L);
	}
}

void Modify_Information(Node* L)     //学生信息的修改并且保存到文件中 
{
	int k;
	Stu e;
	Node* p = NULL;

	printf("\n请输入七位数学号： ");
	scanf("%s", e.num);
	p = getNode(L, e);

	if (p == NULL)
	{
		printf("\t\t\t\t\t    温馨提示：该成员信息不存在 ！             \n\n");
		return;
	}
	e = p->student;
	printf("\n");
	printf("\t\t\t\t\t     * 该 成 员 信 息 如 下 *\n\n");
	printf("** 姓名\t     学号\t 性别\t     专业班级\t  年龄\t     积分\t  等级\t   成员加分次数\t   成员减分次数 **\n");
	printf("   %s\t   %s\t  %s\t\t%s\t   %d\t     %.2lf\t   %c\t        %d\t\t  %d \n",
			e.name,
			e.num,
			e.sex,
			e.class1,
			e.age,
			e.score,
			e.grade,
			e.Increase_score,
			e.Deacrease_score
		 );
	printf("\n");
	printf("\t\t\t\t\t     * 成 员 信 息 的 修 改 *\n\n");
	printf("\t\t\t\t\t       1、修改成员的姓名\n\n");
	printf("\t\t\t\t\t       2、修改成员的学号\n\n");
	printf("\t\t\t\t\t       3、修改成员的专业班级\n\n");
	printf("\t\t\t\t\t       4、修改成员的年龄\n\n");
	printf("\t\t\t\t\t       5、返回上一页面\n\n\n");
		
	printf("请输入要修改的地方： ");
	scanf("%d", &k);
	if (k == 1)
	{
		printf("\n请输入修改后姓名： ");
		scanf("%s", e.name);
	}
	else if (k == 2)
	{
		printf("\n请输入修改后学号： ");
		scanf("%s", e.num);
	}
	else if (k == 3)
	{
		printf("\n请输入修改后专业班级： ");
		scanf("%s", e.class1);
	}
	else if (k == 4)
	{
		printf("\n请输入修改后年龄： ");
		scanf("%d", &e.age);
	}
	else AddressBook_management(L);

	p->student = e;
	printf("\t\t\t\t\t    温馨提示：该成员信息修改成功 ！             \n\n");
	printf("\t\t\t\t\t     * 该 成 员 修 改 后 信 息 如下*\n\n");
	printf("** 姓名\t     学号\t 性别\t     专业班级\t  年龄\t     积分\t  等级\t   成员加分次数\t   成员减分次数 **\n");
	printf("   %s\t   %s\t  %s\t\t%s\t   %d\t     %.2lf\t   %c\t        %d\t\t  %d \n\n\n",
		e.name,
		e.num,
		e.sex,
		e.class1,
		e.age,
		e.score,
		e.grade,
		e.Increase_score,
		e.Deacrease_score);
	save_S(L);
}

void Delete_Information(Node* L)     //从文件中进行学生信息的删除 
{
	int f = 0;
	Stu e;
	printf("\n");
	printf("请输入需要删除成员的七位数学号： ");
	scanf("%s", e.num);
	if (getNode(L, e) != NULL)
	{
		printf("\n\t\t\t\t    已找到数据，是否删除？(y/n)： ");
		char f1[5];
		scanf("%s", f1);
		if (f1[0] == 'Y' || f1[0] == 'y')
		{
			printf("\n\t\t\t\t    温馨提示：该成员删除成功 ！             \n\n");
			delNode(L, e);
		}
		save_S(L);
		f = 1;
		Check_Deleteinformation(L);//打印表后是否存在有该人的元素 
	}
	if (f == 0)
	{
		printf("\t\t\t\t\t    温馨提示：该成员信息不存在 ！             \n\n");
	}
}

void Sort_Information(Node* L)   //对文件中的积分进行排序
{
	Node* p, * q, * pre;
	p = L->next->next;
	L->next->next = NULL;
	while (p)
	{
		q = p->next;
		pre = L;
		while ((pre->next != NULL) && (pre->next->student.score < p->student.score))
			pre = pre->next;
		p->next = pre->next;
		pre->next = p;
		p = q;
	}
	Print_Information( L );//排序后输出 
}

void Icrease_numberscore(Node* L)//学生积分的增加 
{
	int f = 0;
	Stu e;
	Node* p = NULL;
	printf("\n请输入成员七位数学号： ");
	scanf("%s", e.num);
	p = getNode(L, e);
	if (p != NULL)
	{
		e = p->student;
		printf("\n");
		printf("\t\t\t\t\t     * 该 成 员 信 息 如 下 *\n\n");
		printf("** 姓名\t     学号\t 性别\t     专业班级\t  年龄\t     积分\t  等级\t   成员加分次数\t   成员减分次数 **\n");
		printf("   %s\t   %s\t  %s\t\t%s\t   %d\t     %.2lf\t   %c\t        %d\t\t  %d \n",
					e.name,
					e.num,
					e.sex,
					e.class1,
					e.age,
					e.score,
					e.grade,
					e.Increase_score,
					e.Deacrease_score
		);
		double increase;
		printf("请输入增加的积分数： ");
		scanf("%lf", &increase);
		e.score += increase;
		e.Increase_score++;
		
		if (e.score >= 80.00) e.grade = 'A';
		else if (e.score >= 70.00 && e.score < 80.00) e.grade = 'B';
		else if (e.score >= 60.00 && e.score < 70.00) e.grade = 'C';
		else e.grade = 'D';
		
		printf("\n\t\t\t\t\t    温馨提示：成员积分添加成功 ！             \n\n");
		printf("\t\t\t\t\t     * 加 分 后 信 息 如 下 *\n\n");
		printf("** 姓名\t     学号\t 性别\t     专业班级\t  年龄\t     积分\t  等级\t   成员加分次数\t   成员减分次数 **\n");
		printf("   %s\t   %s\t  %s\t\t%s\t   %d\t     %.2lf\t   %c\t        %d\t\t  %d \n",
					e.name,
					e.num,
					e.sex,
					e.class1,
					e.age,
					e.score,
					e.grade,
					e.Increase_score,
					e.Deacrease_score
				);
		printf("\n"); 
		p->student = e;
		save_S(L);
		f = 1;
	}
	if (f == 0)
	{
		printf("\t\t\t\t\t    温馨提示：该成员信息不存在 ！             \n\n");
	}
}

void Dcrease_numberscore(Node* L)//学生积分的减少 
{
	int f = 0;
	Stu e;
	Node* p = NULL;
	printf("\n请输入成员的七位数学号： ");
	scanf("%s", e.num);
	p = getNode(L, e);
	if (p != NULL)
	{
		e = p->student;
		printf("\n");
		printf("\t\t\t\t\t     * 该 成 员 信 息 如 下 *\n\n");
		printf("** 姓名\t     学号\t 性别\t     专业班级\t  年龄\t     积分\t  等级\t   成员加分次数\t   成员减分次数 **\n");
		printf("   %s\t   %s\t  %s\t\t%s\t   %d\t     %.2lf\t   %c\t        %d\t\t  %d \n",
					e.name,
					e.num,
					e.sex,
					e.class1,
					e.age,
					e.score,
					e.grade,
					e.Increase_score,
					e.Deacrease_score
			);
		double deacrease;
		printf("请输入减少的积分数： ");
		scanf("%lf", &deacrease);
		e.score += deacrease;
		e.Deacrease_score++;
		
		if (e.score >= 80.00) e.grade = 'A';
		else if (e.score >= 70.00 && e.score < 80.00) e.grade = 'B';
		else if (e.score >= 60.00 && e.score < 70.00) e.grade = 'C';
		else e.grade = 'D';

		printf("\n\t\t\t\t\t    温馨提示：该成员积分减少成功 ！             \n\n");
		printf("\t\t\t\t\t     * 减 分 后 信 息 如 下 *\n\n");
		printf("** 姓名\t     学号\t 性别\t     专业班级\t  年龄\t     积分\t  等级\t   成员加分次数\t   成员减分次数 **\n");
		printf("   %s\t   %s\t  %s\t\t%s\t   %d\t     %.2lf\t   %c\t        %d\t\t  %d \n",
					e.name,
					e.num,
					e.sex,
					e.class1,
					e.age,
					e.score,
					e.grade,
					e.Increase_score,
					e.Deacrease_score
				);
		p->student = e;
		save_S(L);
		f = 1;
	}
	if (f == 0)
	{
		printf("\t\t\t\t\t    温馨提示：该成员信息不存在 ！             \n\n");
	}
}

void Revise_information(Node* L)//学生积分的修改 
{
	int f = 0;
	Stu e;
	Node* p = NULL;
	printf("\n请输入成员的七位数学号： ");
	scanf("%s", e.num);
	p = getNode(L, e);
	if (p != NULL)
	{
		e = p->student;
		printf("\n请输入修改后的积分:  ");
		scanf("%lf", &e.score);
		e.Deacrease_score = 0;
		e.Increase_score = 0;
		
		if (e.score >= 80.00) e.grade = 'A';
		else if (e.score >= 70.00 && e.score < 80.00) e.grade = 'B';
		else if (e.score >= 60.00 && e.score < 70.00) e.grade = 'C';
		else e.grade = 'D';

		printf("\t\t\t\t\t    温馨提示：该成员积分修改成功 ！             \n\n");
		p->student = e;
		save_S(L);
		f = 1;
	}
	if (f == 0)
	{
		printf("\t\t\t\t\t    温馨提示：该成员信息不存在 ！             \n\n");
	}
}

void Average_value(Node* L)//全部学生积分的平均值 
{
	double score = 0;
	Node* p = L->next;
	while ( p )
	{
		score += p->student.score;
		p = p->next;
	}
	printf("\n\t\t\t\t\t    全部成员积分的平均值是: %.2lf\n", score / getLength(L));
}

void Studentsgrade_management(Node *L) //成员等级管理 
{
	int op;
	while (true)
	{
		system("cls");
		printf("\n");
		printf("\t\t\t\t\t     * 成 员 等 级 管 理  *\n\n");
		printf("\t\t\t\t\t       1、成员积分的添加\n\n");
		printf("\t\t\t\t\t       2、成员积分的减少\n\n");
		printf("\t\t\t\t\t       3、成员积分的修改\n\n");
		printf("\t\t\t\t\t       4、全部成员积分的平均值\n\n");
		printf("\t\t\t\t\t       5、全部成员积分的排序\n\n");
		printf("\t\t\t\t\t       6、返回上一界面\n\n\n");

		system("cls");
		printf("\n\n\n");
		printf("\t\t\t\t ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇\n");
		printf("\t\t\t\t ▇                                                         ▇\n");
		printf("\t\t\t\t ▇  欢 迎 使 用 江 西 财 经 大 学 社 团 成 员 等 级  管 理 ▇\n");
		printf("\t\t\t\t ▇                                                         ▇\n");
		printf("\t\t\t\t ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇\n");
		printf("\n\n\n");
		printf("\t\t\t\t    1.成员积分的添加          2.成员积分的减少       \n\n");
		printf("\t\t\t\t    3.成员积分的修改          4.全部成员积分的平均值             \n\n");
		printf("\t\t\t\t    5.全部成员积分的排序      6.返回上一界面             \n\n\n");

		printf("请选择功能：");
		scanf("%d", &op);
		switch (op)// 通过输入数据，调用其他函数 
		{
			case 1:
				Icrease_numberscore(L);//学生积分的增加 
				system("pause");
				break;
			case 2:
				Dcrease_numberscore(L);//学生积分的减少 
				system("pause");
				break;
			case 3:
				Revise_information(L);//学生积分的修改 
				system("pause");
				break;
			case 4:
				Average_value(L);//全部学生积分的平均值 
				system("pause");
				break;
			case 5:
				Sort_Information(L);//根据积分进行排序并且输出 上面已经实现 
				system("pause");
				break;
			case 6:
				Main_Menu();
			default:
				printf("输入错误，请重新输入！");
				system("pause");
		}
	}
}

void AddressBook_management(Node* L) //（通讯录管理）
{
	int op;	 
	while (true)
	{
		system("cls");
		printf("\n\n\n");
		printf("\t\t\t\t ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇\n");
		printf("\t\t\t\t ▇                                                           ▇\n");
		printf("\t\t\t\t ▇  欢 迎 使 用 江 西 财 经 大 学 社 团 成 员 通 讯 录 管 理 ▇\n");
		printf("\t\t\t\t ▇                                                           ▇\n");
		printf("\t\t\t\t ▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇▇\n");
		printf("\n\n\n");
		printf("\t\t\t\t    1.成员信息的录入          2.成员信息的查询       \n\n");
		printf("\t\t\t\t    3.成员信息的修改          4.成员信息的删除             \n\n");
		printf("\t\t\t\t    5.成员积分排序            6.退出             \n\n");
		printf("\n\n");
		printf("\t\t\t\t    温馨提示：先录入学生信息才能进行其他操作哦 ！             \n\n");
		
		printf("请选择功能：");
		scanf("%d", &op);
		switch (op) // 通过输入数据，调用其他函数
		{
			case 1:
				Add_management(L); //学生信息的录入
				system("pause");
				break;
			case 2:
				Check_Information(L);//学生信息的查询
				system("pause");
				break;
			case 3:
				Modify_Information(L);//学生信息的修改
				system("pause");
				break;
			case 4:
				Delete_Information(L);//学生信息的删除并且输出
				system("pause");
				break;
			case 5:
				Sort_Information(L);//根据积分进行排序并且输出
				system("pause");
				break;
			case 6:
				Main_Menu();
				return;
			default:
				printf("输入错误，请重新输入！");
				system("pause");
		}
	}
}

void Main_Menu() {//主菜单
	system("cls");
	printf("***************************************************************************************\n");
	printf("            欢迎使用江西财经大学软件与物联网工程学院社团管理系统\n");
	printf("***************************************************************************************\n");
	printf("------------成员信息管理------------\n");
	printf("   1 通讯录管理\n");
	printf("   2 成员等级管理\n");
	printf("------------社团信息管理------------\n");
	printf("   3 \n");
	printf("   4 \n");
	printf("------------社团活动管理------------\n");
	printf("   5 \n");
	printf("   6 \n");
	printf("------------------------------------\n");
	printf("   7 退出\n");
	printf("*****************************************************************************************\n");
	printf("请选择功能(1-7)：");
	int operation;
	Node* L = initNode(); //创建成员信息节点
	load_S(L);
	scanf("%d", &operation);
	switch (operation)
	{
		case 1:
			AddressBook_management(L);//通讯录管理
			break;
		case 2:
		    Studentsgrade_management(L);//成员等级管理
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:          // 退出系统
			exit(0);
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
	}
	system("pause"); // 暂停
	system("cls");
}

int main()//主函数 
{
	while (true) Main_Menu();
	
	return 0;
}

Node* initNode() //创建成员信息节点
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	return L;
}

void insertNode(Node* L, Stu e)//添加成员信息节点
{
	Node* p = L;
	Node* n = initNode(); //创建成员信息节点

	n->student = e;
	while (p->next) p = p->next;
	p->next = n;
}

void delNode(Node* L, Stu e) //删除成员信息节点
{
	Node* p = L;
	Node* del = NULL; //创建成员信息节点

	while (p->next)
	{
		if (strcmp(p->next->student.num, e.num) == 0)
		{
			del = p->next;
			p->next = p->next->next;
			free(del);
			return;
		}
		p = p->next;
	}
}

Node* getNode(Node* L, Stu e)//根据成员学号得到节点
{
	Node* p = L;

	while (p->next)
	{
		if (strcmp(p->next->student.num, e.num) == 0) break;
		p = p->next;
	}
	return p->next;
}

int getLength(Node* L)//得到成员信息的个数
{
	Node* p = L;
	int count = 0;
	while (p->next)
	{
		count++;
		p = p->next;
	}
	return count;
}

void load_S(Node* L)//导入文件中成员信息节点
{
	FILE* fp;
	Stu e;
	if ((fp = fopen("STU", "rb")) == NULL) return;
	while ((fread(&e, sizeof(Stu), 1, fp)) != 0) insertNode(L, e);
	fclose(fp);
}

void save_S(Node* L)//保存成员信息节点到文件中
{
	FILE* fp;
	Node* p = L->next;

	if ((fp = fopen("STU", "wb")) == NULL)
	{
		printf("文件打开失败\n");
		exit(0);
	}
	while (p)
	{
		fwrite(&(p->student), sizeof(Stu), 1, fp);
		p = p->next;
	}
	fclose(fp);
}
