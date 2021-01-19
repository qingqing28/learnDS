#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stack.h"
//����ջ��ƥ������


bool isValid(char* s) {
	//����ջ
	Stack st;
	stackInit(&st);
	//����ӳ���ϵ
	char arr[][2] = { {'(' , ')'} ,
		{'[' , ']'},
		{'{' , '}'} };
	//�����ַ�������������ջ��������ƥ��
	while (*s) {
		int i;
		//�Ƿ�Ϊ������
		for (i = 0; i < 3; i++) {
			if (*s == arr[i][0]) {
				stackPush(&st, *s);
				break;
			}
		}
		//ѭ�����꣬˵������������
		if (i > 2) {
			//�õ�ǰ��������ƥ��ջ��Ԫ��
			if (stackEmpty(&st))
				return false;
			for (int j = 0; j < 3; j++) {
				if (*s == arr[j][1]) {
					//�ҵ����������ͣ��ж������Ƿ�ƥ��
					char c = stackTop(&st);
					if (c != arr[j][0])
						return false;
					else
						stackPop(&st);
				}

			}
		}
		s++;
	}
	//ջ��Ϊ�գ������Ų�ƥ��
	if (!stackEmpty(&st))
		return false;
	return true;
}