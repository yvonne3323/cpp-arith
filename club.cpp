//框架是分开负责人的界面:高校社团负责人或管理人员；高校校方社团管理机构负责人
while(ture){
    if(user_type == "club_leader"){
        club_leader_interface();
    }
    else if(user_type == "school_leader"){
        school_leader_interface();
    }
    else{
        cout << "Error: user_type is not defined!" << endl;
    }
}

//我有一个文件是包括这些数据的
{
//分开这些数据的方法是

// # 学生信息 选择了成员信息的第二项，即学生有积分和等级 不知道学号是否有用
// 20210001 张三
// 20210002 李四
// ...

// # 社团信息 社团名称，口号，宗旨，章程，发起人，社团性质等信息
// 001 乒乓球协会
// 002 篮球协会
// ...

// # 活动信息
// 001 2021-05-01 乒乓球比赛
// 002 2021-05-03 篮球训练
// ...

// # 赞助商信息
}
//疑惑点：1.社团信息有点多怎么分，还是全分开
//2.社团信息和活动信息是一对多的关系，怎么分开
//社团信息和赞助商信息是多对多的关系，怎么分开
//4.第三大点还需要文件吗
//

//成员是否需要嵌套
//非嵌套
{
// 成员数据结构
typedef struct {
    int id;                 // 成员编号
    char name[20];          // 成员姓名
    int level;              // 成员等级
    int score;              // 成员积分
} Member;

// 社团基本信息数据结构
typedef struct {
    int id;                 // 社团编号
    char name[50];          // 社团名称
    char slogan[100];       // 社团口号
    char aim[200];          // 社团宗旨
    char charter[200];      // 社团章程
    char founder[20];       // 社团发起人
    char nature[20];        // 社团性质
} Club;

// 赞助商数据结构
typedef struct {
    int id;                 // 赞助商编号
    char name[100];         // 赞助商名称
    char contact[20];       // 赞助商联系人
    char phone[20];         // 赞助商电话
    char email[20];         // 赞助商电邮
    char introduction[200]; // 赞助商介绍
    //赞助商与社团关系的管理
} Sponsor;

// 活动数据结构 是否需要
typedef struct {
    int id;                 // 活动编号
    char name[100];         // 活动名称
    char organizer[20];     // 活动组织者
    char start[20];         // 活动开始时间
    char end[20];           // 活动结束时间
    char address[100];      // 活动地点
} Activity;

}
//读写函数
{
    void read_data_from_file(string filename, vector<Student>& students, vector<Club>& clubs, vector<Activity>& activities) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open file " << filename << endl;
        return;
    }

    string line;
    string type;
    while (getline(file, line)) {
        if (line.empty()) {
            continue;
        }

        if (line[0] == '#') {
            type = line.substr(2);
            continue;
        }

        istringstream iss(line);
        if (type == "学生信息") {
            Student student;
            iss >> student.id >> student.name;
            students.push_back(student);
        } else if (type == "社团信息") {
            Club club;
            iss >> club.id >> club.name;
            clubs.push_back(club);
        } else if (type == "活动信息") {
            Activity activity;
            iss >> activity.id >> activity.date >> activity.name;
            activities.push_back(activity);
        }
    }

    file.close();
}

void write_data_to_file(string filename, const vector<Student>& students, const vector<Club>& clubs, const vector<Activity>& activities) {
    ofstream file(filename);
    if (!file) {
        cerr << "Failed to open file " << filename << endl;
        return;
    }

    file << "# 学生信息\n";
    for (auto student : students) {
        file << student.id << " " << student.name << endl;
    }

    file << "\n# 社团信息\n";
    for (auto club : clubs) {
        file << club.id << " " << club.name << endl;
    }

    file << "\n# 活动信息\n";
    for (auto activity : activities) {
        file << activity.id << " " << activity.date << " " << activity.name << endl;
    }

    file.close();
}

}
//嵌套
{
    struct Member { // 社团成员
    string name; // 姓名
    string gender; // 性别
    string contact; // 联系方式
    string major; // 专业
    vector<string> tags; // 标签
};

struct Activity { // 社团活动
    string name; // 活动名称
    string date; // 活动日期
    string time; // 活动时间
    string location; // 活动地点
    string organizer; // 组织者
    string intro; // 活动简介
    vector<string> tags; // 标签
};

struct Club { // 社团
    string name; // 社团名称
    string category; // 社团类别
    string intro; // 社团简介
    vector<Member> members; // 社团成员
    vector<Activity> activities; // 社团活动
};

}
//还不是特别熟悉vector的用法,不太确定是否为嵌套

//数据的修改部分结构体：成员积分，社团信息/活动信息，赞助商信息

//eg函数取名
{
// 1 读取活动信息文件并生成活动链表：loadActivities(FILE* file, ActivityList* list)
// 2 新增活动：insertActivity(ActivityList* list, Activity activity)
// 3 删除活动：deleteActivity(ActivityList* list, int id)
// 4 修改活动：updateActivity(ActivityList* list, Activity activity)
// 5 查询活动：findActivity(ActivityList* list, int id)
// 6 活动评分：scoreActivity(ActivityList* list, int id, int score)
}
//提醒了我主题：链表变文件，文件变链表

//一个结构体所对对应的文件读写
{
    #include <stdio.h>
#include <stdlib.h>

// 从文件中读取数据到结构体中
void loadDataFromFile(char* filename, Data* data) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }
    fread(data, sizeof(Data), 1, fp);
    fclose(fp);
}

// 将结构体中的数据写入到文件中
void saveDataToFile(char* filename, Data* data) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Failed to open file %s\n", filename);
        exit(1);
    }
    fwrite(data, sizeof(Data), 1, fp);
    fclose(fp);
}
}

//我所涉及的文件操作
{
    //打开文件
    //写入文件
    //读取文件
    //文件定位
    //关闭文件
}

//文件变链表
{

// 定义链表结构
typedef struct node {
    char data;              // 存储读取的数据
    struct node* next;      // 指向下一个节点的指针
} Node;

int main() {
    // 打开文件，读取二进制数据
    FILE *fp;
    fp = fopen("file.bin", "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // 创建链表并读取文件
    Node *head, *p;
    head = (Node *)malloc(sizeof(Node));
    p = head;

    while (!feof(fp)) {
        p->next = (Node *)malloc(sizeof(Node));     // 创建新节点
        fread(&p->next->data, sizeof(char), 1, fp);  // 读取数据
        p = p->next;                                // 移动指针到下一个节点
    }
    p->next = NULL;                                 // 链表结束

    // 关闭文件
    fclose(fp);

    // 对链表进行操作
    // ...

    // 释放内存
    while (head) {
        p = head->next;
        free(head);
        head = p;
    }

    return 0;
}
}

//一次性打开关闭文件不太好，方法：文件缓存
{
#define MAX_BUF_SIZE 1024

int main() {
    FILE *fp;
    char buf[MAX_BUF_SIZE];     // 文件缓存

    // 打开文件并读入缓存
    fp = fopen("file.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    fread(buf, sizeof(char), MAX_BUF_SIZE, fp);

    // 对缓存进行操作
    // ...

    // 将修改后的缓存写回文件中
    fseek(fp, 0, SEEK_SET);     // 文件指针回到文件开头
    fwrite(buf, sizeof(char), MAX_BUF_SIZE, fp);

    // 关闭文件
    fclose(fp);

    return 0;
}
}

//文件缓存之后
{
#define MAX_BUF_SIZE 1024

typedef struct member {
    int id;
    char name[20];
    char gender[5];
} Member;

// 添加新成员，mem为新增的成员信息
void add_member(char* buf, int* buf_size, Member* mem) {
    // 将数据添加到缓存中
    int len = strlen(buf);
    memcpy(&buf[len], mem, sizeof(Member));
    *buf_size += sizeof(Member);
}

int main() {
    FILE *fp;
    char buf[MAX_BUF_SIZE];             // 文件缓存
    int buf_size;                       // 缓存大小
    Member mem = {1, "张三", "男"};     // 新增成员信息

    // 打开文件并读入缓存
    fp = fopen("file.txt", "r+");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    buf_size = fread(buf, sizeof(char), MAX_BUF_SIZE, fp);

    // 对缓存进行操作
    add_member(buf, &buf_size, &mem);

    // 将修改后的缓存写回文件中
    fseek(fp, 0, SEEK_SET);             // 文件指针回到文件开头
    fwrite(buf, sizeof(char), buf_size, fp);

    // 关闭文件
    fclose(fp);

    return 0;
}
}


//链表变文件
{
   typedef struct node {
    int data;
    struct node *next;
} Node;

int main() {
  FILE *fp;
  Node *head = NULL, *p, *q;
  int size;

  // 将链表读入内存中
  // ...

  // 打开文件
  fp = fopen("file.txt", "wb");
  if (fp == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }

  // 将链表写入文件中
  size = 0;
  p = head;
  while (p) {
    fwrite(&(p->data), sizeof(int), 1, fp);
    p = p->next;
    size++;
  }

  // 关闭文件
  fclose(fp);

  // 释放链表节点的内存
  p = head;
  while (p) {
    q = p->next;
    free(p);
    p = q;
  }

  return 0;
}
}



//第一步：定文件存储方式/结构体如何存储信息，典型的为社团和成员之间的联系
{
    //分别遍历社团信息文件和成员信息文件(补充社团信息)，在每一个遍历到的节点中，查找它对应的社团和成员，并将他们建立起对应关系。
    //或者可以在同一个文件中存储社团和成员的信息，每个节点中同时存储社团和成员的信息
    //前两行的前提是一对一
    //社团和成员
    //一个指针数组来存储成员所属的多个社团
    //在成员节点中使用一个指向社团节点的链表来存储成员所属的多个社团
    //哈希表 (不是特别清楚)
    //嵌套(成员补充社团数量和社团编号？)
}