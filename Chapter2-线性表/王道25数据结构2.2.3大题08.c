#include <stdio.h>
#include <stdlib.h>

// 问题函数：在有序顺序表中查找并交换或插入
// 参数:
//   A: 递增有序的顺序表数组
//   n: 表的当前有效长度（指针，用于修改）
//   x: 要查找/插入的数值
// 返回值: 找到返回1，未找到插入后返回0
int findAndInsertOrSwap(int A[], int* n, int x) {
    int left = 0, right = *n - 1;
    int mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (A[mid] > x) {
            right = mid - 1;
        }
        else if (A[mid] < x) {
            left = mid + 1;
        }
        else {
            if (mid!=*n-1) {
                int temp = A[mid + 1];
                A[mid + 1] = A[mid];
                A[mid] = temp;
            }
            return 1;
        }
    }
    if (A[mid] > x) {
        int i;
        for (i = *n - 1; i >= mid; i--) {
            A[i + 1] = A[i];
            
        }
        A[i+1] = x;
        
        (*n)++;
        return 0;
    }
    if (A[mid] < x) {
        int j;
        for (j = *n - 1; j >= mid + 1; j--) {
            A[j + 1] = A[j];
        }
        A[j + 1] = x;
        
        (*n)++;
        return 0;
    }

}

// 辅助函数：打印顺序表
void printList(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// 测试函数：测试不同情况下的查找、交换和插入逻辑
void testFindAndInsertOrSwap() {
    // 测试用例1: 找到元素并交换（非最后一个元素）
    int A1[10] = { 1, 3, 5, 7, 9 };
    int n1 = 5;
    int x1 = 5;
    printf("测试用例1: 原始表 = ");
    printList(A1, n1);
    printf("查找值 = %d\n", x1);
    int res1 = findAndInsertOrSwap(A1, &n1, x1);
    printf("操作后表 = ");
    printList(A1, n1);
    printf("预期结果: 1 3 7 5 9\n\n");

    // 测试用例2: 找到元素但为最后一个元素（无法交换）
    int A2[10] = { 2, 4, 6, 8 };
    int n2 = 4;
    int x2 = 8;
    printf("测试用例2: 原始表 = ");
    printList(A2, n2);
    printf("查找值 = %d\n", x2);
    int res2 = findAndInsertOrSwap(A2, &n2, x2);
    printf("操作后表 = ");
    printList(A2, n2);
    printf("预期结果: 2 4 6 8（无交换）\n\n");

    // 测试用例3: 未找到元素，插入到表中间
    int A3[10] = { 10, 20, 30, 40, 50 };
    int n3 = 5;
    int x3 = 25;
    printf("测试用例3: 原始表 = ");
    printList(A3, n3);
    printf("插入值 = %d\n", x3);
    int res3 = findAndInsertOrSwap(A3, &n3, x3);
    printf("操作后表 = ");
    printList(A3, n3);
    printf("预期结果: 10 20 25 30 40 50\n\n");

    // 测试用例4: 未找到元素，插入到表开头
    int A4[10] = { 5, 10, 15 };
    int n4 = 3;
    int x4 = 3;
    printf("测试用例4: 原始表 = ");
    printList(A4, n4);
    printf("插入值 = %d\n", x4);
    int res4 = findAndInsertOrSwap(A4, &n4, x4);
    printf("操作后表 = ");
    printList(A4, n4);
    printf("预期结果: 3 5 10 15\n\n");

    // 测试用例5: 未找到元素，插入到表末尾
    int A5[10] = { 1, 2, 3 };
    int n5 = 3;
    int x5 = 4;
    printf("测试用例5: 原始表 = ");
    printList(A5, n5);
    printf("插入值 = %d\n", x5);
    int res5 = findAndInsertOrSwap(A5, &n5, x5);
    printf("操作后表 = ");
    printList(A5, n5);
    printf("预期结果: 1 2 3 4\n\n");
}

// 主函数
int main() {
    printf("开始测试有序顺序表查找交换/插入算法...\n\n");
    testFindAndInsertOrSwap();
    printf("所有测试用例执行完毕。\n");
    return 0;
}