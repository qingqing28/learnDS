#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"queue.h"
/*�ö���ʵ��ջ*/


//ʵ��ջ
typedef struct {
	Queue q;
}MyStack;


//��ʼ��ջ
MyStack* myStackCreate() {
	MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
	queueInit(&obj->q);
	return obj;
}

//��ջ
void myStackPush(MyStack* obj, int x) {
	//���Ҳ������ջ
	queuePush(&obj->q, x);
}

//��ջ
int myStackPop(MyStack* obj) {
	//��ջ�����൱��ȡ����βԪ��
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

//��ȡջ��Ԫ��
int myStackTop(MyStack* obj) {
	//��ջ�����൱��ȡ����βԪ��
	return queueBack(&obj->q);
}

//�ж�ջ�Ƿ�Ϊ��
bool myStackEmpty(MyStack* obj) {
	return queueEmpty(&obj->q);
}

//����ջ
void myStackFree(MyStack* obj) {
	queueDestroy(&obj->q);
	free(obj);
}