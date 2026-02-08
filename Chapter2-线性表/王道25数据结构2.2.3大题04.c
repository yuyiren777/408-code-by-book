#include <stdio.h>

#define MAXSIZE 100  // 顺序表最大容量

typedef struct {
    int data[MAXSIZE];
    int length;  // 当前长度
} SqList;

// 删除值在[s,t]之间的元素
void DeleteRange(SqList* L, int s, int t) {
    if (L->length == 0) {
        return 0;
    }
    int k = 0;
    for (int i = 0; i < L->length; i++) {
        if (L->data[i]<s || L->data[i]>t) {
            L->data[k++] = L->data[i];
        }
    }
    L->length = k;
    return 0;
}

// 打印顺序表
void PrintList(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

int main() {
    SqList L = { {1, 3, 5, 7, 9, 2, 4, 6, 8, 10}, 10 };
    int s = 3, t = 7;

    printf("原顺序表：");
    PrintList(L);

    DeleteRange(&L, s, t);

    printf("删除后顺序表：");
    PrintList(L);

    return 0;
}