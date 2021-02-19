#pragma once
#include"BTNode.h"

//���еĵ�����ͷ��ѭ�������ʵ��
typedef BTNode* QDataType;
typedef struct QNode {
	QDataType data;
	struct QNode* next;
} QNode;  //�����е�����ڵ�

typedef struct Queue {
	QNode* front;  //ָ���ͷ
	QNode* rear;  //ָ���β
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
