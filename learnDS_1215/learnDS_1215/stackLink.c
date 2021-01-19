#include<stdio.h>
#include<stdlib.h>

//链表实现栈
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

//创建新的节点
ListNode* createListnode(STDataType val) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = val;
	node->prev = node->next = NULL;
}

//打印节点的值
void printListNode(ListNode* node) {
	printf("栈顶元素=%d\n", node->data);
}
//初始化栈
void stackLinkInit(stack* st) {
	if (st == NULL)
		return;
	//使st->head成为一个带头单向循环链表
	st->head = createListnode(0);
	st->head->prev = st->head;
	st->head->next = st->head;

	st->top = st->head;
}

//入栈
void stackLinkPush(stack* st, STDataType val) {
	if (st == NULL)
		return;
	ListNode* node = createListnode(val);
	//进行头插操作
	node->next = st->top;
	st->top->prev = node;

	st->head->next = node;
	node->prev = st->head;

	//修改栈顶
	st->top = node;
}

//出栈
void stackLinkPop(stack* st) {
	if (st == NULL || st->top == st->head)
		return;
	ListNode* next = st->top->next;
	//进行头删操作
	st->head->next = next;
	next->prev = st->head;
	//修改栈顶
	st->top = next;
}

//获取栈顶元素
STDataType stackLinkTop(stack* st) {
	//栈一定不为空栈
	if (st == NULL)
		return ; 
	return st->top;
}
//返回栈的长度
int stackLinkSize(stack* st) {
	if (st == NULL || st->top == st->head)
		return 0;
	int k = 0;
	ListNode* cur = st->top;
	//遍历整个链表，统计栈的长度
	while (cur != st->head) {
		k++;
		cur = cur->next;
	}
	return k;
}

//判断栈是否为空
int stackLinkEmpty(stack* st) {
	if (st == NULL || st->top == st->head)
		return 1;
	return 0;
}

//销毁栈
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
	stackLinkInit(&st);//初始化栈
	//入栈
	stackLinkPush(&st, 1);
	stackLinkPush(&st, 2);
	stackLinkPush(&st, 3);
	//栈为1 2 3
	printListNode(stackLinkTop(&st));//获取栈顶元素3
	stackLinkPop(&st);//出栈，栈为1 2
	printf("栈的大小=%d \n", stackLinkSize(&st));//栈的大小为2
	printListNode(stackLinkTop(&st));//获取栈顶元素2
	stackLinkPop(&st);//出栈，栈为1
	printf("栈是否为空：%d\n" , stackLinkEmpty(&st));//0表示栈不为空
	stackLinkDestroy(&st);//销毁栈
	printf("栈是否为空：%d", stackLinkEmpty(&st));//1表示栈为空
}

