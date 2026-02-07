#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100  // 顺序表最大容量

typedef struct {
    int data[MAXSIZE];
    int length;  // 当前表长
} SqList;

// 你需要实现的核心函数：删除顺序表中所有值为x的元素
// 要求：时间复杂度O(n)，空间复杂度O(1)
// 若表为空，返回0表示出错；成功删除返回1
int deleteAllX(SqList* L, int x) {
    if (L->length == 0) {
        return 0;
    }
    int k = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] != x) {
            L->data[k++] = L->data[i];
        }
    }
    L->length = k;
    return 1;
}

// 辅助函数：初始化顺序表
void initList(SqList* L) {
    L->length = 0;
}

// 辅助函数：打印顺序表
void printList(SqList* L) {
    printf("当前顺序表元素：");
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

// 辅助函数：向顺序表尾部添加元素
int appendList(SqList* L, int val) {
    if (L->length >= MAXSIZE) {
        printf("表满，无法添加元素！\n");
        return 0;
    }
    L->data[L->length++] = val;
    return 1;
}

int main() {
    SqList L;
    initList(&L);

    // 测试用例1：正常情况，有多个x
    int test1[] = { 1, 3, 5, 3, 2, 4, 3, 6 };
    int x1 = 3;
    printf("=== 测试用例1 ===\n");
    printf("原始表：");
    for (int i = 0; i < 8; i++) {
        appendList(&L, test1[i]);
    }
    printList(&L);
    printf("删除所有值为 %d 的元素...\n", x1);
    if (deleteAllX(&L, x1)) {
        printf("删除后：");
        printList(&L);
    }
    else {
        printf("删除失败：表为空\n");
    }
    // 清空表
    initList(&L);

    // 测试用例2：表中没有x
    int test2[] = { 10, 20, 30 };
    int x2 = 5;
    printf("\n=== 测试用例2 ===\n");
    printf("原始表：");
    for (int i = 0; i < 3; i++) {
        appendList(&L, test2[i]);
    }
    printList(&L);
    printf("删除所有值为 %d 的元素...\n", x2);
    if (deleteAllX(&L, x2)) {
        printf("删除后：");
        printList(&L);
    }
    else {
        printf("删除失败：表为空\n");
    }
    // 清空表
    initList(&L);

    // 测试用例3：空表
    int x3 = 1;
    printf("\n=== 测试用例3 ===\n");
    printf("原始表：空表\n");
    printf("删除所有值为 %d 的元素...\n", x3);
    if (deleteAllX(&L, x3)) {
        printf("删除后：");
        printList(&L);
    }
    else {
        printf("删除失败：表为空\n");
    }

    return 0;
}