#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

// 定义评价记录的数据结构
struct EvaluationRecord {
    char activityName[50]; // 活动名称
    char participantName[20]; // 参与人员名称
    int score; // 分数
};

// 定义评价记录数组及其大小和容量
struct EvaluationRecord *records;
int len = 0; // 当前记录数
int capacity = 0; // 最大记录数

// 初始化评价记录数组
void initEvaluationRecords() {
    capacity = 10;
    records = (struct EvaluationRecord*) malloc(capacity * sizeof(struct EvaluationRecord));
}

// 释放评价记录数组
void freeEvaluationRecords() {
    free(records);
}

// 扩展评价记录数组的容量
void expandEvaluationRecords() {
    capacity *= 2;
    records = (struct EvaluationRecord*) realloc(records, capacity * sizeof(struct EvaluationRecord));
}

// 添加一条评价记录
void addEvaluationRecord() {
    struct EvaluationRecord record;
    printf("请输入活动名称：\n");
    scanf("%s", record.activityName);
    printf("请输入参与人员名称：\n");
    scanf("%s", record.participantName);
    printf("请输入得分：\n");
    scanf("%d", &record.score);
    
    // 如果数组已满，扩展容量
    if (len == capacity) {
        expandEvaluationRecords();
    }
    
    records[len++] = record;
}

// 修改一条评价记录
void modifyEvaluationRecord() {
    int index;
    printf("请输入要修改的记录编号（从1开始）：\n");
    scanf("%d", &index);
    if (index < 1 || index > len) {
        printf("输入的编号无效！\n");
        return;
    }
    struct EvaluationRecord *record = &records[index - 1];
    printf("当前记录原始信息如下：\n");
    printf("活动名称：%s\n", record->activityName);
    printf("参与人员名称：%s\n", record->participantName);
    printf("得分：%d\n", record->score);
    printf("请输入修改后的活动名称（不修改请直接回车）：\n");
    char buf[50];
    fgets(buf, 50, stdin);
    if (buf[0] != '\n') {
        sscanf(buf, "%s", record->activityName);
    }
    printf("请输入修改后的参与人员名称（不修改请直接回车）：\n");
    fgets(buf, 50, stdin);
    if (buf[0] != '\n') {
        sscanf(buf, "%s", record->participantName);
    }
    printf("请输入修改后的得分（不修改请直接回车）：\n");
    fgets(buf, 50, stdin);
    if (buf[0] != '\n') {
        sscanf(buf, "%d", &record->score);
    }
}

// 删除一条评价记录
void deleteEvaluationRecord() {
    int index;
    printf("请输入要删除的记录编号（从1开始）：\n");
    scanf("%d", &index);
    if (index < 1 || index > len) {
        printf("输入的编号无效！\n");
        return;
    }
    for (int i = index - 1; i < len - 1; i++) {
        records[i] = records[i + 1]; // 后面的记录依次前移
    }
    len--;
}

// 显示所有评价记录
void displayEvaluationRecords() {
    if (len == 0) {
        printf("当前没有任何评价记录！\n");
        return;
    }
    printf("编号\t活动名称\t参与人员名称\t得分\n");
    for (int i = 0; i < len; i++) {
        struct EvaluationRecord *record = &records[i];
        printf("%d\t%s\t%s\t%d\n", i + 1, record->activityName, record->participantName, record->score);
    }
}

// 主程序
int main() {
    initEvaluationRecords();
    while (true) {
        printf("请选择操作：\n");
        printf("1. 添加一条评价记录\n");
        printf("2. 修改一条评价记录\n");
        printf("3. 删除一条评价记录\n");
        printf("4. 显示所有评价记录\n");
        printf("5. 退出程序\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addEvaluationRecord();
                break;
            case 2:
                modifyEvaluationRecord();
                break;
            case 3:
                deleteEvaluationRecord();
                break;
            case 4:
                displayEvaluationRecords();
                break;
            case 5:
                freeEvaluationRecords();
                return 0;
            default:
                printf("无效的选择！\n");
        }
    }
}