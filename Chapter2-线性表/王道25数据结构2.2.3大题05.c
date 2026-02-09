#include <stdio.h>
//从有序顺序表中删除重复元素
#define MAXSIZE 100

typedef struct {
    int data[MAXSIZE];
    int length;
} SqList;

void DeleteDuplicate(SqList* L) {
    if (L->length == 0) {
        return 0;
    }
    int k = 0;
    for (int j = 1; j < L->length; j++) {
        if (L->data[j] != L->data[k]) {
            k++;
            L->data[k] = L->data[j];
        }
        
    }
    L->length = k + 1;
}

// 测试代码
int main() {
    SqList L = { {1, 2, 2, 2, 3, 3, 3, 4}, 8 };
    DeleteDuplicate(&L);
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    return 0;
}