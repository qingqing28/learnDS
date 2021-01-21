typedef int QDataType;
typedef struct {
	QDataType* data;
	int front;   //ָ����еĶ�ͷ
	int rear;   //ָ����еĶ�β����һ��λ��
	int capacity;    //���пɴ洢���ݵĴ�С
}MyCircularQueue;

MyCircularQueue* myCircularQueueCreate(int capacity);
bool myCricularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueEnQueue(MyCircularQueue* obj, QDataType value);
bool myCircularIsEmpty(MyCircularQueue* obj);
bool myCircularQueueDeQueue(MyCircularQueue* obj);
QDataType myCircularQueueFront(MyCircularQueue* obj);
QDataType myCircularQueueRear(MyCircularQueue* obj);
void myCircularQueueFree(MyCircularQueue* obj)