#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

struct Node {
    char data[MAX_LINE_LENGTH];
    struct Node *next;
};

int main() {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    struct Node *head, *p, *q;

    // 以读方式打开文件
    fp = fopen("example.txt", "r");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }

    // 读取文件中的数据，并将数据转换成链表形式
    head = NULL;
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        p = (struct Node *)malloc(sizeof(struct Node));
        if (p == NULL) {
            printf("Failed to allocate memory.\n");
            return 1;
        }
        strcpy(p->data, line);
        p->next = NULL;
        if (head == NULL) {
            head = p;
        } else {
            q->next = p;
        }
        q = p;
    }

    // 修改链表中的数据
    p = head;
    while (p != NULL) {
        // 对链表中的数据进行修改
        // ...

        // 移动指针
        p = p->next;
    }

    // 将修改后的数据写回到文件中
    fclose(fp);
    fp = fopen("example.txt", "w");
    if (fp == NULL) {
        printf("Failed to open file.\n");
        return 1;
    }
    p = head;
    while (p != NULL) {
        fputs(p->data, fp);
        p = p->next;
    }
    fflush(fp);
    fclose(fp);

    // 释放链表中的节点
    p = head;
    while (p != NULL) {
        q = p->next;
        free(p);
        p = q;
    }

    return 0;
}
