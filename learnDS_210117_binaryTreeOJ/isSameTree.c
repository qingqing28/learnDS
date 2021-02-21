#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

/*相同的树
* 给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
*/
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    //判断当前节点是否相同
    if (p == NULL && q == NULL)
        return true;
    if (p == NULL)
        return false;
    if (q == NULL)
        return false;
    //判断左子树是否相同
    return p->val == q->val && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
}