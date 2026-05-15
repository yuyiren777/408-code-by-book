#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXSIZE 100
typedef int ElemType;

// 更大的非完全二叉树 结构图
/*
           1
        /      \
       2        3
     /   \       \
    4     5       7
   / \   / \     /
  8  9 10 11   14
     /      \
    18      23
*/

ElemType tree[MAXSIZE] = { 0 };

ElemType findLCA(ElemType tree[], int i, int j) {

    double h = ceil(log2(i + 1));

    for (int k = 0; k < h - 1; k++) {
        i /= 2;
        int m = j;
        while (i != m && m != 1) {
            m /= 2;
        }
        if (i == m) {
            return tree[i];
        }
    }
}

int main() {
    // 给你赋值更大的非完全二叉树
    tree[1] = 1;
    tree[2] = 2;
    tree[3] = 3;
    tree[4] = 4;
    tree[5] = 5;
    tree[7] = 7;
    tree[8] = 8;
    tree[9] = 9;
    tree[10] = 10;
    tree[11] = 11;
    tree[14] = 14;
    tree[18] = 18;
    tree[23] = 23;

    int i, j;
    printf("可用结点编号：1 2 3 4 5 7 8 9 10 11 14 18 23\n");
    printf("请输入两个结点编号i和j：");
    scanf_s("%d %d", &i, &j);

    ElemType lca_val = findLCA(tree, i, j);
    printf("编号%d和%d的最近公共祖先结点的值为：%d\n", i, j, lca_val);

    return 0;
}