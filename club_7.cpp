#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1000
#define MAX_NAME_LEN 50

// 定义成员信息结构体
typedef struct {
    char name[MAX_NAME_LEN];
    int age;
    char gender[MAX_NAME_LEN];
    int point;
} Member;

// 定义俱乐部信息结构体
typedef struct {
    char name[MAX_NAME_LEN];
    char slogan[MAX_LINE_LEN];
    char aim[MAX_LINE_LEN];
    char rule[MAX_LINE_LEN];
    char boss[MAX_NAME_LEN];
    char description[MAX_LINE_LEN];
    int member_count;
    Member *members;
    char **sponsors;
    int sponsor_count;
} Club;

// 解析成员信息
Member parse_member(char *line) {
    Member member;
    char *token;
    token = strtok(line, ":");
    strcpy(member.name, strtok(NULL, "\n"));
    fgets(line, MAX_LINE_LEN, stdin); // age
    member.age = atoi(strtok(line, ":"));
    fgets(line, MAX_LINE_LEN, stdin); // gender
    strcpy(member.gender, strtok(NULL, "\n"));
    fgets(line, MAX_LINE_LEN, stdin); // point
    member.point = atoi(strtok(line, ":"));
    return member;
}

// 解析俱乐部信息
Club parse_club(FILE *fp) {
    Club club;
    char line[MAX_LINE_LEN];
    // club_001:数学社
    // slogan:love
    // aim:study
    // rule:high level
    // boss:Bend
    // description:math
    //解析
    //将club_001:数学社分割成两个片段，第一个片段是club_001，第二个片段是数学社,然后将第二个片段复制到club.name中
    fgets(line, MAX_LINE_LEN, fp); // club_001:数学社
    strtok(line, ":");
    strcpy(club.name, strtok(NULL, "\n"));
    printf("%s\n", club.name);
    //如果line是string类型
    //string line;
    //getline(cin, line);
    //strtok(line.c_str(), ":");
    //strcpy(club.name, strtok(NULL, "\n"));
    //printf("%s\n", club.name);
    fgets(line, MAX_LINE_LEN, fp); // slogan
    strcpy(club.slogan, strtok(NULL, "\n"));
    fgets(line, MAX_LINE_LEN, fp); // aim
    strcpy(club.aim, strtok(NULL, "\n"));
    fgets(line, MAX_LINE_LEN, fp); // rule
    strcpy(club.rule, strtok(NULL, "\n"));
    fgets(line, MAX_LINE_LEN, fp); // boss
    strcpy(club.boss, strtok(NULL, "\n"));
    fgets(line, MAX_LINE_LEN, fp); // description
    strcpy(club.description, strtok(NULL, "\n"));

    // 解析成员信息
    club.member_count = 0;
    club.members = NULL;
    while (fgets(line, MAX_LINE_LEN, fp)) {
        if (line[0] == '\n') 
        {
            break;
        }
        club.member_count++;
        club.members = (Member *) realloc(club.members, club.member_count * sizeof(Member));
        club.members[club.member_count-1] = parse_member(line);
    }

    // 解析赞助商信息
    club.sponsor_count = 0;
    club.sponsors = NULL;
    while (fgets(line, MAX_LINE_LEN, fp)) {
        if (line[0] == '\n') {
            break;
        }
        club.sponsor_count++;
        club.sponsors = (char **) realloc(club.sponsors, club.sponsor_count * sizeof(char *));
        club.sponsors[club.sponsor_count-1] = (char *) malloc(MAX_LINE_LEN * sizeof(char));
        strcpy(club.sponsors[club.sponsor_count-1], strtok(line, "\n"));
    }

    return club;
}

int main() {
    FILE *fp;
    fp = fopen("club_1.txt", "r");
    Club club = parse_club(fp);
    fclose(fp);

    // 输出俱乐部信息
    printf("name: %s\n", club.name);
    printf("slogan: %s\n", club.slogan);
    printf("aim: %s\n", club.aim);
    printf("rule: %s\n", club.rule);
    printf("boss: %s\n", club.boss);
    printf("description: %s\n", club.description);

    printf("members:\n");
    for (int i = 0; i < club.member_count; i++) {
        printf("  name: %s\n", club.members[i].name);
        printf("  age: %d\n", club.members[i].age);
        printf("  gender: %s\n", club.members[i].gender);
        printf("  point: %d\n", club.members[i].point);
    }

    printf("sponsors:\n");
    for (int i = 0; i < club.sponsor_count; i++) {
        printf("  %s\n", club.sponsors[i]);
    }

    // 释放内存
    for (int i = 0; i < club.sponsor_count; i++) {
        free(club.sponsors[i]);
    }
    free(club.sponsors);
    free(club.members);

    return 0;
}
