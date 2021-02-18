#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeTNode {
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* binaryTreeCreate(BTDataType arr[], int n, int* idx) {
	// 递归停止条件
	if (*idx >= n || arr[*idx] == '#') {
		(*idx)++;
		return NULL;
	}
	else {
		//创建以当前数据为根的子树
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->data = arr[*idx];
		(*idx)++;
		root->left = binaryTreeCreate(arr, n, idx);
		root->right = binaryTreeCreate(arr, n, idx);
		return root;
	}
}

// 二叉树前序遍历
void binaryTreePrevOrder(BTNode* root) {
	if (root) {
		printf("%c ", root->data);
		binaryTreePrevOrder(root->left);
		binaryTreePrevOrder(root->right);
	}
}

// 二叉树中序遍历
void binaryTreeInOrder(BTNode* root) {
	if (root) {
		binaryTreeInOrder(root->left);
		printf("%c ", root->data);
		binaryTreeInOrder(root->right);
	}
}
// 二叉树后序遍历
void binaryTreePostOrder(BTNode* root) {
	if (root) {
		binaryTreePostOrder(root->left);
		binaryTreePostOrder(root->right);
		printf("%c ", root->data);
	}
}

// 二叉树节点个数(有返回值)
int binaryTreeSize(BTNode* root) {
	//二叉树的节点个数=左子树节点个数+右子树节点个数+1
	if (root == NULL)
		return 0;
	return binaryTreeSize(root->left) + binaryTreeSize(root->right) + 1;
}
// 二叉树节点个数(无返回值)
void binaryTreeSize2(BTNode* root, int* idx) {
	if (root) {
		(*idx)++;
		binaryTreeSize2(root->left, idx);
		binaryTreeSize2(root->right, idx);
	}
}

// 二叉树叶子节点个数
int binaryTreeLeafSize(BTNode* root) {
	if (root == NULL)
		return 0;
	//若根节点为叶子节点，则叶子节点数为1
	if (root->left == NULL && root->right == NULL)
		return 1;
	//若根节点不为叶子节点，则二叉树叶子节点的个数为左右子树之和
	return binaryTreeLeafSize(root->left) + binaryTreeLeafSize(root->right);
}

// 二叉树第k层节点个数
int binaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return binaryTreeLevelKSize(root->left, k - 1) + binaryTreeLevelKSize(root->right, k - 1);
}

// 二叉树查找值为x的节点
BTNode* binaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL)
		return NULL;
	if (root->data = x)
		return root;
	BTNode* node = binaryTreeFind(root->left, x);
	//若节点不在左子树，则在右子树中查找
	if(node == NULL)
		node = binaryTreeFind(root->right, x);
	return node;
}

// 二叉树销毁
void binaryTreeDestory(BTNode** root) {
	if (*root) {
		binaryTreeDestory(&((*root)->left));
		binaryTreeDestory(&((*root)->right));
		free(*root);
	}
	*root = NULL;
}


// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);

void testBTNode() {
	char arr[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	int idx = 0;
	BTNode* root = binaryTreeCreate(arr, sizeof(arr) / sizeof(arr[0]), &idx);
	printf("先序遍历：");
	binaryTreePrevOrder(root);
	printf("\n中序遍历：");
	binaryTreeInOrder(root);
	printf("\n后序遍历：");
	binaryTreePostOrder(root);
	printf("\n二叉树节点的个数=%d\n", binaryTreeSize(root));
	int num = 0;
	binaryTreeSize2(root, &num);
	printf("二叉树节点的个数=%d\n",num);
	printf("二叉树的叶子节点数=%d\n", binaryTreeLeafSize(root));
	printf("二叉树第3层节点数=%d\n", binaryTreeLevelKSize(root, 3));
	BTNode* node = binaryTreeFind(root, 'D');
	if (node)
		printf("找到节点,节点值为：%c\n", node->data);
	else
		printf("未找到节点\n");

	//销毁二叉树
	binaryTreeDestory(&root);
	printf("先序遍历：");
	binaryTreePrevOrder(root);
	printf("\n");
}