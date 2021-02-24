#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"Tree.h"
/*����ջ��ʵ�ַǵݹ���������
* */

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
	int sz = getSize(root);
	int* arr = (int*)malloc(sizeof(int) * sz);
	int idx = 0;

	Stack st;
	stackInit(&st);
	while (root || !stackEmpty(&st)) {
		//��������·��
		while (root) {
			stackPush(&st, root);
			root = root->left;
		}
		//��ȡջ��Ԫ�أ�����������
		root = stackTop(&st);
		stackPop(&st);
		arr[idx] = root->val;
		idx++;
		root = root->right;
	}
	*returnSize = idx;
	return arr;
}