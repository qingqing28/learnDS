#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

/*
�ݹ�ʵ�ֶ������ĺ������
*/
void postOrder(struct TreeNode* root, int* arr, int* idx) {
    if (root) {
        postOrder(root->left, arr, idx);
        postOrder(root->right, arr, idx);
        arr[*idx] = root->val;
        (*idx)++;
    }
}

int* postorderTraversalrecursion(struct TreeNode* root, int* returnSize) {
    int sz = getSize(root);
    int* arr = (int*)malloc(sizeof(int) * sz);
    int idx = 0;
    postOrder(root, arr, &idx);
    *returnSize = idx;
    return arr;
}