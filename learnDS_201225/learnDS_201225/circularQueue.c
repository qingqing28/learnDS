#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int QDataType;
typedef struct {
	QDataType* data;
	int front;   //指向队列的队头
	int rear;   //指向队列的队尾的下一个位置
	int capacity;    //队列可存储数据的大小
}MyCircularQueue;

//创建一个循环队列
MyCircularQueue* myCircularQueueCreate(int capacity) {
	MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
	//为了区分满队列和空队列，这里多开一个内存
	obj->data = (QDataType*)malloc(sizeof(QDataType) * (capacity + 1));  
	obj->capacity = capacity;
	obj->front = obj->rear = 0;
	return obj;
}


bool myCricularQueueIsFull(MyCircularQueue* obj) {
	//如果队尾的下一个位置是队头，则表示队列已满
	//（队尾+1）%存储队列的数组大小 == 队头
	if ((obj->rear + 1) % (obj->capacity + 1) == obj->front)
		return true;
	return false;
}

//进行入队操作，并返回入队的结果
bool myCircularQueueEnQueue(MyCircularQueue* obj, QDataType value) {
	//如果队列满了，则入队失败
	if (myCricularQueueIsFull(obj))
		return false;
	//进行入队
	obj->data[obj->rear] = value;
	obj->rear++;
	//如果队尾发生数组越界，则使队尾指向data[0]
	if (obj->rear > obj->capacity) {
		obj->rear = 0;
	}
	return true;
}

bool myCircularIsEmpty(MyCircularQueue* obj) {
	//如果队尾==队头，则队列为空
	if (obj->front == obj->rear)
		return true;
	return false;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj) {
	//队列为空，则队列出队失败
	if (myCircularIsEmpty(obj))
		return false;
	//队列出队

	obj->front++;
	//判断队头是否越界，若是越界则使队头指向data[0]
	if (obj->front > obj->capacity){
		obj->front = 0;
	}
	return true;
}

//获取队头元素,获取失败返回-1
QDataType myCircularQueueFront(MyCircularQueue* obj) {
	if (myCircularIsEmpty(obj))
		return -1;
	return obj->data[obj->front];
}

//获取队尾元素，获取失败返回-1
QDataType myCircularQueueRear(MyCircularQueue* obj) {
	//若队列为空，则获取元素失败
	if (myCircularIsEmpty(obj))
		return -1;
	int idx = obj->rear - 1;
	if (idx < 0)
		idx = obj->capacity;
	return obj->data[idx];
}

//销毁队列
void myCircularQueueFree(MyCircularQueue* obj) {
	free(obj->data);
	free(obj);
}

void testCircularQueue() {
	MyCircularQueue* obj =myCircularQueueCreate(3);
	myCircularQueueEnQueue(obj, 1);
	//队列为1 
	printf("第一次入队后队头=%d\n" , myCircularQueueFront(obj));
	printf("第一次入队后队尾=%d\n", myCircularQueueRear(obj));
	printf("队列是否已满：%d\n", myCricularQueueIsFull(obj));//队列不为满，结果为0
	myCircularQueueEnQueue(obj, 2);
	//队列为1 2
	printf("第二次入队后队头=%d\n", myCircularQueueFront(obj));
	printf("第二次入队后队尾=%d\n", myCircularQueueRear(obj));
	myCircularQueueEnQueue(obj, 3);
	//队列为1 2 3 
	printf("第三次入队后队头=%d\n", myCircularQueueFront(obj));
	printf("第三次入队后队尾=%d\n", myCircularQueueRear(obj));
	printf("队列是否已满：%d\n", myCricularQueueIsFull(obj));
	printf("\n");

	myCircularQueueDeQueue(obj);
	//队列为2 3
	printf("第一次出队后队头=%d\n", myCircularQueueFront(obj));
	printf("第一次出队后队尾=%d\n", myCircularQueueRear(obj));
	myCircularQueueEnQueue(obj, 4);
	//队列为2 3 4 
	printf("第四次入队后队头=%d\n", myCircularQueueFront(obj));
	printf("第四次入队后队尾=%d\n", myCircularQueueRear(obj));
	printf("队列是否已满：%d\n", myCricularQueueIsFull(obj));//队列为满，结果为1
	printf("队列是否为空：%d\n", myCircularIsEmpty(obj));//队列不为空，结果为0
	printf("\n");

	myCircularQueueDeQueue(obj);
	//队列为3 4
	printf("第二次出队后队头=%d\n", myCircularQueueFront(obj));
	printf("第二次出队后队尾=%d\n", myCircularQueueRear(obj));
	myCircularQueueDeQueue(obj);
	//队列为4
	printf("第三次出队后队头=%d\n", myCircularQueueFront(obj));
	printf("第三次出队后队尾=%d\n", myCircularQueueRear(obj));
	myCircularQueueDeQueue(obj);
	printf("队列是否为空：%d\n", myCircularIsEmpty(obj));
	myCircularQueueFree(obj);
	
	return 0;
}