#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeTNode {
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* arr, int n, int* idx) {
	//递归停止条件
	if ((*idx) >= n || arr[*idx] == '#') {
		(*idx)++;
		return NULL;
	}
	else {
		//创建以当前数据为根的子树
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->data = arr[*idx];
		(*idx)++;
		root->left = BinaryTreeCreate(arr, n, idx);
		root->right = BinaryTreeCreate(arr, n, idx);
		return root;
	}
}

// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
// 二叉树销毁
void BinaryTreeDestory(BTNode** root);
// 二叉树节点个数
int BinaryTreeSize(BTNode* root);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

void testBTNode() {
	char arr[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	int idx = 0;
	BTNode* root = BinaryTreeCreate(arr, sizeof(arr) / sizeof(arr[0]), &idx);
	printf("先序遍历：");
	BinaryTreePrevOrder(root);
	printf("\n中序遍历：");
	BinaryTreeInOrder(root);
	printf("\n后序遍历：");
	BinaryTreePostOrder(root);
}