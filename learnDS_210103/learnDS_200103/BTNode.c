#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;
typedef struct BinaryTreeTNode {
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;
// ͨ��ǰ�����������"ABD##E#H##CF##G##"����������
BTNode* binaryTreeCreate(BTDataType arr[], int n, int* idx) {
	// �ݹ�ֹͣ����
	if (*idx >= n || arr[*idx] == '#') {
		(*idx)++;
		return NULL;
	}
	else {
		//�����Ե�ǰ����Ϊ��������
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->data = arr[*idx];
		(*idx)++;
		root->left = binaryTreeCreate(arr, n, idx);
		root->right = binaryTreeCreate(arr, n, idx);
		return root;
	}
}

// ������ǰ�����
void binaryTreePrevOrder(BTNode* root) {
	if (root) {
		printf("%c ", root->data);
		binaryTreePrevOrder(root->left);
		binaryTreePrevOrder(root->right);
	}
}

// �������������
void binaryTreeInOrder(BTNode* root) {
	if (root) {
		binaryTreeInOrder(root->left);
		printf("%c ", root->data);
		binaryTreeInOrder(root->right);
	}
}
// �������������
void binaryTreePostOrder(BTNode* root) {
	if (root) {
		binaryTreePostOrder(root->left);
		binaryTreePostOrder(root->right);
		printf("%c ", root->data);
	}
}

// �������ڵ����(�з���ֵ)
int binaryTreeSize(BTNode* root) {
	//�������Ľڵ����=�������ڵ����+�������ڵ����+1
	if (root == NULL)
		return 0;
	return binaryTreeSize(root->left) + binaryTreeSize(root->right) + 1;
}
// �������ڵ����(�޷���ֵ)
void binaryTreeSize2(BTNode* root, int* idx) {
	if (root) {
		(*idx)++;
		binaryTreeSize2(root->left, idx);
		binaryTreeSize2(root->right, idx);
	}
}

// ������Ҷ�ӽڵ����
int binaryTreeLeafSize(BTNode* root) {
	if (root == NULL)
		return 0;
	//�����ڵ�ΪҶ�ӽڵ㣬��Ҷ�ӽڵ���Ϊ1
	if (root->left == NULL && root->right == NULL)
		return 1;
	//�����ڵ㲻ΪҶ�ӽڵ㣬�������Ҷ�ӽڵ�ĸ���Ϊ��������֮��
	return binaryTreeLeafSize(root->left) + binaryTreeLeafSize(root->right);
}

// ��������k��ڵ����
int binaryTreeLevelKSize(BTNode* root, int k) {
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return binaryTreeLevelKSize(root->left, k - 1) + binaryTreeLevelKSize(root->right, k - 1);
}

// ����������ֵΪx�Ľڵ�
BTNode* binaryTreeFind(BTNode* root, BTDataType x) {
	if (root == NULL)
		return NULL;
	if (root->data = x)
		return root;
	BTNode* node = binaryTreeFind(root->left, x);
	//���ڵ㲻���������������������в���
	if(node == NULL)
		node = binaryTreeFind(root->right, x);
	return node;
}

// ����������
void binaryTreeDestory(BTNode** root) {
	if (*root) {
		binaryTreeDestory(&((*root)->left));
		binaryTreeDestory(&((*root)->right));
		free(*root);
	}
	*root = NULL;
}


// �������
void BinaryTreeLevelOrder(BTNode* root);
// �ж϶������Ƿ�����ȫ������
int BinaryTreeComplete(BTNode* root);

void testBTNode() {
	char arr[] = { 'A','B','D','#','#','E','#','H','#','#','C','F','#','#','G','#','#' };
	int idx = 0;
	BTNode* root = binaryTreeCreate(arr, sizeof(arr) / sizeof(arr[0]), &idx);
	printf("���������");
	binaryTreePrevOrder(root);
	printf("\n���������");
	binaryTreeInOrder(root);
	printf("\n���������");
	binaryTreePostOrder(root);
	printf("\n�������ڵ�ĸ���=%d\n", binaryTreeSize(root));
	int num = 0;
	binaryTreeSize2(root, &num);
	printf("�������ڵ�ĸ���=%d\n",num);
	printf("��������Ҷ�ӽڵ���=%d\n", binaryTreeLeafSize(root));
	printf("��������3��ڵ���=%d\n", binaryTreeLevelKSize(root, 3));
	BTNode* node = binaryTreeFind(root, 'D');
	if (node)
		printf("�ҵ��ڵ�,�ڵ�ֵΪ��%c\n", node->data);
	else
		printf("δ�ҵ��ڵ�\n");

	//���ٶ�����
	binaryTreeDestory(&root);
	printf("���������");
	binaryTreePrevOrder(root);
	printf("\n");
}