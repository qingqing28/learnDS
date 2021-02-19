#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。
//只有给定的树是单值二叉树时，才返回 true；否则返回 false。
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