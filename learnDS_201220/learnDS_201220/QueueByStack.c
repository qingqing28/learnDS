#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stack.h"
/*用栈实现队列*/

typedef struct {
	Stack pushST;//将数据入此栈
	Stack popST;//数据从此栈弹出
}MyQueue;


//初始化队列
MyQueue* myQueueCreate() {
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	stackInit(&mq->pushST);
	stackInit(&mq->popST);
	return mq;
}

//数据入队
void myQueuePush(MyQueue* obj, int x) {
	stackPush(&obj->pushST, x);
}

/*数据出队 */
int myQueuePop(MyQueue* obj) {
	//如果popST数据为空，则将pushST中数据弹入popST中
	if (stackEmpty(&obj->popST)) {
		while (!stackEmpty(&obj->pushST)) {
			int top = stackTop(&obj->pushST);
			stackPop(&obj->pushST);
			stackPush(&obj->popST, top);
		}
	}
	//从popST中弹出数据
	int top = stackTop(&obj->popST);
	stackPop(&obj->popST);
	return top;
}

/** 获取队头元素 */
int myQueuePeek(MyQueue* obj) {
	//如果popST数据为空，则将pushST中数据弹入popST中
	if (stackEmpty(&obj->popST)) {
		while (!stackEmpty(&obj->pushST)) {
			int top = stackTop(&obj->pushST);
			stackPop(&obj->pushST);
			stackPush(&obj->popST, top);
		}
	}
	//从popST中弹出数据
	int top = stackTop(&obj->popST);
	return top;
}

/** 判断队列是否为空 */
bool myQueueEmpty(MyQueue* obj) {
	return stackEmpty(&obj->pushST) && stackEmpty(&obj->popST);
}

//销毁队列
void myQueueFree(MyQueue* obj) {
	stackDestroy(&obj->pushST);
	stackDestroy(&obj->popST);
	free(obj);
}