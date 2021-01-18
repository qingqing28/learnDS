#include<stdio.h>
#include<stdlib.h>

typedef int STDataType;
typedef struct LstkNode {
	STDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;
typedef struct Stack {
	ListNode* head;
	ListNode* top;
} Stack;

//�����µĽڵ�
ListNode* createListnode(STDataType val) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = val;
	node->prev = node->next = NULL;
}

//��ӡ�ڵ��ֵ
void printListNode(ListNode* node) {
	printf("%d\n", node->data);
}
//��ʼ��ջ
void stackInit(Stack* st) {
	if (st == NULL)
		return;
	//ʹst->head��Ϊһ����ͷ����ѭ������
	st->head = createListnode(0);
	st->head->prev = st->head;
	st->head->next = st->head;

	st->top = st->head;
}

//��ջ
void stackPush(Stack* st, STDataType val) {
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
void stackPop(Stack* st) {
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
STDataType stackTop(Stack* st) {
	//ջһ����Ϊ��ջ
	if (st == NULL)
		return ; 
	return st->top;
}
//����ջ�ĳ���
int stackSize(Stack* st) {
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
int stackEmpty(Stack* st) {
	if (st == NULL || st->top == st->head)
		return 1;
	return 0;
}

//����ջ
void stackDestroy(Stack* st) {
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

int test3() {
	Stack st;
	stackInit(&st);//��ʼ��ջ
	//��ջ
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	//ջΪ1 2 3
	printListNode(stackTop(&st));//��ȡջ��Ԫ��3
	stackPop(&st);//��ջ��ջΪ1 2
	printf("%d \n", stackSize(&st));//ջ�Ĵ�СΪ2
	printListNode(stackTop(&st));//��ȡջ��Ԫ��2
	stackPop(&st);//��ջ��ջΪ1
	printf("%d\n" , stackEmpty(&st));//0��ʾջ��Ϊ��
	stackDestroy(&st);//����ջ
	printf("%d", stackEmpty(&st));//1��ʾջΪ��
}

int main3() {
	test3();
	return 0;
}