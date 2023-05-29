#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <windows.h>

void Main_Menu();
void AddressBook_management();

// ��Ա��Ϣ
typedef struct student
{
	char name[10];//����
	char num[30];//ѧ�� 
	char sex[5];//�Ա� 
	char class1[20];//רҵ�༶
	int age;//���� 
	double score;//���� 
	char grade;//�����ȼ�
	int Increase_score;//ѧ����ӻ��ֵĴ���
	int Deacrease_score;//ѧ�����ٻ��ֵĴ���  
}Stu;

// �����Ϣ
typedef struct _Node
{
	Stu student;
	struct _Node* next;
}Node;

void Sort_Information(Node* L);
Node* initNode(); //������Ա��Ϣ�ڵ�
void insertNode(Node* L, Stu e);//��ӳ�Ա��Ϣ�ڵ�
void delNode(Node* L, Stu e); //ɾ����Ա��Ϣ�ڵ�
Node* getNode(Node* L, Stu e);//���ݳ�Աѧ�ŵõ��ڵ�
int getLength(Node* L);//�õ���Ա��Ϣ�ĸ���
void load_S(Node* L);//�����ļ��г�Ա��Ϣ�ڵ�
void save_S(Node* L);//�����Ա��Ϣ�ڵ㵽�ļ���
void AddressBook_management(Node* L);//��Ա��Ϣ�Ĺ��� 
void AddressBook_management(Node* L);

void Add_management(Node* L)//ѧ����Ϣ��¼�� 
{
	char f[10];
	Stu e;

	while (true)
	{
		printf("\n"); 
		printf("�������Ա�������� ");
		scanf("%s", e.name);

		printf("�������Ա����λ��ѧ�ţ� ");
		scanf("%s", e.num);

		printf("�������Ա���Ա� ");
		scanf("%s", e.sex);

		printf("�������Ա��רҵ�༶�� ");
		scanf("%s", e.class1);

		printf("�������Ա�����䣺 ");
		scanf("%d", &e.age);

		printf("�������Ա�Ļ��֣� ");
		scanf("%lf", &e.score);

		if (e.score >= 80.00) e.grade = 'A';
		else if (e.score >= 70.00 && e.score < 80.00) e.grade = 'B';
		else if (e.score >= 60.00 && e.score < 70.00) e.grade = 'C';
		else e.grade = 'D';
		
		e.Increase_score = 0;//ѧ����ӻ��ֵĴ���
		e.Deacrease_score = 0;//ѧ�����ٻ��ֵĴ���  

		insertNode(L, e);
		printf("\n\t\t\t\t\t    �Ƿ�������룿(y/n):  ");
		scanf("%s", f);
		if (f[0] == 'n' || f[0] == 'N')  break; //�ж��Ƿ��˳�
	}
	printf("\n\t\t\t\t\t    ��ܰ��ʾ���ó�Ա��Ϣ¼��ɹ� ��             \n\n");
	save_S(L);//�����Ա��Ϣ�ڵ㵽�ļ���
}

void Print_Information(Node* L)//��ӡ�ļ������г�Ա����Ϣ 
{
	system("cls"); // ����
	printf("\n");
	printf("\t\t\t\t\t     * �� Ա �� Ϣ չ ʾ  *\n\n");
	printf("** ����\t     ѧ��\t �Ա�\t     רҵ�༶\t  ����\t     ����\t  �ȼ�\t   ��Ա�ӷִ���\t   ��Ա���ִ��� **\n");

	// ��������
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

void Check_Deleteinformation(Node* L)//��ӡ�ļ������г�Ա����Ϣ 
{
	printf("\n");
	printf("\t\t\t\t\t     * �� Ա �� Ϣ չ ʾ  *\n\n");
	printf("** ����\t     ѧ��\t �Ա�\t     רҵ�༶\t  ����\t     ����\t  �ȼ�\t   ��Ա�ӷִ���\t   ��Ա���ִ��� **\n");

	// ��������
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

void Check_Information(Node* L)//ѧ����Ϣ��ѯ 
{
	int op,f;
	char na[15];
	char nu[15];
	while (true)
	{
		system("cls");
		printf("\n");
		printf("\t\t\t\t\t     * �� Ա �� Ϣ �� �� ѯ *\n\n");
		printf("\t\t\t\t\t       1��ȫ����Ա�����\n\n");
		printf("\t\t\t\t\t       2�����������\n\n");
		printf("\t\t\t\t\t       3����ѧ�����\n\n");
		printf("\t\t\t\t\t       4��������һ����\n\n\n");

		printf("��ѡ���ܣ� ");
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
			printf("������������ ");
			scanf("%s", na);
			printf("\n");
			printf("\t\t\t\t\t     * �� �� Ա �� Ϣ �� �� *\n\n");
			printf("** ����\t     ѧ��\t �Ա�\t     רҵ�༶\t  ����\t     ����\t  �ȼ�\t   ��Ա�ӷִ���\t   ��Ա���ִ��� **\n");
			Node* temp1 = L->next;
			while (temp1 != NULL)
			{
				if (strcmp(na, temp1->student.name) == 0)//strcmp�ж��ַ����Ƿ�ƥ�� 
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
				printf("\t\t\t\t\t    ��ܰ��ʾ���ó�Ա��Ϣ������ ��             \n\n");
			}
			system("pause");
		}
		else if (op == 3)
		{
			f = 0;
			printf("\n");
			printf("��������λ��ѧ�ţ� ");
			scanf("%s", nu);
			printf("\n");
			printf("\t\t\t\t\t     * �� �� Ա �� Ϣ �� �� *\n\n");
			printf("** ����\t     ѧ��\t �Ա�\t     רҵ�༶\t  ����\t     ����\t  �ȼ�\t   ��Ա�ӷִ���\t   ��Ա���ִ��� **\n");
			Node* temp2 = L->next;
			while (temp2 != NULL)
			{
				if (strcmp(nu, temp2->student.num) == 0)//strcmp�ж��ַ����Ƿ�ƥ�� 
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
				printf("\t\t\t\t\t    ��ܰ��ʾ���ó�Ա��Ϣ������ ��             \n\n");
			}
			system("pause");
		}
		else AddressBook_management(L);
	}
}

void Modify_Information(Node* L)     //ѧ����Ϣ���޸Ĳ��ұ��浽�ļ��� 
{
	int k;
	Stu e;
	Node* p = NULL;

	printf("\n��������λ��ѧ�ţ� ");
	scanf("%s", e.num);
	p = getNode(L, e);

	if (p == NULL)
	{
		printf("\t\t\t\t\t    ��ܰ��ʾ���ó�Ա��Ϣ������ ��             \n\n");
		return;
	}
	e = p->student;
	printf("\n");
	printf("\t\t\t\t\t     * �� �� Ա �� Ϣ �� �� *\n\n");
	printf("** ����\t     ѧ��\t �Ա�\t     רҵ�༶\t  ����\t     ����\t  �ȼ�\t   ��Ա�ӷִ���\t   ��Ա���ִ��� **\n");
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
	printf("\t\t\t\t\t     * �� Ա �� Ϣ �� �� �� *\n\n");
	printf("\t\t\t\t\t       1���޸ĳ�Ա������\n\n");
	printf("\t\t\t\t\t       2���޸ĳ�Ա��ѧ��\n\n");
	printf("\t\t\t\t\t       3���޸ĳ�Ա��רҵ�༶\n\n");
	printf("\t\t\t\t\t       4���޸ĳ�Ա������\n\n");
	printf("\t\t\t\t\t       5��������һҳ��\n\n\n");
		
	printf("������Ҫ�޸ĵĵط��� ");
	scanf("%d", &k);
	if (k == 1)
	{
		printf("\n�������޸ĺ������� ");
		scanf("%s", e.name);
	}
	else if (k == 2)
	{
		printf("\n�������޸ĺ�ѧ�ţ� ");
		scanf("%s", e.num);
	}
	else if (k == 3)
	{
		printf("\n�������޸ĺ�רҵ�༶�� ");
		scanf("%s", e.class1);
	}
	else if (k == 4)
	{
		printf("\n�������޸ĺ����䣺 ");
		scanf("%d", &e.age);
	}
	else AddressBook_management(L);

	p->student = e;
	printf("\t\t\t\t\t    ��ܰ��ʾ���ó�Ա��Ϣ�޸ĳɹ� ��             \n\n");
	printf("\t\t\t\t\t     * �� �� Ա �� �� �� �� Ϣ ����*\n\n");
	printf("** ����\t     ѧ��\t �Ա�\t     רҵ�༶\t  ����\t     ����\t  �ȼ�\t   ��Ա�ӷִ���\t   ��Ա���ִ��� **\n");
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

void Delete_Information(Node* L)     //���ļ��н���ѧ����Ϣ��ɾ�� 
{
	int f = 0;
	Stu e;
	printf("\n");
	printf("��������Ҫɾ����Ա����λ��ѧ�ţ� ");
	scanf("%s", e.num);
	if (getNode(L, e) != NULL)
	{
		printf("\n\t\t\t\t    ���ҵ����ݣ��Ƿ�ɾ����(y/n)�� ");
		char f1[5];
		scanf("%s", f1);
		if (f1[0] == 'Y' || f1[0] == 'y')
		{
			printf("\n\t\t\t\t    ��ܰ��ʾ���ó�Աɾ���ɹ� ��             \n\n");
			delNode(L, e);
		}
		save_S(L);
		f = 1;
		Check_Deleteinformation(L);//��ӡ����Ƿ�����и��˵�Ԫ�� 
	}
	if (f == 0)
	{
		printf("\t\t\t\t\t    ��ܰ��ʾ���ó�Ա��Ϣ������ ��             \n\n");
	}
}

void Sort_Information(Node* L)   //���ļ��еĻ��ֽ�������
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
	Print_Information( L );//�������� 
}

void Icrease_numberscore(Node* L)//ѧ�����ֵ����� 
{
	int f = 0;
	Stu e;
	Node* p = NULL;
	printf("\n�������Ա��λ��ѧ�ţ� ");
	scanf("%s", e.num);
	p = getNode(L, e);
	if (p != NULL)
	{
		e = p->student;
		printf("\n");
		printf("\t\t\t\t\t     * �� �� Ա �� Ϣ �� �� *\n\n");
		printf("** ����\t     ѧ��\t �Ա�\t     רҵ�༶\t  ����\t     ����\t  �ȼ�\t   ��Ա�ӷִ���\t   ��Ա���ִ��� **\n");
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
		printf("���������ӵĻ������� ");
		scanf("%lf", &increase);
		e.score += increase;
		e.Increase_score++;
		
		if (e.score >= 80.00) e.grade = 'A';
		else if (e.score >= 70.00 && e.score < 80.00) e.grade = 'B';
		else if (e.score >= 60.00 && e.score < 70.00) e.grade = 'C';
		else e.grade = 'D';
		
		printf("\n\t\t\t\t\t    ��ܰ��ʾ����Ա������ӳɹ� ��             \n\n");
		printf("\t\t\t\t\t     * �� �� �� �� Ϣ �� �� *\n\n");
		printf("** ����\t     ѧ��\t �Ա�\t     רҵ�༶\t  ����\t     ����\t  �ȼ�\t   ��Ա�ӷִ���\t   ��Ա���ִ��� **\n");
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
		printf("\t\t\t\t\t    ��ܰ��ʾ���ó�Ա��Ϣ������ ��             \n\n");
	}
}

void Dcrease_numberscore(Node* L)//ѧ�����ֵļ��� 
{
	int f = 0;
	Stu e;
	Node* p = NULL;
	printf("\n�������Ա����λ��ѧ�ţ� ");
	scanf("%s", e.num);
	p = getNode(L, e);
	if (p != NULL)
	{
		e = p->student;
		printf("\n");
		printf("\t\t\t\t\t     * �� �� Ա �� Ϣ �� �� *\n\n");
		printf("** ����\t     ѧ��\t �Ա�\t     רҵ�༶\t  ����\t     ����\t  �ȼ�\t   ��Ա�ӷִ���\t   ��Ա���ִ��� **\n");
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
		printf("��������ٵĻ������� ");
		scanf("%lf", &deacrease);
		e.score += deacrease;
		e.Deacrease_score++;
		
		if (e.score >= 80.00) e.grade = 'A';
		else if (e.score >= 70.00 && e.score < 80.00) e.grade = 'B';
		else if (e.score >= 60.00 && e.score < 70.00) e.grade = 'C';
		else e.grade = 'D';

		printf("\n\t\t\t\t\t    ��ܰ��ʾ���ó�Ա���ּ��ٳɹ� ��             \n\n");
		printf("\t\t\t\t\t     * �� �� �� �� Ϣ �� �� *\n\n");
		printf("** ����\t     ѧ��\t �Ա�\t     רҵ�༶\t  ����\t     ����\t  �ȼ�\t   ��Ա�ӷִ���\t   ��Ա���ִ��� **\n");
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
		printf("\t\t\t\t\t    ��ܰ��ʾ���ó�Ա��Ϣ������ ��             \n\n");
	}
}

void Revise_information(Node* L)//ѧ�����ֵ��޸� 
{
	int f = 0;
	Stu e;
	Node* p = NULL;
	printf("\n�������Ա����λ��ѧ�ţ� ");
	scanf("%s", e.num);
	p = getNode(L, e);
	if (p != NULL)
	{
		e = p->student;
		printf("\n�������޸ĺ�Ļ���:  ");
		scanf("%lf", &e.score);
		e.Deacrease_score = 0;
		e.Increase_score = 0;
		
		if (e.score >= 80.00) e.grade = 'A';
		else if (e.score >= 70.00 && e.score < 80.00) e.grade = 'B';
		else if (e.score >= 60.00 && e.score < 70.00) e.grade = 'C';
		else e.grade = 'D';

		printf("\t\t\t\t\t    ��ܰ��ʾ���ó�Ա�����޸ĳɹ� ��             \n\n");
		p->student = e;
		save_S(L);
		f = 1;
	}
	if (f == 0)
	{
		printf("\t\t\t\t\t    ��ܰ��ʾ���ó�Ա��Ϣ������ ��             \n\n");
	}
}

void Average_value(Node* L)//ȫ��ѧ�����ֵ�ƽ��ֵ 
{
	double score = 0;
	Node* p = L->next;
	while ( p )
	{
		score += p->student.score;
		p = p->next;
	}
	printf("\n\t\t\t\t\t    ȫ����Ա���ֵ�ƽ��ֵ��: %.2lf\n", score / getLength(L));
}

void Studentsgrade_management(Node *L) //��Ա�ȼ����� 
{
	int op;
	while (true)
	{
		system("cls");
		printf("\n");
		printf("\t\t\t\t\t     * �� Ա �� �� �� ��  *\n\n");
		printf("\t\t\t\t\t       1����Ա���ֵ����\n\n");
		printf("\t\t\t\t\t       2����Ա���ֵļ���\n\n");
		printf("\t\t\t\t\t       3����Ա���ֵ��޸�\n\n");
		printf("\t\t\t\t\t       4��ȫ����Ա���ֵ�ƽ��ֵ\n\n");
		printf("\t\t\t\t\t       5��ȫ����Ա���ֵ�����\n\n");
		printf("\t\t\t\t\t       6��������һ����\n\n\n");

		system("cls");
		printf("\n\n\n");
		printf("\t\t\t\t �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("\t\t\t\t �~                                                         �~\n");
		printf("\t\t\t\t �~  �� ӭ ʹ �� �� �� �� �� �� ѧ �� �� �� Ա �� ��  �� �� �~\n");
		printf("\t\t\t\t �~                                                         �~\n");
		printf("\t\t\t\t �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("\n\n\n");
		printf("\t\t\t\t    1.��Ա���ֵ����          2.��Ա���ֵļ���       \n\n");
		printf("\t\t\t\t    3.��Ա���ֵ��޸�          4.ȫ����Ա���ֵ�ƽ��ֵ             \n\n");
		printf("\t\t\t\t    5.ȫ����Ա���ֵ�����      6.������һ����             \n\n\n");

		printf("��ѡ���ܣ�");
		scanf("%d", &op);
		switch (op)// ͨ���������ݣ������������� 
		{
			case 1:
				Icrease_numberscore(L);//ѧ�����ֵ����� 
				system("pause");
				break;
			case 2:
				Dcrease_numberscore(L);//ѧ�����ֵļ��� 
				system("pause");
				break;
			case 3:
				Revise_information(L);//ѧ�����ֵ��޸� 
				system("pause");
				break;
			case 4:
				Average_value(L);//ȫ��ѧ�����ֵ�ƽ��ֵ 
				system("pause");
				break;
			case 5:
				Sort_Information(L);//���ݻ��ֽ������������ �����Ѿ�ʵ�� 
				system("pause");
				break;
			case 6:
				Main_Menu();
			default:
				printf("����������������룡");
				system("pause");
		}
	}
}

void AddressBook_management(Node* L) //��ͨѶ¼����
{
	int op;	 
	while (true)
	{
		system("cls");
		printf("\n\n\n");
		printf("\t\t\t\t �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("\t\t\t\t �~                                                           �~\n");
		printf("\t\t\t\t �~  �� ӭ ʹ �� �� �� �� �� �� ѧ �� �� �� Ա ͨ Ѷ ¼ �� �� �~\n");
		printf("\t\t\t\t �~                                                           �~\n");
		printf("\t\t\t\t �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("\n\n\n");
		printf("\t\t\t\t    1.��Ա��Ϣ��¼��          2.��Ա��Ϣ�Ĳ�ѯ       \n\n");
		printf("\t\t\t\t    3.��Ա��Ϣ���޸�          4.��Ա��Ϣ��ɾ��             \n\n");
		printf("\t\t\t\t    5.��Ա��������            6.�˳�             \n\n");
		printf("\n\n");
		printf("\t\t\t\t    ��ܰ��ʾ����¼��ѧ����Ϣ���ܽ�����������Ŷ ��             \n\n");
		
		printf("��ѡ���ܣ�");
		scanf("%d", &op);
		switch (op) // ͨ���������ݣ�������������
		{
			case 1:
				Add_management(L); //ѧ����Ϣ��¼��
				system("pause");
				break;
			case 2:
				Check_Information(L);//ѧ����Ϣ�Ĳ�ѯ
				system("pause");
				break;
			case 3:
				Modify_Information(L);//ѧ����Ϣ���޸�
				system("pause");
				break;
			case 4:
				Delete_Information(L);//ѧ����Ϣ��ɾ���������
				system("pause");
				break;
			case 5:
				Sort_Information(L);//���ݻ��ֽ������������
				system("pause");
				break;
			case 6:
				Main_Menu();
				return;
			default:
				printf("����������������룡");
				system("pause");
		}
	}
}

void Main_Menu() {//���˵�
	system("cls");
	printf("***************************************************************************************\n");
	printf("            ��ӭʹ�ý����ƾ���ѧ���������������ѧԺ���Ź���ϵͳ\n");
	printf("***************************************************************************************\n");
	printf("------------��Ա��Ϣ����------------\n");
	printf("   1 ͨѶ¼����\n");
	printf("   2 ��Ա�ȼ�����\n");
	printf("------------������Ϣ����------------\n");
	printf("   3 \n");
	printf("   4 \n");
	printf("------------���Ż����------------\n");
	printf("   5 \n");
	printf("   6 \n");
	printf("------------------------------------\n");
	printf("   7 �˳�\n");
	printf("*****************************************************************************************\n");
	printf("��ѡ����(1-7)��");
	int operation;
	Node* L = initNode(); //������Ա��Ϣ�ڵ�
	load_S(L);
	scanf("%d", &operation);
	switch (operation)
	{
		case 1:
			AddressBook_management(L);//ͨѶ¼����
			break;
		case 2:
		    Studentsgrade_management(L);//��Ա�ȼ�����
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		case 6:
			break;
		case 7:          // �˳�ϵͳ
			exit(0);
			break;
		default:
			printf("�����������������\n");
			break;
	}
	system("pause"); // ��ͣ
	system("cls");
}

int main()//������ 
{
	while (true) Main_Menu();
	
	return 0;
}

Node* initNode() //������Ա��Ϣ�ڵ�
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	return L;
}

void insertNode(Node* L, Stu e)//��ӳ�Ա��Ϣ�ڵ�
{
	Node* p = L;
	Node* n = initNode(); //������Ա��Ϣ�ڵ�

	n->student = e;
	while (p->next) p = p->next;
	p->next = n;
}

void delNode(Node* L, Stu e) //ɾ����Ա��Ϣ�ڵ�
{
	Node* p = L;
	Node* del = NULL; //������Ա��Ϣ�ڵ�

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

Node* getNode(Node* L, Stu e)//���ݳ�Աѧ�ŵõ��ڵ�
{
	Node* p = L;

	while (p->next)
	{
		if (strcmp(p->next->student.num, e.num) == 0) break;
		p = p->next;
	}
	return p->next;
}

int getLength(Node* L)//�õ���Ա��Ϣ�ĸ���
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

void load_S(Node* L)//�����ļ��г�Ա��Ϣ�ڵ�
{
	FILE* fp;
	Stu e;
	if ((fp = fopen("STU", "rb")) == NULL) return;
	while ((fread(&e, sizeof(Stu), 1, fp)) != 0) insertNode(L, e);
	fclose(fp);
}

void save_S(Node* L)//�����Ա��Ϣ�ڵ㵽�ļ���
{
	FILE* fp;
	Node* p = L->next;

	if ((fp = fopen("STU", "wb")) == NULL)
	{
		printf("�ļ���ʧ��\n");
		exit(0);
	}
	while (p)
	{
		fwrite(&(p->student), sizeof(Stu), 1, fp);
		p = p->next;
	}
	fclose(fp);
}
