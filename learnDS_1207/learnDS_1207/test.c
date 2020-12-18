#include<stdio.h>
#include<stdlib.h>

int* addToArrayForm(int* A, int Asize, int k, int* returnSize) {
	/*A[1 2 0 0]
	* k = 34 
	* ���Ƚ���ѭ������һ��ӣ�
	* ÿ����ӵĽ��Ӧ�ɣ��������Ӧλ�á����ֵ���Ӧλ�á���һλ�õĽ�λ
	* �Ӻ���ǰ�ۼӣ��ۼӴ���Ϊ���鳤�Ⱥ����ֳ��ȵ����ֵ
	* ���������һ�������У����鳤��Ϊ�ۼӴ���+1
	*/
	//1.����ͳ��k��λ��
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
	

	//�����鷴�ã��õ����ļ�����
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