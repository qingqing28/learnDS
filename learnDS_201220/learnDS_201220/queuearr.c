#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;

typedef struct Queue {
	QDataType* data;//存储队列的数据
	int rear;  //表示队尾，指向队列最后一个元素的下一个位置
	int capacity;//表示数组的大小
}queue;

// 初始化队列
void QueueInit(queue* q) {
	q->data = NULL;
	q->rear = 0;
	q->capacity = 0;
}
//检查容量
void checkCapacity(queue* q) {
	if (q == NULL)
		return;
	if (q->rear == q->capacity) {
		//进行扩容
		int newCapacity = (q->capacity == 0) ? 1 : 2 * q->capacity;
		q->data = (QDataType*)realloc(q->data , sizeof(QDataType) * newCapacity);
		q->capacity = newCapacity;
	}
}

// 队尾入队列
void QueuePush(queue* q, QDataType data) {
	if (q == NULL)
		return;
	checkCapacity(q);
	q->data[q->rear] = data;
	q->rear++;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(queue* q) {
	if (q->rear == 0)
		return 1;
	return 0;
}

// 队头出队列(头插）
void QueuePop(queue* q) {
	if (q == NULL || QueueEmpty(q) == 1)
		return;
	//将数据向后移动
	for (int i = 1; i < q->rear; i++) {
		q->data[i - 1] = q->data[i];
	}
	q->rear--;
}

// 获取队列头部元素
QDataType QueueFront(queue* q) {
	return q->data[0];
}
// 获取队列队尾元素
QDataType QueueBack(queue* q) {
	return q->data[q->rear - 1];
}
// 获取队列中有效元素个数
int QueueSize(queue* q) {
	return q->rear;
}

// 销毁队列
void QueueDestroy(queue* q) {
	free(q->data);
	q->data = NULL;
	q->capacity = 0;
	q->rear = 0;
}

int testQueueArr(){
	queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	//队列为1 2 3
	printf("队头=%d\n", QueueFront(&q));//队头为1
	printf("队尾=%d\n", QueueBack(&q));//队尾为3
	printf("队列长度=%d\n", QueueSize(&q));//队列长度为3
	printf("队列是否为空：%d\n", QueueEmpty(&q));//队列不为空
	//出队
	QueuePop(&q);
	printf("队头=%d\n", QueueFront(&q));//队头为2
	printf("队尾=%d\n", QueueBack(&q));//队尾为3
	QueuePop(&q);
	printf("队头=%d\n", QueueFront(&q));//队头为3
	printf("队尾=%d\n", QueueBack(&q));//队尾为3
	QueuePop(&q);
	printf("队列是否为空：%d\n", QueueEmpty(&q));//队列不为空
	return 0;
}