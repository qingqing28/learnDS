#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*����һ�����������ҳ��������ȡ�
�����������Ϊ���ڵ㵽��ԶҶ�ӽڵ���·���ϵĽڵ�����
˵��: Ҷ�ӽڵ���ָû���ӽڵ�Ľڵ㡣
*/
 struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
 };
int maxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return l > r ? l + 1 : r + 1;
}