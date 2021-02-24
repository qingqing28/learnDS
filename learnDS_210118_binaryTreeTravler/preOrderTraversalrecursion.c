#include<stdio.h>
#include<stdlib.h>
#include"Tree.h"

/*�ݹ�ʵ�ֶ�������ǰ�����
*/
void preOrder(struct TreeNode* root, int* arr, int* idx) {
    if (root) {
        arr[*idx] = root->val;
        (*idx)++;
        preOrder(root->left, arr, idx);
        preOrder(root->right, arr, idx);
    }
}
//�ݹ鷽��
int* preorderTraversalrecursion(struct TreeNode* root, int* returnSize) {
    int sz = getSize(root);
    int* arr = (int*)malloc(sizeof(int) * sz);
    int idx = 0;
    preOrder(root, arr, &idx);
    *returnSize = idx;
    return arr;
}