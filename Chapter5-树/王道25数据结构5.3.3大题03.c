#include <stdio.h>
#include <stdlib.h>

// 二叉树结点定义
typedef struct BiTNode
{
    int data;
    struct BiTNode* lchild, * rchild;
} BiTNode, * BiTree;

typedef struct Stack {
    BiTree node;
    int flag; // 0未访问，1已访问
} Stack;

Stack stack[100];
int top = -1;

int isEmpty() {
    return top == -1;
}

void push(BiTree node, int flag) {
    stack[++top].node = node;
    stack[top].flag = flag;
}

Stack pop() {
    return stack[top--];
}


int PostOrderNonRec(BiTree T, int arr[]) {
    int top = -1;
    int len = 0;
    if (T == NULL) { return 0; }
    push(T,0);
    while (!isEmpty()) {
        Stack s = pop();
        BiTree tree = s.node;
        if (s.flag == 0) {
            push(tree, 1);
            if (tree->rchild != NULL) { push(tree->rchild, 0); }
            if (tree->lchild != NULL) { push(tree->lchild, 0); }
        }
        else
        {
            arr[len++] = tree->data;
        }
    }
    return len;
}


// 标准答案数组 + 校验函数
int checkAns(int res[], int len)
{
    // 预设正确后序序列：7 4 5 2 6 3 1
    int std[] = { 7,4,5,2,6,3,1 };
    int stdLen = sizeof(std) / sizeof(std[0]);

    if (len != stdLen) return 0;
    for (int i = 0; i < len; i++)
    {
        if (res[i] != std[i]) return 0;
    }
    return 1;
}

// 构造复杂测试树 + 整体测试
void TestFunc()
{
    // 构建树形
    /*
            1
          /   \
         2     3
        / \     \
       4   5     6
      /
     7
    */
    BiTree n1 = (BiTree)malloc(sizeof(BiTNode));
    BiTree n2 = (BiTree)malloc(sizeof(BiTNode));
    BiTree n3 = (BiTree)malloc(sizeof(BiTNode));
    BiTree n4 = (BiTree)malloc(sizeof(BiTNode));
    BiTree n5 = (BiTree)malloc(sizeof(BiTNode));
    BiTree n6 = (BiTree)malloc(sizeof(BiTNode));
    BiTree n7 = (BiTree)malloc(sizeof(BiTNode));

    n1->data = 1; n2->data = 2; n3->data = 3;
    n4->data = 4; n5->data = 5; n6->data = 6; n7->data = 7;

    n1->lchild = n2; n1->rchild = n3;
    n2->lchild = n4; n2->rchild = n5;
    n3->lchild = NULL; n3->rchild = n6;
    n4->lchild = n7; n4->rchild = NULL;
    n5->lchild = n5->rchild = NULL;
    n6->lchild = n6->rchild = NULL;
    n7->lchild = n7->rchild = NULL;

    int buf[100];
    int cnt = PostOrderNonRec(n1, buf);

    printf("你的遍历结果：");
    for (int i = 0; i < cnt; i++) printf("%d ", buf[i]);
    printf("\n");

    if (checkAns(buf, cnt))
        printf("答案正确\n");
    else
        printf("答案错误，正确序列：7 4 5 2 6 3 1\n");
}

int main()
{
    TestFunc();
    return 0;
}