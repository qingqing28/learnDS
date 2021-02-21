#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*
���������ǿն����� s �� t������ s ���Ƿ������ t ������ͬ�ṹ�ͽڵ�ֵ��������
s ��һ���������� s ��һ���ڵ������ڵ���������s Ҳ���Կ����������һ��������
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
//bool isSameTree(struct TreeNode* s, struct TreeNode* t) {
//    if (s == NULL && t == NULL)
//        return true;
//    if (s == NULL || t == NULL)
//        return false;
//    return s->val == t->val && isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
//}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (t == NULL)
        return true;
    if (s == NULL)
        return false;
    return isSameTree(s, t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}