#include<stdio.h>
#include<stdlib.h>
void reverse(int* nums, int start, int end) {
    while (start < end) {
        int tmp = nums[start];
        nums[start] = nums[end];
        nums[end] = tmp;
        start++;
        end--;
    }
}

int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    //���������ж���λ
    int len = 0;
    int tmp = K;
    while (tmp) {
        tmp = tmp / 10;
        len++;
    }

    //��������ret�����������
    int* ret = (int*)malloc(sizeof(int) * (ASize >= len ? ASize + 1 : len + 1));
    int end = ASize - 1, idx = 0;
    tmp = 0;
    while (end >= 0 || K > 0) {
        int curRet = tmp;
        if (end >= 0) {
            curRet += A[end--];
        }
        if (K > 0) {
            curRet += K % 10;
        }
        //�ж��Ƿ��н�λ
        if (curRet > 9) {
            tmp = 1;
            curRet -= 10;
        }
        else {
            tmp = 0;
        }
        //������
        ret[idx] = curRet;
        idx++;
        //printf("%d  " , curRet);
        //����ѭ������
        K = K / 10;
    }
    //�ж����λ�Ƿ��н�λ
    if (tmp > 0) {
        ret[idx++] = 1;
    }
    //��ת����
    reverse(ret, 0, idx - 1);
    *returnSize = idx;
    return ret;
}