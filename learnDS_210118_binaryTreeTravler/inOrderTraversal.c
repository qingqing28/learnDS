#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"Tree.h"
/*借助栈来实现非递归的中序遍历
* */

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int) * sz);
	int idx = 0;

	Stack st;
	stackInit(&st);
	while (root || !stackEmpty(&st)) {
		//访问最左路径
		while (root) {
			stackPush(&st, root);
			root = root->left;
		}
		//获取栈顶元素，访问右子树
		root = stackTop(&st);
		stackPop(&st);
		arr[idx] = root->val;
		idx++;
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}