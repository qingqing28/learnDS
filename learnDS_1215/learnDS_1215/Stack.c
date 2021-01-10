#include<stdio.h>
#include<stdlib.h>
#include"stack.h"


void stackInit1(Stack* st) {
	if (st == NULL)
		return;
	st->data = NULL;
	//栈中没有存储任何元素，栈顶指向-1
	st->top = -1;
	st->capacity = 0;
}

void checkCapacity1(Stack* st) {
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

void stackPush1(Stack* st, STDataType val) {
	if (st == NULL)
		return;
	//检查栈是否满了
	checkCapacity1(st);
	//进行入栈，栈顶+1 ，存入数据
	st->top++;
	st->data[st->top] = val;
}

void stackPop1(Stack* st) {
	//若栈中无数据则进行返回
	if (st == NULL || st->top == -1) {
		return;
	}
	//栈顶-1
	st->top--;
}

//获取栈顶元素
STDataType stackTop1(Stack* st) {
	//前提是栈中有有效元素
	return st->data[st->top];
}

//获取栈中的有效元素个数
int stackSize1(Stack* st) {
	if (st == NULL)
		return 0;
	return (st->top) + 1;
}

//检测栈是否为空，如果为空返回非零结果，如果不为空返回0
int stackEmpty1(Stack* st) {
	if (st == NULL || st->top == -1)
		return 1;
	return 0;
}

//销毁栈
void stackDestroy1(Stack* st) {
	free(st->data);
	st->data = NULL;
	st->top = -1;
	st->capacity = 0;
}

void test1() {
	Stack st;
	stackInit(&st);
	//入栈
	stackPush(&st, 0);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	//栈为0 1 2 3
	STDataType s = stackTop(&st);
	printf("%d ", s);
	stackPop(&st);
	//出栈，栈为0 1 2
	printf("%d ", stackSize(&st));//打印栈的大小--3
	printf("%d ", stackEmpty(&st));//0表示栈不为空
	stackDestroy(&st);//销毁栈
	printf("%d ", stackEmpty(&st));
}

int main2() {
	test1();
	return 0; 
}