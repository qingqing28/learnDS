#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct {
	QDataType* data;
	int front;   //ָ����еĶ�ͷ
	int rear;   //ָ����еĶ�β����һ��λ��
	int capacity;    //���пɴ洢���ݵĴ�С
}MyCircularQueue;

//����һ��ѭ������
MyCircularQueue* myCircularQueueCreate(int capacity) {
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	//Ϊ�����������кͿն��У�����࿪һ���ڴ�
	obj->data = (QDataType*)malloc(sizeof(QDataType) * (capacity + 1));  
	obj->capacity = capacity;
	obj->front = obj->rear = 0;
	return obj;
}


bool myCricularQueueIsFull(MyCircularQueue* obj) {
	//�����β����һ��λ���Ƕ�ͷ�����ʾ��������
	//����β+1��%�洢���е������С == ��ͷ
	if ((obj->rear + 1) % (obj->capacity + 1) == obj->front)
		return true;
	return false;
}

//������Ӳ�������������ӵĽ��
bool myCircularQueueEnQueue(MyCircularQueue* obj, QDataType value) {
	//����������ˣ������ʧ��
	if (myCricularQueueIsFull(obj))
		return false;
	//�������
	obj->data[obj->rear] = value;
	obj->rear++;
	//�����β��������Խ�磬��ʹ��βָ��data[0]
	if (obj->rear > obj->capacity) {
		obj->rear = 0;
	}
	return true;
}

bool myCircularIsEmpty(MyCircularQueue* obj) {
	//�����β==��ͷ�������Ϊ��
	if (obj->front == obj->rear)
		return true;
	return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//����Ϊ�գ�����г���ʧ��
	if (myCircularIsEmpty(obj))
		return false;
	//���г���

	obj->front++;
	//�ж϶�ͷ�Ƿ�Խ�磬����Խ����ʹ��ͷָ��data[0]
	if (obj->front > obj->capacity){
		obj->front = 0;
	}
	return true;
}

//��ȡ��ͷԪ��,��ȡʧ�ܷ���-1
QDataType myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularIsEmpty(obj))
		return -1;
	return obj->data[obj->front];
}

//��ȡ��βԪ�أ���ȡʧ�ܷ���-1
QDataType myCircularQueueRear(MyCircularQueue* obj) {
	//������Ϊ�գ����ȡԪ��ʧ��
	if (myCircularIsEmpty(obj))
		return -1;
	int idx = obj->rear - 1;
	if (idx < 0)
		idx = obj->capacity;
	return obj->data[idx];
}

//���ٶ���
void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}

void testCircularQueue() {
	MyCircularQueue* obj =myCircularQueueCreate(3);
	myCircularQueueEnQueue(obj, 1);
	//����Ϊ1 
	printf("��һ����Ӻ��ͷ=%d\n" , myCircularQueueFront(obj));
	printf("��һ����Ӻ��β=%d\n", myCircularQueueRear(obj));
	printf("�����Ƿ�������%d\n", myCricularQueueIsFull(obj));//���в�Ϊ�������Ϊ0
	myCircularQueueEnQueue(obj, 2);
	//����Ϊ1 2
	printf("�ڶ�����Ӻ��ͷ=%d\n", myCircularQueueFront(obj));
	printf("�ڶ�����Ӻ��β=%d\n", myCircularQueueRear(obj));
	myCircularQueueEnQueue(obj, 3);
	//����Ϊ1 2 3 
	printf("��������Ӻ��ͷ=%d\n", myCircularQueueFront(obj));
	printf("��������Ӻ��β=%d\n", myCircularQueueRear(obj));
	printf("�����Ƿ�������%d\n", myCricularQueueIsFull(obj));
	printf("\n");

	myCircularQueueDeQueue(obj);
	//����Ϊ2 3
	printf("��һ�γ��Ӻ��ͷ=%d\n", myCircularQueueFront(obj));
	printf("��һ�γ��Ӻ��β=%d\n", myCircularQueueRear(obj));
	myCircularQueueEnQueue(obj, 4);
	//����Ϊ2 3 4 
	printf("���Ĵ���Ӻ��ͷ=%d\n", myCircularQueueFront(obj));
	printf("���Ĵ���Ӻ��β=%d\n", myCircularQueueRear(obj));
	printf("�����Ƿ�������%d\n", myCricularQueueIsFull(obj));//����Ϊ�������Ϊ1
	printf("�����Ƿ�Ϊ�գ�%d\n", myCircularIsEmpty(obj));//���в�Ϊ�գ����Ϊ0
	printf("\n");

	myCircularQueueDeQueue(obj);
	//����Ϊ3 4
	printf("�ڶ��γ��Ӻ��ͷ=%d\n", myCircularQueueFront(obj));
	printf("�ڶ��γ��Ӻ��β=%d\n", myCircularQueueRear(obj));
	myCircularQueueDeQueue(obj);
	//����Ϊ4
	printf("�����γ��Ӻ��ͷ=%d\n", myCircularQueueFront(obj));
	printf("�����γ��Ӻ��β=%d\n", myCircularQueueRear(obj));
	myCircularQueueDeQueue(obj);
	printf("�����Ƿ�Ϊ�գ�%d\n", myCircularIsEmpty(obj));
	myCircularQueueFree(obj);
	
	return 0;
}