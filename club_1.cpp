
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct member {
    char name[20];
    int id;
    int age;
    int point;
    int level;
    struct member *next;
};

struct activity {
    char name[20];
    char description[100];
    char date[20];
    struct activity *next;
};

struct club {
    char name[20];
    char description[100];
    char slogan[20];
    char aim[20];
    char rule[20];
    char boss[20];
    struct member *members;
    struct activity *activities;
    struct club *next;
};

// 读取文件中的一行数据
char *read_line(FILE *fp) {
    char *line = NULL;
    size_t len = 0;
    if (getline(&line, &len, fp) == -1) {
        free(line);
        return NULL;
    }
    // 去除换行符
    if (line[strlen(line)-1] == '\n') {
        line[strlen(line)-1] = '\0';
    }
    return line;
}

// 读取文件并创建链表
void read_file(char *filename, struct club **head)
{
    FILE *fp = fopen(filename, "r");//打开文件 r 代表只读
    if (fp == NULL) 
    {
        printf("Error: Cannot open file %s\n", filename);
        return;
    }

    char *line;
    int is_member = 0, is_activity = 0;
    struct club *curr_club = NULL;
    struct member *curr_member = NULL;
    struct activity *curr_activity = NULL;

    while ((line = read_line(fp)) != NULL) {
        if (strstr(line, "club_") != NULL) {
            // 新社团开始，创建新节点
            struct club *new_club = (struct club *)malloc(sizeof(struct club));
            strcpy(new_club->name, line);
            new_club->members = NULL;
            new_club->activities = NULL;
            new_club->next = NULL;

            // 插入链表
            if (*head == NULL) {
                *head = new_club;
            } else {
                curr_club->next = new_club;
            }
            curr_club = new_club;
        } else if (strstr(line, "name:") != NULL) {
            // 社团名称
            strcpy(curr_club->name, line+strlen("name: "));
        } else if (strstr(line, "description:") != NULL) {
            // 社团描述
            strcpy(curr_club->description, line+strlen("description: "));
        } else if (strstr(line, "slogan:") != NULL) {
            // 社团口号
            strcpy(curr_club->slogan, line+strlen("slogan: "));
        } else if (strstr(line, "aim:") != NULL) {
            // 社团宗旨
            strcpy(curr_club->aim, line+strlen("aim: "));
        } else if (strstr(line, "rule:") != NULL) {
            // 社团规则
            strcpy(curr_club->rule, line+strlen("rule: "));
        } else if (strstr(line, "boss:") != NULL) {
            // 社团负责人
            strcpy(curr_club->boss, line+strlen("boss: "));
        } else if (strstr(line, "members:") != NULL) {
            is_member = 1;
        } else if (strstr(line, "activities:") != NULL) {
            is_activity = 1;
        } else if (strstr(line, "name:") != NULL && is_member) {
            // 成员姓名
            struct member *new_member = (struct member *)malloc(sizeof(struct member));
            strcpy(new_member->name, line+strlen("name: "));
            new_member->next = NULL;
            if (curr_club->members == NULL) {
                curr_club->members = new_member;
            } else {
                curr_member->next = new_member;
            }
            curr_member = new_member;
        } else if (strstr(line, "id:") != NULL && is_member) {
            // 成员学号
            curr_member->id = atoi(line+strlen("id: "));
        } else if (strstr(line, "age:") != NULL && is_member) {
            // 成员年龄
            curr_member->age = atoi(line+strlen("age: "));
        } else if (strstr(line, "point:") != NULL && is_member) {
            // 成员积分
            curr_member->point = atoi(line+strlen("point: "));
        } else if (strstr(line, "level:") != NULL && is_member) {
            // 成员等级
            curr_member->level = atoi(line+strlen("level: "));
        } else if (strstr(line, "name:") != NULL && is_activity) {
            // 活动名称
            struct activity *new_activity = (struct activity *)malloc(sizeof(struct activity));
            strcpy(new_activity->name, line+strlen("name: "));
            new_activity->next = NULL;
            if (curr_club->activities == NULL) {
                curr_club->activities = new_activity;
            } else {
                curr_activity->next = new_activity;
            }
            curr_activity = new_activity;
        } else if (strstr(line, "description:") != NULL && is_activity) {
            // 活动描述
            strcpy(curr_activity->description, line+strlen("description: "));
        } else if (strstr(line, "date:") != NULL && is_activity) {
            // 活动日期
            strcpy(curr_activity->date, line+strlen("date: "));
        } else {
            // 不合法的格式，忽略
        }
    }

    fclose(fp);
}

// 主函数
int main() {
    struct club *head = NULL;
    read_file("clubs.txt", &head);

    // 遍历链表输出数据
    struct club *curr_club = head;
    while (curr_club != NULL) {
        printf("Club name: %s\n", curr_club->name);
        printf("Description: %s\n", curr_club->description);
        printf("Slogan: %s\n", curr_club->slogan);
        printf("Aim: %s\n", curr_club->aim);
        printf("Rule: %s\n", curr_club->rule);
        printf("Boss: %s\n", curr_club->boss);

        // 遍历成员链表
        struct member *curr_member = curr_club->members;
        while (curr_member != NULL) {
            printf("Member name: %s\n", curr_member->name);
            printf("Member id: %d\n", curr_member->id);
            printf("Member age: %d\n", curr_member->age);
            printf("Member point: %d\n", curr_member->point);
            printf("Member level: %d\n", curr_member->level);
            curr_member = curr_member->next;
        }

        // 遍历活动链表
        struct activity *curr_activity = curr_club->activities;
        while (curr_activity != NULL) {
            printf("Activity name: %s\n", curr_activity->name);
            printf("Description: %s\n", curr_activity->description);
            printf("Date: %s\n", curr_activity->date);
            curr_activity = curr_activity->next;
        }

        curr_club = curr_club->next;
    }

    return 0;
}

*/