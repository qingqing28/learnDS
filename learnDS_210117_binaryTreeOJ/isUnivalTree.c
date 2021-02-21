#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//���������ÿ���ڵ㶼������ͬ��ֵ����ô�ö��������ǵ�ֵ��������
//ֻ�и��������ǵ�ֵ������ʱ���ŷ��� true�����򷵻� false��
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
    
};
bool _isUnivalTree(struct TreeNode* root, int val) {
    if (root) {
        return root->val == val && _isUnivalTree(root->left, val) && _isUnivalTree(root->right, val);
    }
    return true;
}
bool isUnivalTree(struct TreeNode* root) {
    if (root == NULL)
        return true;
    return _isUnivalTree(root, root->val);
}