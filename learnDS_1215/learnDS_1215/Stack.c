#include<stdio.h>
#include<stdlib.h>
#include"stack.h"


void stackInit1(Stack* st) {
	if (st == NULL)
		return;
	st->data = NULL;
	//ջ��û�д洢�κ�Ԫ�أ�ջ��ָ��-1
	st->top = -1;
	st->capacity = 0;
}

void checkCapacity1(Stack* st) {
	if (st == NULL)
		return;
	//������洢���ˣ����������
	if (st->top == (st->capacity) - 1) {
		int newCapacity = st->capacity == 0 ? 1 : st->capacity * 2;
		//��st->data�������ݵ�sizeof(STDataType)*newCapacity���ֽڴ�С
		st->data = (STDataType*)realloc(st->data, sizeof(STDataType)*newCapacity);
		st->capacity = newCapacity;
	}
}

void stackPush1(Stack* st, STDataType val) {
	if (st == NULL)
		return;
	//���ջ�Ƿ�����
	checkCapacity1(st);
	//������ջ��ջ��+1 ����������
	st->top++;
	st->data[st->top] = val;
}

void stackPop1(Stack* st) {
	//��ջ������������з���
	if (st == NULL || st->top == -1) {
		return;
	}
	//ջ��-1
	st->top--;
}

//��ȡջ��Ԫ��
STDataType stackTop1(Stack* st) {
	//ǰ����ջ������ЧԪ��
	return st->data[st->top];
}

//��ȡջ�е���ЧԪ�ظ���
int stackSize1(Stack* st) {
	if (st == NULL)
		return 0;
	return (st->top) + 1;
}

//���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0
int stackEmpty1(Stack* st) {
	if (st == NULL || st->top == -1)
		return 1;
	return 0;
}

//����ջ
void stackDestroy1(Stack* st) {
	free(st->data);
	st->data = NULL;
	st->top = -1;
	st->capacity = 0;
}

void test1() {
	Stack st;
	stackInit(&st);
	//��ջ
	stackPush(&st, 0);
	stackPush(&st, 1);
	stackPush(&st, 2);
	stackPush(&st, 3);
	//ջΪ0 1 2 3
	STDataType s = stackTop(&st);
	printf("%d ", s);
	stackPop(&st);
	//��ջ��ջΪ0 1 2
	printf("%d ", stackSize(&st));//��ӡջ�Ĵ�С--3
	printf("%d ", stackEmpty(&st));//0��ʾջ��Ϊ��
	stackDestroy(&st);//����ջ
	printf("%d ", stackEmpty(&st));
}

int main2() {
	test1();
	return 0; 
}