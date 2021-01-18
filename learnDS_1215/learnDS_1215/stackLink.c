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

//创建新的节点
ListNode* createListnode(STDataType val) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = val;
	node->prev = node->next = NULL;
}

//打印节点的值
void printListNode(ListNode* node) {
	printf("%d\n", node->data);
}
//初始化栈
void stackInit(Stack* st) {
	if (st == NULL)
		return;
	//使st->head成为一个带头单向循环链表
	st->head = createListnode(0);
	st->head->prev = st->head;
	st->head->next = st->head;

	st->top = st->head;
}

//入栈
void stackPush(Stack* st, STDataType val) {
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
void stackPop(Stack* st) {
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
STDataType stackTop(Stack* st) {
	//栈一定不为空栈
	if (st == NULL)
		return ; 
	return st->top;
}
//返回栈的长度
int stackSize(Stack* st) {
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
int stackEmpty(Stack* st) {
	if (st == NULL || st->top == st->head)
		return 1;
	return 0;
}

//销毁栈
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
	stackInit(&st);//初始化栈
	//入栈
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	//栈为1 2 3
	printListNode(stackTop(&st));//获取栈顶元素3
	stackPop(&st);//出栈，栈为1 2
	printf("%d \n", stackSize(&st));//栈的大小为2
	printListNode(stackTop(&st));//获取栈顶元素2
	stackPop(&st);//出栈，栈为1
	printf("%d\n" , stackEmpty(&st));//0表示栈不为空
	stackDestroy(&st);//销毁栈
	printf("%d", stackEmpty(&st));//1表示栈为空
}

int main3() {
	test3();
	return 0;
}