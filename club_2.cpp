#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Gender {//枚举 性别
    Male,
    Female,
    Unknown
};
//社团
typedef struct ClubNode {
    char name[50];//名称
    char slogan[50];//口号
    char purpose[50];//宗旨
    char charter[50];//章程
    char boss[50];//发起人
    char nature[50];//社团性质
    struct MemberNode *members;
    struct SponsorNode *sponsors;
    struct ClubNode *next;
} ClubNode;

//成员
typedef struct MemberNode {
    char name[50];//姓名
    int age;//年龄
    enum Gender gender;//性别
    int point;//积分
    struct MemberNode *next;
} MemberNode;

//赞助商
typedef struct SponsorNode {
    char name[50];//姓名
    struct SponsorNode *next;
} SponsorNode;



MemberNode *parse_member(char *buffer)//解析成员
{
MemberNode *member = (MemberNode *) malloc(sizeof(MemberNode));
char *token;

//解析姓名
token = strtok(buffer, ",");//
strcpy(member->name, token);

//解析年龄
token = strtok(NULL, ",");
member->age = atoi(token);

//解析性别
token = strtok(NULL, ",");
if (strcmp(token, "Male") == 0)//
 {
    member->gender = Male;
} else if (strcmp(token, "Female") == 0) {
    member->gender = Female;
} else {
    member->gender = Unknown;
}

//解析积分
token = strtok(NULL, ",");
member->point = atoi(token);

return member;
}

SponsorNode *parse_sponsor(char *buffer)//解析赞助商
{
SponsorNode *sponsor = (SponsorNode *) malloc(sizeof(SponsorNode));
char *token;

//解析姓名
token = strtok(buffer, ",");
strcpy(sponsor->name, token);

sponsor->next = NULL;
return sponsor;
}

ClubNode *parse_club(char *buffer) //解析社团
{
    ClubNode *club = (ClubNode *) malloc(sizeof(ClubNode));
    MemberNode *members = NULL;
    SponsorNode *sponsors = NULL;
    char *token;
//社团序号club_001不算入链表,解析跳过社团序号
token = strtok(buffer, "_");
token = strtok(NULL, "_");


//解析名称
token = strtok(buffer, ":");//strtok()函数用于将字符串分割成一个个片段
strcpy(club->name, token);//strcpy()函数用于将字符串复制到另一个字符串

//解析口号
token = strtok(NULL, ":");
strcpy(club->slogan, token);

//解析宗旨
token = strtok(NULL, ":");
strcpy(club->purpose, token);

//解析章程
token = strtok(NULL, ":");
strcpy(club->charter, token);

//解析发起人
token = strtok(NULL, ":");
strcpy(club->boss, token);

//解析社团性质
token = strtok(NULL, ":");
strcpy(club->nature, token);

//解析成员
token = strtok(NULL, ":");
while (token != NULL && strcmp(token, "sponsor") != 0) //strcmp()函数用于比较两个字符串
{
    MemberNode *member = parse_member(token);
    if (members == NULL) {
        members = member;
        club->members = members;
    } else {
        members->next = member;
        members = member;
    }
    token = strtok(NULL, ":");
}

//解析赞助商
while (token != NULL) 
{
    token = strtok(NULL, ":");
    if (token != NULL) {
        SponsorNode *sponsor = parse_sponsor(token);
        if (sponsors == NULL) {
            sponsors = sponsor;
        } else {
            sponsor->next = sponsors;
            sponsors = sponsor;
        }
    }
}

return club;
}

// 打开文件并将数据转换成链表   细节问题
ClubNode *parse_file(const char *filename) 
{
    FILE *f = fopen(filename, "r");
    ClubNode *head = NULL;
    ClubNode *current = NULL;
    char buffer[1000];
    while (fgets(buffer, 1000, f)) //fgets()函数用于从文件中读取一行
    {
        ClubNode *club = parse_club(buffer);
        if (head == NULL) {
            head = club;
            current = club;
        } else {
            current->next = club;
            current = club;
        }
    }
    fclose(f);
    return head;
}

//定义一个函数，解析文件并将数据存入链表中
ClubNode *parse_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {//读取文件失败
        printf("Error opening file!\n");
        return NULL;
    }
    ClubNode *head = NULL;
    ClubNode *current = NULL;
    char line[100];
    while (fgets(line, sizeof(line), file)) {//逐行读取文件
        if (line[0] == '\n') {//跳过空行
            continue;
        }
        if (line[0] == 'c') {//新建一个社团
            ClubNode *club = (ClubNode *)malloc(sizeof(ClubNode));
            sscanf(line, "club_%*d:\n");//读取社团名称
            fgets(line, sizeof(line), file);//读取社团信息
            sscanf(line, "name:%s\n", club->name);
            fgets(line, sizeof(line), file);
            sscanf(line, "slogan:%s\n", club->slogan);
            fgets(line, sizeof(line), file);
            sscanf(line, "purpose:%s\n", club->purpose);
            fgets(line, sizeof(line), file);
            sscanf(line, "charter:%s\n", club->charter);
            fgets(line, sizeof(line), file);
            sscanf(line, "boss:%s\n", club->boss);
            fgets(line, sizeof(line), file);
            sscanf(line, "nature:%s\n", club->nature);
            club->members = NULL;
            club->sponsors = NULL;
            club->next = NULL;
            if (head == NULL) {//链表为空，将新建的社团设为头节点
                head = club;
            } else {//链表不为空，将新建的社团加入到链表尾部
                current = head;
                while (current->next != NULL) {
                    current = current->next;
                }
                current->next = club;
            }
        } else if (line[0] == 'm') {//新建一个成员
            MemberNode *member = (MemberNode *)malloc(sizeof(MemberNode));
            sscanf(line, "        name:%s\n", member->name);
            fgets(line, sizeof(line), file);
            sscanf(line, "        age:%d\n", &member->age);
            fgets(line, sizeof(line), file);
            char gender[10];
            sscanf(line, "        gender:%s\n", gender);
            if (strcmp(gender, "Male") == 0) {
                member->gender = Male;
            } else if (strcmp(gender, "Female") == 0) {
                member->gender = Female;
            } else {
                member->gender = Unknown;
            }
            fgets(line, sizeof(line), file);
            sscanf(line, "        point:%d\n", &member->point);
            member->next = NULL;
            if (current->members == NULL) {//成员链表为空，将新建的成员设为头节点
                current->members = member;
            } else {//成员链表不为空，将新建的成员加入到链表尾部
                MemberNode *currentMember = current->members;
                while (currentMember->next != NULL) {
                    currentMember = currentMember->next;
                }
                currentMember->next = member;
            }
        } else {//新建一个赞助商
            SponsorNode *sponsor = (SponsorNode *)malloc(sizeof(SponsorNode));
            sscanf(line, "        %s\n", sponsor->name);
            sponsor->next = NULL;
            if (current->sponsors == NULL) {//赞助商链表为空，将新建的赞助商设为头节点
                current->sponsors = sponsor;
            } else {//赞助商链表不为空，将新建的赞助商加入到链表尾部
                SponsorNode *currentSponsor = current->sponsors;
                while (currentSponsor->next != NULL) {
                    currentSponsor = currentSponsor->next;
                }
                currentSponsor->next = sponsor;
            }
        }
    }
    fclose(file);
    return head;//返回链表头节点
}
// 输出社团信息
void print_club(ClubNode *club) {
    printf("Name: %s\n", club->name);
    printf("Slogan: %s\n", club->slogan);
    printf("Purpose: %s\n", club->purpose);
    printf("Charter: %s\n", club->charter);
    printf("Boss: %s\n", club->boss);
    printf("Nature: %s\n", club->nature);
    printf("Members:\n");
    MemberNode *member = club->members;
    while (member != NULL) {
        printf("\tName: %s\n", member->name);
        printf("\tAge: %d\n", member->age);
        printf("\tGender: %s\n", member->gender == Male ? "Male" : member->gender == Female ? "Female" : "Unknown");
        printf("\tPoint: %d\n", member->point);
        member = member->next;
    }
    printf("Sponsors:\n");
    SponsorNode *sponsor = club->sponsors;
    while (sponsor != NULL) {
        printf("\tName: %s\n", sponsor->name);
        sponsor = sponsor->next;
    }
    printf("\n");
}

int main() 
{
    //打开文件
    FILE *fp;
    fp = fopen("club_1.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    //读取文件，创建链表





    //关闭文件
    fclose(fp);


    // ClubNode *head = parse_file("club_1.txt");

    //遍历文件
    // ClubNode *current = head;//
    // while (current != NULL) {
    //     print_club(current);
    //     current = current->next;
    // }
    // return 0;
}