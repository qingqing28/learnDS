#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;

typedef struct QNode {
	QDataType data;
	struct QNode* next;
} QNode;  //队列中的链表节点

typedef struct Queue {
	QNode* front;  //指向队头
	QNode* rear;  //指向队尾
}Queue;


// 初始化队列
void queueInit(Queue* q) {
	if (q == NULL)
		return;
	q->front = q->rear = NULL;
}
//创建一个新的节点
QNode* creatNode(QDataType data) {
	QNode* node = (QNode*)malloc(sizeof(QNode));
	node->data = data;
	node->next = NULL;
	return node;
}

// 队尾入队列
void queuePush(Queue* q, QDataType data) {
	if (q == NULL)
		return;
	//第一次入队
	if (q->front == NULL) {
		q->front = q->rear = creatNode(data);
	}
	else {
		q->rear->next = creatNode(data);
		q->rear = q->rear->next;
	}
}

// 队头出队列
void queuePop(Queue* q) {
	if (q == NULL || q->front == NULL)
		return;
	QNode* next = q->front->next;
	free(q->front);
	q->front = next;
	//若元素出队后，队列为空
	if (q->front == NULL)
		q->rear = NULL;
}

// 获取队列头部元素
QDataType queueFront(Queue* q) {
	return q->front->data;
}
// 获取队列队尾元素
QDataType queueBack(Queue* q) {
	return q->rear->data;
}
// 获取队列中有效元素个数
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

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int queueEmpty(Queue* q) {
	if (q->front == NULL)
		return 1;
	return 0;
}
// 销毁队列
void queueDestroy(Queue* q) {
	QNode* cur = q->front;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	q->front = q->rear = NULL;
}

int main1() {
	Queue q;
	queueInit(&q);
	queuePush(&q, 1);
	queuePush(&q, 2);
	queuePush(&q, 3);
	//队列为1 2 3
	printf("队头=%d\n",queueFront(&q));//队头为1
	printf("队尾=%d\n", queueBack(&q));//队尾为3
	printf("队列长度=%d\n", queueSize(&q));//队列长度为3
	printf("队列是否为空：%d\n", queueEmpty(&q));//队列不为空
	//出队
	queuePop(&q);
	queuePop(&q);
	queuePop(&q);
	queueDestroy(&q);
	return 0;
}