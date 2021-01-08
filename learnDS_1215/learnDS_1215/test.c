#include<stdio.h>
#include<stdlib.h>
#include"list.h"

//����һ���½ڵ�
ListNode* createListNode(LDataType val) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = val;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

//����ĳ�ʼ��
void listInit(List* lst) {
	lst->head = createListNode(0);
	//ͷ�ڵ��ǰһ���ڵ�ͺ�һ���ڵ��Ϊ������
	lst->head->next = lst->head->prev = lst->head;
}

//β��һ������
void listPushBack(List* lst, LDataType val) {
	if (lst == NULL)
		return;
	//ͷ�ڵ��ǰһ���ڵ�Ϊ���һ���ڵ�
	ListNode* node = createListNode(val);
	ListNode* last = lst->head->prev;
	//����β��
	last->next = node;
	node->next = lst->head;
	node->prev = last;
	lst->head->prev = node;
}

//βɾһ������
void listPopBack(List* lst) {
	//�������ڻ�������Ϊ��ʱֱ�ӷ��س���
	if (lst == NULL || lst->head->next == lst->head) {
		return;
	}
	//ͷ�ڵ��ǰһ���ڵ�Ϊ���һ���ڵ�
	ListNode* last = lst->head->prev;
	ListNode* prev = last->prev;

	//����βɾ
	prev->next = lst->head;
	lst->head->prev = prev;
	free(last);
}

//��ӡ����
void printList(List* lst) {
	if (lst == NULL || lst->head == NULL)
		return;
	ListNode* cur = lst->head->next;
	while (cur != lst->head) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//ͷ��һ������
void listPushFront(List* lst, LDataType val){
	if (lst == NULL)
		return;
	ListNode* node = createListNode(val);
	ListNode* next = lst->head->next;

	//����ͷ��
	lst->head->next = node;
	node->next = next;
	
	next->prev = node;
	node->prev = lst->head;
}

//ͷɾһ������
void listPopFront(List* lst) {
	//�������ڻ�������Ϊ��ʱֱ�ӷ��س���
	if (lst == NULL || lst->head->next == lst->head) {
		return;
	}
	ListNode* node = lst->head->next;
	ListNode* next = node->next;

	//����ͷɾ
	lst->head->next = next;
	next->prev = lst->head;
	free(node);
}

//ɾ�������ڵ㣨����ɾ��ͷ�ڵ㣩
void listErase(List* lst, ListNode* node) {
	//���������� �� ����Ϊ�������ڵ�Ϊͷ�ڵ���ֱ�ӷ���
	if (lst == NULL || lst->head->next == lst->head || node == lst->head)
		return;
	ListNode* prev = node->prev;
	ListNode* next = node->next;

	//����ɾ��
	prev->next = next;
	next->prev = prev;
	free(node);
}

// ��node�ڵ�λ�ô������½ڵ�
void listInsert(List* lst,  ListNode* node,LDataType val) {
	//�����������򷵻�
	if (lst == NULL)
		return;
	ListNode* prev = node->prev;
	ListNode* newNode = createListNode(val);

	//����ڵ�
	prev->next = newNode;
	newNode->next = node;
	node->prev = newNode;
	newNode->prev = prev;
}

//���ҵ�n��λ�õĽڵ�
ListNode* listFindByIdx(List* lst, int n) {
	if (lst == NULL || lst->head->next == lst->head)
		return;
	ListNode* cur = lst->head;
	int len = 0;
	while (len < n && cur) {
		len++;
		cur = cur->next;
	}
	return cur;
}

//����ĳ���ڵ�
ListNode* listFind(List* lst, LDataType val) {
	if (lst == NULL || lst->head->next == lst->head)
		return;
	ListNode* cur = lst->head->next;
	while (cur != lst->head) {
		if (cur->data == val)
			break;
		cur = cur->next;
	}
}

//������ĳ���
int listSize(List* lst) {
	if (lst == NULL || lst->head->next == lst->head)
		return 0;
	int len = 0;
	ListNode* cur = lst->head->next;
	while (cur != lst->head) {
		len++;
		cur = cur->next;
	}
	return len;
}

//��������
void listDestroy(List* lst) {
	if (lst == NULL || lst->head->next == lst->head)
		return;
	ListNode* cur = lst->head->next;
	while (cur != lst->head) {
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(lst->head);
	lst->head = NULL; 
}

void test() {
	List lst;
	listInit(&lst);//��ʼ������
	listPushBack(&lst, 1);//β��1
	//����Ϊ1
	printList(&lst); //��ӡ����
	listPushBack(&lst, 2);//β��2
	//����Ϊ1->2
	printList(&lst); //��ӡ����
	listPushFront(&lst, 0);//ͷ��0
	//����Ϊ0->1->2
	printList(&lst); //��ӡ����

	ListNode* cur = listFind(&lst, 1);//����ֵΪ1�Ľڵ�
	listInsert(&lst, cur, 11);//��ֵΪ1�Ľڵ�ǰ�Ĳ���11
	//����Ϊ0->11->1->2
	printList(&lst); //��ӡ����
	listInsert(&lst , lst.head, 13);//β��13
	//����Ϊ0->11->1->2->13
	printList(&lst); //��ӡ����

	listPopBack(&lst);//βɾ
	//����Ϊ0->11->1->2
	printList(&lst); //��ӡ����
	listPopFront(&lst);//ͷɾ
	//����Ϊ11->1->2
	printList(&lst); //��ӡ����
	cur = listFindByIdx(&lst, 1);
	listErase(&lst , cur);//ɾ��λ��Ϊ1�Ľڵ�
	//����Ϊ1->2
	printList(&lst); //��ӡ����
	listErase(&lst , lst.head->prev);//βɾ
	//����Ϊ1
	printList(&lst); //��ӡ����
	listDestroy(&lst);//��������
	printList(&lst); //��ӡ����

}

int main() {
	test();
	return 0;
}