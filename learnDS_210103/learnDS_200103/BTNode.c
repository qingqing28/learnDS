#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeTNode {
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* BinaryTreeCreate(BTDataType* arr, int n, int* idx) {
	//�ݹ�ֹͣ����
	if ((*idx) >= n || arr[*idx] == '#') {
		(*idx)++;
		return NULL;
	}
	else {
		//�����Ե�ǰ����Ϊ��������
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->data = arr[*idx];
		(*idx)++;
		root->left = BinaryTreeCreate(arr, n, idx);
		root->right = BinaryTreeCreate(arr, n, idx);
		return root;
	}
}

// ������ǰ�����
void BinaryTreePrevOrder(BTNode* root) {
	if (root == NULL)
		return;
	printf("%c ", root->data);
	BinaryTreePrevOrder(root->left);
	BinaryTreePrevOrder(root->right);
}
// �������������
void BinaryTreeInOrder(BTNode* root) {
	if (root == NULL)
		return;
	BinaryTreeInOrder(root->left);
	printf("%c ", root->data);
	BinaryTreeInOrder(root->right);
}
// �������������
void BinaryTreePostOrder(BTNode* root) {
	if (root == NULL)
		return;
	BinaryTreePostOrder(root->left);
	BinaryTreePostOrder(root->right);
	printf("%c ", root->data);
}
// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);
// ����������
void BinaryTreeDestory(BTNode** root);
// �������ڵ����
int BinaryTreeSize(BTNode* root);
// ������Ҷ�ӽڵ����
int BinaryTreeLeafSize(BTNode* root);
// ��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);
// ����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

void testBTNode() {
	char arr[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	int idx = 0;
	BTNode* root = BinaryTreeCreate(arr, sizeof(arr) / sizeof(arr[0]), &idx);
	printf("���������");
	BinaryTreePrevOrder(root);
	printf("\n���������");
	BinaryTreeInOrder(root);
	printf("\n���������");
	BinaryTreePostOrder(root);
}