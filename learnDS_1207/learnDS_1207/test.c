#include<stdio.h>
#include<stdlib.h>

int* addToArrayForm(int* A, int Asize, int k, int* returnSize) {
	/*A[1 2 0 0]
	* k = 34 
	* 首先进行循环，逐一相加，
	* 每次相加的结果应由：数组的相应位置、数字的相应位置、上一位置的进位
	* 从后先前累加，累加次数为数组长度和数字长度的最大值
	* 结果保存在一个数组中，数组长度为累加次数+1
	*/
	//1.首先统计k的位数
	int num = k;
	int len = 0;
	while(num){
		num = num / 10;
		len++;
	}
	int arrlen = Asize > len ? Asize+1 : len+1;
	int* ret = (int*)malloc(sizeof(int) * arrlen);

	int end = Asize - 1;
	int step = 0;
	int idx = 0;
	while (end >= 0 || k > 0) {
		int curret = step;
		if (end >= 0) {
			curret += A[end];
		}
		if (k > 0) {
			curret = curret + k % 10;
			
		}
		if (curret > 9) {
			curret -= 10;
			step = 1;
		}
		else {
			step = 0;
		}
		ret[idx++] = curret;
		end--;
		k = k / 10;
	}
	if (step == 1) {
		ret[idx++] = 1;
	}
	

	//将数组反置，得到最后的计算结果
	int start = 0;
	end = idx - 1;
	while (start < end) {
		int tmp = ret[start];
		ret[start] = ret[end];
		ret[end] = tmp;
	}
	*returnSize = idx ;
	return ret;
}