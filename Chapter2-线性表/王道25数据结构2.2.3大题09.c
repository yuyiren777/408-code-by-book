#include <stdio.h>
int max(int a, int b) {
    return a > b ? a : b;
}
//算法
// 问题函数：由你自己实现
void findCommonElements(int A[], int B[], int C[], int n) {
    int i = 0, j = 0, k = 0;
    while (i < n && j < n && k < n) {
        if (A[i] == B[j]&&B[j] == C[k]) {
            printf("%d ", A[i]);
            i++;
            j++;
            k++;
        }
        else {
            int ele = max(A[i], max(B[j], C[k]));
            if (A[i] < ele) {
                i++;
            }
            if (B[j] < ele) {
                j++;
            }
            if (C[k] < ele) {
                k++;
            }
        }
    }
    return;
}


// 测试用例1：题目示例
void test_case1() {
    int A[] = { 1, 2, 3 };
    int B[] = { 2, 3, 4 };
    int C[] = { -1, 0, 2 };
    int n = 3;

    printf("=== 测试用例1 ===\n");
    printf("预期输出: 2\n");
    printf("实际输出: ");
    findCommonElements(A, B, C, n);
    printf("\n\n");
}

// 测试用例2：有多个公共元素
void test_case2() {
    int A[] = { 1, 3, 5, 7, 9 };
    int B[] = { 2, 3, 5, 8, 9 };
    int C[] = { 3, 4, 5, 9, 10 };
    int n = 5;

    printf("=== 测试用例2 ===\n");
    printf("预期输出: 3 5 9\n");
    printf("实际输出: ");
    findCommonElements(A, B, C, n);
    printf("\n\n");
}

// 测试用例3：无公共元素
void test_case3() {
    int A[] = { 1, 2, 3 };
    int B[] = { 4, 5, 6 };
    int C[] = { 7, 8, 9 };
    int n = 3;

    printf("=== 测试用例3 ===\n");
    printf("预期输出: (无)\n");
    printf("实际输出: ");
    findCommonElements(A, B, C, n);
    printf("\n\n");
}

// 主函数：调用所有测试用例
int main() {
    test_case1();
    test_case2();
    test_case3();
    return 0;
}