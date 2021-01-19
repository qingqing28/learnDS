#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"stack.h"
//借助栈来匹配括号


bool isValid(char* s) {
	//定义栈
	Stack st;
	stackInit(&st);
	//定义映射关系
	char arr[][2] = { {'(' , ')'} ,
		{'[' , ']'},
		{'{' , '}'} };
	//遍历字符串，左括号入栈，右括号匹配
	while (*s) {
		int i;
		//是否为左括号
		for (i = 0; i < 3; i++) {
			if (*s == arr[i][0]) {
				stackPush(&st, *s);
				break;
			}
		}
		//循环走完，说明不是左括号
		if (i > 2) {
			//让当前的右括号匹配栈顶元素
			if (stackEmpty(&st))
				return false;
			for (int j = 0; j < 3; j++) {
				if (*s == arr[j][1]) {
					//找到右括号类型，判断左右是否匹配
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
	//栈不为空，则括号不匹配
	if (!stackEmpty(&st))
		return false;
	return true;
}