#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

/*
递归实现二叉树的中序遍历
*/
void inOrder(struct TreeNode* root, int* arr, int* idx) {
    if (root) {
        inOrder(root->left, arr, idx);
        arr[*idx] = root->val;
        (*idx)++;
        inOrder(root->right, arr, idx);
    }
}

int* inorderTraversalrecursion(struct TreeNode* root, int* returnSize) {
    int sz = getSize(root);
    int* arr = (int*)malloc(sizeof(int) * sz);
    int idx = 0;
    inOrder(root, arr, &idx);
    *returnSize = idx;
    return arr;
}