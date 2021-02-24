#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

/*递归实现二叉树的前序遍历
*/
void preOrder(struct TreeNode* root, int* arr, int* idx) {
    if (root) {
        arr[*idx] = root->val;
        (*idx)++;
        preOrder(root->left, arr, idx);
        preOrder(root->right, arr, idx);
    }
}
//递归方法
int* preorderTraversalrecursion(struct TreeNode* root, int* returnSize) {
    int sz = getSize(root);
    int* arr = (int*)malloc(sizeof(int) * sz);
    int idx = 0;
    preOrder(root, arr, &idx);
    *returnSize = idx;
    return arr;
}