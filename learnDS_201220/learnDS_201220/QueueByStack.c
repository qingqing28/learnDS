#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stack.h"
/*��ջʵ�ֶ���*/

typedef struct {
	Stack pushST;//���������ջ
	Stack popST;//���ݴӴ�ջ����
}MyQueue;


//��ʼ������
MyQueue* myQueueCreate() {
	MyQueue* mq = (MyQueue*)malloc(sizeof(MyQueue));
	stackInit(&mq->pushST);
	stackInit(&mq->popST);
	return mq;
}

//�������
void myQueuePush(MyQueue* obj, int x) {
	stackPush(&obj->pushST, x);
}

/*���ݳ��� */
int myQueuePop(MyQueue* obj) {
	//���popST����Ϊ�գ���pushST�����ݵ���popST��
	if (stackEmpty(&obj->popST)) {
		while (!stackEmpty(&obj->pushST)) {
			int top = stackTop(&obj->pushST);
			stackPop(&obj->pushST);
			stackPush(&obj->popST, top);
		}
	}
	//��popST�е�������
	int top = stackTop(&obj->popST);
	stackPop(&obj->popST);
	return top;
}

/** ��ȡ��ͷԪ�� */
int myQueuePeek(MyQueue* obj) {
	//���popST����Ϊ�գ���pushST�����ݵ���popST��
	if (stackEmpty(&obj->popST)) {
		while (!stackEmpty(&obj->pushST)) {
			int top = stackTop(&obj->pushST);
			stackPop(&obj->pushST);
			stackPush(&obj->popST, top);
		}
	}
	//��popST�е�������
	int top = stackTop(&obj->popST);
	return top;
}

/** �ж϶����Ƿ�Ϊ�� */
bool myQueueEmpty(MyQueue* obj) {
	return stackEmpty(&obj->pushST) && stackEmpty(&obj->popST);
}

//���ٶ���
void myQueueFree(MyQueue* obj) {
	stackDestroy(&obj->pushST);
	stackDestroy(&obj->popST);
	free(obj);
}