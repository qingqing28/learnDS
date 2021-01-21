typedef int QDataType;
typedef struct {
	QDataType* data;
	int front;   //指向队列的队头
	int rear;   //指向队列的队尾的下一个位置
	int capacity;    //队列可存储数据的大小
}MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int capacity);
bool myCricularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueEnQueue(MyCircularQueue* obj, QDataType value);
bool myCircularIsEmpty(MyCircularQueue* obj);
bool myCircularQueueDeQueue(MyCircularQueue* obj);
QDataType myCircularQueueFront(MyCircularQueue* obj);
QDataType myCircularQueueRear(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj)