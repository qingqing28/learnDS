#include<stdio.h>
#include<stdlib.h>

typedef int QDataType;

typedef struct Queue {
	QDataType* data;//�洢���е�����
	int rear;  //��ʾ��β��ָ��������һ��Ԫ�ص���һ��λ��
	int capacity;//��ʾ����Ĵ�С
}queue;

// ��ʼ������
void QueueInit(queue* q) {
	q->data = NULL;
	q->rear = 0;
	q->capacity = 0;
}
//�������
void checkCapacity(queue* q) {
	if (q == NULL)
		return;
	if (q->rear == q->capacity) {
		//��������
		int newCapacity = (q->capacity == 0) ? 1 : 2 * q->capacity;
		q->data = (QDataType*)realloc(q->data , sizeof(QDataType) * newCapacity);
		q->capacity = newCapacity;
	}
}

// ��β�����
void QueuePush(queue* q, QDataType data) {
	if (q == NULL)
		return;
	checkCapacity(q);
	q->data[q->rear] = data;
	q->rear++;
}

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0
int QueueEmpty(queue* q) {
	if (q->rear == 0)
		return 1;
	return 0;
}

// ��ͷ������(ͷ�壩
void QueuePop(queue* q) {
	if (q == NULL || QueueEmpty(q) == 1)
		return;
	//����������ƶ�
	for (int i = 1; i < q->rear; i++) {
		q->data[i - 1] = q->data[i];
	}
	q->rear--;
}

// ��ȡ����ͷ��Ԫ��
QDataType QueueFront(queue* q) {
	return q->data[0];
}
// ��ȡ���ж�βԪ��
QDataType QueueBack(queue* q) {
	return q->data[q->rear - 1];
}
// ��ȡ��������ЧԪ�ظ���
int QueueSize(queue* q) {
	return q->rear;
}

// ���ٶ���
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
	//����Ϊ1 2 3
	printf("��ͷ=%d\n", QueueFront(&q));//��ͷΪ1
	printf("��β=%d\n", QueueBack(&q));//��βΪ3
	printf("���г���=%d\n", QueueSize(&q));//���г���Ϊ3
	printf("�����Ƿ�Ϊ�գ�%d\n", QueueEmpty(&q));//���в�Ϊ��
	//����
	QueuePop(&q);
	printf("��ͷ=%d\n", QueueFront(&q));//��ͷΪ2
	printf("��β=%d\n", QueueBack(&q));//��βΪ3
	QueuePop(&q);
	printf("��ͷ=%d\n", QueueFront(&q));//��ͷΪ3
	printf("��β=%d\n", QueueBack(&q));//��βΪ3
	QueuePop(&q);
	printf("�����Ƿ�Ϊ�գ�%d\n", QueueEmpty(&q));//���в�Ϊ��
	return 0;
}