#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 你的代码 —— 完全没动！
bool isLegal(char arr[], int n) {
    char* arr1 = (char*)malloc(sizeof(char) * (n + 1));
    int tag = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 'I') {
            arr1[tag++] = 'I';
        }
        else
        {
            if (arr1[0] != 'I') {
                free(arr1);
                return false;//已经取完，还要索取
            }
            else
            {
                arr1[--tag] = 0;
            }
        }
    }
    if (arr1[0] == 'I') {
        free(arr1);
        return false;
    }
    else
    {
        free(arr1);
        return true;
    }

}

void testSequence(char arr[], int n, const char* name) {
    printf("测试序列 %s: ", name);
    if (isLegal(arr, n)) {
        printf("合法\n");
    }
    else {
        printf("非法\n");
    }
}

int main() {
    char A[] = { 'I','O','I','I','O','I','O','O' };
    char B[] = { 'I','O','O','I','O','I','I','O' };
    char C[] = { 'I','I','I','O','I','O','I','O' };
    char D[] = { 'I','I','I','O','I','O','O','O' };
    char E[] = { 'I','O','I','O' };

    // 我加的两个测试用例 —— 专门测你逻辑漏洞
    char F[] = { 'O' };
    char G[] = { 'I','O','O' };

    int lenA = sizeof(A) / sizeof(A[0]);
    int lenB = sizeof(B) / sizeof(B[0]);
    int lenC = sizeof(C) / sizeof(B[0]);
    int lenD = sizeof(D) / sizeof(D[0]);
    int lenE = sizeof(E) / sizeof(E[0]);
    int lenF = sizeof(F) / sizeof(F[0]);
    int lenG = sizeof(G) / sizeof(G[0]);

    testSequence(A, lenA, "A");
    testSequence(B, lenB, "B");
    testSequence(C, lenC, "C");
    testSequence(D, lenD, "D");
    testSequence(E, lenE, "E");

    // 运行危险用例
    testSequence(F, lenF, "F");
    testSequence(G, lenG, "G");

    return 0;
}