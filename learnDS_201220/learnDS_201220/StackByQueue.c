#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"queue.h"
/*用队列实现栈*/


//实现栈
typedef struct {
	Queue q;
}MyStack;


//初始化栈
MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	queueInit(&obj->q);
	return obj;
}

//入栈
void myStackPush(MyStack* obj, int x) {
	//入队也就是入栈
	queuePush(&obj->q, x);
}

//出栈
int myStackPop(MyStack* obj) {
	//出栈操作相当于取出队尾元素
	int idx = queueSize(&obj->q);
	while (idx > 1) {
		int front = queueFront(&obj->q);
		queuePop(&obj->q);
		queuePush(&obj->q, front);
		idx--;
	}
	int front = queueFront(&obj->q);
	queuePop(&obj->q);
	return front;
}

//获取栈顶元素
int myStackTop(MyStack* obj) {
	//出栈操作相当于取出队尾元素
	return queueBack(&obj->q);
}

//判断栈是否为空
bool myStackEmpty(MyStack* obj) {
	return queueEmpty(&obj->q);
}

//销毁栈
void myStackFree(MyStack* obj) {
	queueDestroy(&obj->q);
	free(obj);
}