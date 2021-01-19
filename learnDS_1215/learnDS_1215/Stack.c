#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

//动态数组实现栈
void stackInit(Stack* st) {
	if (st == NULL)
		return;
	st->data = NULL;
	//栈中没有存储任何元素，栈顶指向-1
	st->top = -1;
	st->capacity = 0;
}

void checkCapacity(Stack* st) {
	if (st == NULL)
		return;
	//若数组存储满了，则进行扩容
	if (st->top == (st->capacity) - 1) {
		int newCapacity = st->capacity == 0 ? 1 : st->capacity * 2;
		//将st->data数组扩容到sizeof(STDataType)*newCapacity个字节大小
		st->data = (STDataType*)realloc(st->data, sizeof(STDataType)*newCapacity);
		st->capacity = newCapacity;
	}
}

void stackPush(Stack* st, STDataType val) {
	if (st == NULL)
		return;
	//检查栈是否满了
	checkCapacity(st);
	//进行入栈，栈顶+1 ，存入数据
	st->top++;
	st->data[st->top] = val;
}

void stackPop(Stack* st) {
	//若栈中无数据则进行返回
	if (st == NULL || st->top == -1) {
		return;
	}
	//栈顶-1
	st->top--;
}

//获取栈顶元素
STDataType stackTop(Stack* st) {
	//前提是栈中有有效元素
	return st->data[st->top];
}

//获取栈中的有效元素个数
int stackSize(Stack* st) {
	if (st == NULL)
		return 0;
	return (st->top) + 1;
}

//检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int stackEmpty(Stack* st) {
	if (st == NULL || st->top == -1)
		return 1;
	return 0;
}

//销毁栈
void stackDestroy(Stack* st) {
	free(st->data);
	st->data = NULL;
	st->top = -1;
	st->capacity = 0;
}

void testStack() {
	Stack st;
	stackInit(&st);
	//入栈
	stackPush(&st, 0);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	//栈为0 1 2 3
	STDataType s = stackTop(&st);
	printf("栈顶元素=%d\n", s);
	stackPop(&st);
	//出栈，栈为0 1 2
	printf("栈的大小=%d\n", stackSize(&st));//打印栈的大小--3
	printf("栈是否为空：%d\n", stackEmpty(&st));//0表示栈不为空
	stackDestroy(&st);//销毁栈
	printf("栈是否为空%d\n", stackEmpty(&st));
}
