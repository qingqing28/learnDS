#pragma once
#include"BTNode.h"

//队列的单向无头非循环链表的实现
typedef BTNode* QDataType;
typedef struct QNode {
	QDataType data;
	struct QNode* next;
} QNode;  //队列中的链表节点

typedef struct Queue {
	QNode* front;  //指向队头
	QNode* rear;  //指向队尾
}Queue;

void queueInit(Queue* q);
QNode* creatNode(QDataType data);
void queuePush(Queue* q, QDataType data);
void queuePop(Queue* q);
QDataType queueFront(Queue* q);
QDataType queueBack(Queue* q);
int queueSize(Queue* q);
int queueEmpty(Queue* q);
void queueDestroy(Queue* q);
