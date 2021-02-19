#include<stdio.h>
#include<stdlib.h>
#include"queue.h"

// ��ʼ������
void queueInit(Queue* q) {
	if (q == NULL)
		return;
	q->front = q->rear = NULL;
}
//����һ���µĽڵ�
QNode* creatNode(QDataType data) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;
	return node;
}

// ��β�����
void queuePush(Queue* q, QDataType data) {
	if (q == NULL)
		return;
	//��һ�����
	if (q->front == NULL) {
		q->front = q->rear = creatNode(data);
	}
	else {
		q->rear->next = creatNode(data);
		q->rear = q->rear->next;
	}
}

// ��ͷ������
void queuePop(Queue* q) {
	if (q == NULL || q->front == NULL)
		return;
	QNode* next = q->front->next;
	free(q->front);
	q->front = next;
	//��Ԫ�س��Ӻ󣬶���Ϊ��
	if (q->front == NULL)
		q->rear = NULL;
}

// ��ȡ����ͷ��Ԫ��
QDataType queueFront(Queue* q) {
	return q->front->data;
}
// ��ȡ���ж�βԪ��
QDataType queueBack(Queue* q) {
	return q->rear->data;
}
// ��ȡ��������ЧԪ�ظ���
int queueSize(Queue* q) {
	if (q == NULL)
		return 0;
	int size = 0;
	QNode* node = q->front;
	while (node) {
		size++;
		node = node->next;
	}
	return size;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int queueEmpty(Queue* q) {
	if (q->front == NULL)
		return 1;
	return 0;
}
// ���ٶ���
void queueDestroy(Queue* q) {
	QNode* cur = q->front;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->rear = NULL;
}
