#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*��ͬ����
* �������ö������ĸ��ڵ� p �� q ����дһ���������������������Ƿ���ͬ��
����������ڽṹ����ͬ�����ҽڵ������ͬ��ֵ������Ϊ��������ͬ�ġ�
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //�жϵ�ǰ�ڵ��Ƿ���ͬ
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL)
        return false;
    if (q == NULL)
        return false;
    //�ж��������Ƿ���ͬ
    return p->val == q->val && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}