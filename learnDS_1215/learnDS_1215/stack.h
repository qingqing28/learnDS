typedef int STDataType;
//数组为静态数组，无法进行扩容
//#define N 10
//typedef struct Stack
//{
//	STDataType a[N];
//	int top; // 栈顶
//}Stack;


typedef struct Stack {
	STDataType* data;  //数组
	int top;      //栈顶指针
	int capacity;    //数组的容量
}Stack;

void stackInit(Stack* st);
void checkCapacity(Stack* st);
void stackPush(Stack* st, STDataType val);
void stackPop(Stack* st);
STDataType stackTop(Stack* st);
int stackSize(Stack* st);
int stackEmpty(Stack* st);
//销毁栈
void stackDestroy(Stack* st);