#include<stdio.h>
#include<stdlib.h>

//����ʵ��ջ
typedef int STDataType;
typedef struct LstkNode {
	STDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;
typedef struct Stack {
	ListNode* head;
	ListNode* top;
} stack;

//�����µĽڵ�
ListNode* createListnode(STDataType val) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = val;
	node->prev = node->next = NULL;
}

//��ӡ�ڵ��ֵ
void printListNode(ListNode* node) {
	printf("ջ��Ԫ��=%d\n", node->data);
}
//��ʼ��ջ
void stackLinkInit(stack* st) {
	if (st == NULL)
		return;
	//ʹst->head��Ϊһ����ͷ����ѭ������
	st->head = createListnode(0);
	st->head->prev = st->head;
	st->head->next = st->head;

	st->top = st->head;
}

//��ջ
void stackLinkPush(stack* st, STDataType val) {
	if (st == NULL)
		return;
	ListNode* node = createListnode(val);
	//����ͷ�����
	node->next = st->top;
	st->top->prev = node;

	st->head->next = node;
	node->prev = st->head;

	//�޸�ջ��
	st->top = node;
}

//��ջ
void stackLinkPop(stack* st) {
	if (st == NULL || st->top == st->head)
		return;
	ListNode* next = st->top->next;
	//����ͷɾ����
	st->head->next = next;
	next->prev = st->head;
	//�޸�ջ��
	st->top = next;
}

//��ȡջ��Ԫ��
STDataType stackLinkTop(stack* st) {
	//ջһ����Ϊ��ջ
	if (st == NULL)
		return ; 
	return st->top;
}
//����ջ�ĳ���
int stackLinkSize(stack* st) {
	if (st == NULL || st->top == st->head)
		return 0;
	int k = 0;
	ListNode* cur = st->top;
	//������������ͳ��ջ�ĳ���
	while (cur != st->head) {
		k++;
		cur = cur->next;
	}
	return k;
}

//�ж�ջ�Ƿ�Ϊ��
int stackLinkEmpty(stack* st) {
	if (st == NULL || st->top == st->head)
		return 1;
	return 0;
}

//����ջ
void stackLinkDestroy(stack* st) {
	if (st == NULL)
		return;
	ListNode* cur = st->head->next;
	while (cur != st->head) {
		ListNode* next = cur->next;
		st->head->next = next;
		next->prev = st->head;
		free(cur);
		cur = next;
	}
	free(st->head);
	st->head = NULL;
	st->top = NULL;
}

int testStackLink() {
	stack st;
	stackLinkInit(&st);//��ʼ��ջ
	//��ջ
	stackLinkPush(&st, 1);
	stackLinkPush(&st, 2);
	stackLinkPush(&st, 3);
	//ջΪ1 2 3
	printListNode(stackLinkTop(&st));//��ȡջ��Ԫ��3
	stackLinkPop(&st);//��ջ��ջΪ1 2
	printf("ջ�Ĵ�С=%d \n", stackLinkSize(&st));//ջ�Ĵ�СΪ2
	printListNode(stackLinkTop(&st));//��ȡջ��Ԫ��2
	stackLinkPop(&st);//��ջ��ջΪ1
	printf("ջ�Ƿ�Ϊ�գ�%d\n" , stackLinkEmpty(&st));//0��ʾջ��Ϊ��
	stackLinkDestroy(&st);//����ջ
	printf("ջ�Ƿ�Ϊ�գ�%d", stackLinkEmpty(&st));//1��ʾջΪ��
}

