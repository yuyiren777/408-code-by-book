//1. 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
// 空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。
#include <stdio.h>
#include <stdlib.h>

// 定义顺序表的最大容量
#define MAXSIZE 100

// 顺序表结构定义
typedef struct {
    int data[MAXSIZE];
    int length;  // 当前元素个数
} SqList;

// 初始化一个测试用的顺序表
void initTestList(SqList* L) {
    // 初始化一些测试数据
    int testData[] = { 12, 5, 8, 3, 15, 7, 20, 4 };
    int dataCount = sizeof(testData) / sizeof(testData[0]);

    // 将测试数据填入顺序表
    for (int i = 0; i < dataCount; i++) {
        L->data[i] = testData[i];
    }
    L->length = dataCount;
}

// 打印顺序表（用于验证结果）
void printList(SqList* L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}


int deleteMin(SqList* L,int * result) {
    if (L->length == 0) {
        return 0;
    }
    *result = L->data[0];
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] <= *result) {
            *result = L->data[i];
        }
    }
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == *result) {
            L->data[i] = L->data[L->length - 1];
        }
    }
    return *result;
}

int main() {
    // 创建并初始化顺序表
    SqList L;
    initTestList(&L);

    printf("初始化的顺序表：");
    printList(&L);
    int result;
    
    int min = deleteMin(&L,&result);
    printf("最小值是%d\n", min);

    printf("修改后的的顺序表：");
    printList(&L);
    return 0;
}