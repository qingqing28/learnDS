#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"Tree.h"
/*借助栈来实现非递归的后序遍历
* */
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int sz = getSize(root);
    int* arr = (int*)malloc(sizeof(int) * sz);
    int idx = 0;

    Stack st;
    stackInit(&st);
    struct TreeNode* prev = NULL;
    while (root || !stackEmpty(&st)) {
        while (root) {
            stackPush(&st, root);
            root = root->left;
        }
        struct TreeNode* top = stackTop(&st);
        //没有右子树，或者右子树已经访问过，可以访问节点
        if (top->right == NULL || prev == top->right) {
            arr[idx] = top->val;
            idx++;
            stackPop(&st);
            prev = top;
        }
        else {
            root = top->right;
        }

    }
    *returnSize = idx;
    return arr;
}