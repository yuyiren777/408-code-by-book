//设计一个高效算法，将顺序表L的所有元素逆置，要求算法空间复杂度是o(1)
#include <stdio.h>
#include <stdlib.h>

// 顺序表核心定义
#define ElemType int
#define MaxSize 100
typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;


void ReverseSqList(SqList* L);
// 辅助函数：初始化并添加完整测试数据
void InitAndSetData(SqList* L);
// 辅助函数：打印顺序表（检查结果用）
void PrintSqList(SqList* L);

// 主函数：自动执行初始化→打印原表→逆置→打印逆置表
int main() {
    SqList L;
    // 初始化并添加测试数据
    InitAndSetData(&L);
    printf("原顺序表元素：");
    PrintSqList(&L);

    // 调用逆置函数
    ReverseSqList(&L);

    printf("逆置后元素：");
    PrintSqList(&L);
    return 0;
}

// 初始化+添加完整测试数据（固定数据：1,2,3,4,5,6,7,8,9,10）
void InitAndSetData(SqList* L) {
    L->length = 0; // 初始化长度为0
    // 手动添加10个测试数数据
    int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    int n = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < n; i++) {
        L->data[i] = nums[i];
        L->length++;
    }
}

// 打印顺序表（检查逆置结果
void PrintSqList(SqList* L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

//逆置函数
void ReverseSqList(SqList* L) {
    if (L->length % 2 == 0) {
        int temp, id;
        id = (L->length-1) / 2;
        for (int i = id; i >= 0; i--) {
            int j = L->length - 1 - i;
            temp = L->data[j];
            L->data[j] = L->data[i];
            L->data[i] = temp;
        }
    }
    if (L->length % 2 == 1) {
        int temp1, id1;
        id1 = (L->length - 1) / 2;
        for (int i = id1 - 1; i >= 0; i--) {
            int j = L->length - 1 - i;
            temp1 = L->data[j];
            L->data[j] = L->data[i];
            L->data[i] = temp1;
        }
    }
    // 要求：空间复杂度O(1)，仅用临时变量，不额外开数组
}