typedef int STDataType;
//����Ϊ��̬���飬�޷���������
//#define N 10
//typedef struct Stack
//{
//	STDataType a[N];
//	int top; // ջ��
//}Stack;


typedef struct Stack {
	STDataType* data;  //����
	int top;      //ջ��ָ��
	int capacity;    //���������
}Stack;

void stackInit(Stack* st);
void checkCapacity(Stack* st);
void stackPush(Stack* st, STDataType val);
void stackPop(Stack* st);
STDataType stackTop(Stack* st);
int stackSize(Stack* st);
int stackEmpty(Stack* st);
//����ջ
void stackDestroy(Stack* st);