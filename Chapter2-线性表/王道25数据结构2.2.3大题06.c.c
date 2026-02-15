#include <stdio.h>
#include <stdlib.h>

// 定义顺序表结构体
#define MAXSIZE 100  // 顺序表最大容量
typedef struct {
    int data[MAXSIZE];  // 存储数据的数组
    int length;         // 顺序表实际长度
} SqList;

/**
 * 合并两个有序顺序表为一个新的有序顺序表
 * @param L1 第一个有序顺序表
 * @param L2 第二个有序顺序表
 * @return 合并后的新有序顺序表
 */
SqList mergeTwoSortedSqList(SqList L1, SqList L2) {
    SqList result;
    result.length = L1.length + L2.length;
    int i=0, j = 0,k = 0;
    while (j < L2.length && i < L1.length) {
        if (L1.data[i] >= L2.data[j]) {
            result.data[k++] = L2.data[j];
            j++;
        }
        else
        {
            result.data[k++] = L1.data[i];
            i++;
        }
    }
    if (j < L2.length) {
        result.data[k++] = L2.data[j++];
    }
    else
        result.data[k++] = L1.data[i++];
    return result;
}

// 辅助函数：打印顺序表
void printSqList(SqList L) {
    for (int k = 0; k < L.length; k++) {
        printf("%d ", L.data[k]);
    }
    printf("\n");
}

// 主函数测试
int main() {
    // 初始化第一个有序顺序表 L1: [1, 3, 5, 7, 9]
    SqList L1;
    L1.length = 5;
    int arr1[] = { 1, 3, 5, 7, 9 };
    for (int i = 0; i < L1.length; i++) {
        L1.data[i] = arr1[i];
    }

    // 初始化第二个有序顺序表 L2: [2, 4, 6, 8, 10]
    SqList L2;
    L2.length = 5;
    int arr2[] = { 2, 4, 6, 8, 10 };
    for (int i = 0; i < L2.length; i++) {
        L2.data[i] = arr2[i];
    }

    // 合并两个有序顺序表
    SqList result = mergeTwoSortedSqList(L1, L2);

    // 输出结果
    printf("原顺序表L1: ");
    printSqList(L1);
    printf("原顺序表L2: ");
    printSqList(L2);
    printf("合并后的顺序表: ");
    printSqList(result);

    return 0;
}
