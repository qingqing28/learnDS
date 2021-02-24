#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"Tree.h"
/*借助栈来实现非递归的前序遍历
* */
int getSize(struct TreeNode* root) {
	if (root == NULL)
		return 0;
	return getSize(root->left) + getSize(root->right) + 1;
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int) * sz);
	int idx = 0;

	Stack st;
	stackInit(&st);
	while (root || !stackEmpty(&st)) {
		//访问最左路径
		while (root) {
			arr[idx] = root->val;
			idx++;
			stackPush(&st, root);
			root = root->left;
		}
		//获取栈顶元素，访问右子树
		root = stackTop(&st);
		stackPop(&st);
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}