#include <stdio.h>
#include <stdlib.h>

// 问题函数：将数组中两个顺序表的位置互换
// 参数:
//   A: 一维数组，存放两个线性表
//   m: 第一个线性表(a1...am)的长度
//   n: 第二个线性表(b1...bn)的长度
// 返回值: 无
void swapTwoLists(int A[], int m, int n) {
    //先定义两个数组存放交换数
    int* temp = (int*)malloc(sizeof(int) * n);
    int* temp1 = (int*)malloc(sizeof(int) * m);
    int a = 0;
    int b = 0;
    //把数字存入数组
    for (int i = 0; i < m; i++) {
        temp1[a++] = A[i];
    }
    for (int j = m; j <= m + n - 1; j++) {
        temp[b++] = A[j];
    }
    //按照顺序把数组中的数字放入A
    int c = 0;
    int d = 0;
    for (int x = 0; x < n; x++) {
        A[x] = temp[c++];
    }
    for (int x = n; x <= m + n - 1; x++) {
        A[x] = temp1[d++];
    }
}

// 辅助函数：打印数组
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

// 测试函数：测试不同情况下的交换逻辑
void testSwapTwoLists() {
    // 测试用例1: m=3, n=2
    int A1[5] = { 1, 2, 3, 4, 5 };
    int m1 = 3, n1 = 2;
    printf("测试用例1: 原始数组 = ");
    printArray(A1, m1 + n1);
    swapTwoLists(A1, m1, n1);
    printf("交换后数组 = ");
    printArray(A1, m1 + n1);
    printf("预期结果: 4 5 1 2 3\n\n");

    // 测试用例2: m=1, n=1
    int A2[2] = { 10, 20 };
    int m2 = 1, n2 = 1;
    printf("测试用例2: 原始数组 = ");
    printArray(A2, m2 + n2);
    swapTwoLists(A2, m2, n2);
    printf("交换后数组 = ");
    printArray(A2, m2 + n2);
    printf("预期结果: 20 10\n\n");

    // 测试用例3: m=0 (边界情况)
    int A3[4] = { 1, 2, 3, 4 };
    int m3 = 0, n3 = 4;
    printf("测试用例3: 原始数组 = ");
    printArray(A3, m3 + n3);
    swapTwoLists(A3, m3, n3);
    printf("交换后数组 = ");
    printArray(A3, m3 + n3);
    printf("预期结果: 1 2 3 4\n\n");

    // 测试用例4: n=0 (边界情况)
    int A4[4] = { 1, 2, 3, 4 };
    int m4 = 4, n4 = 0;
    printf("测试用例4: 原始数组 = ");
    printArray(A4, m4 + n4);
    swapTwoLists(A4, m4, n4);
    printf("交换后数组 = ");
    printArray(A4, m4 + n4);
    printf("预期结果: 1 2 3 4\n\n");
}

// 主函数
int main() {
    printf("开始测试两个顺序表位置互换算法...\n\n");
    testSwapTwoLists();
    printf("所有测试用例执行完毕。\n");
    return 0;
}