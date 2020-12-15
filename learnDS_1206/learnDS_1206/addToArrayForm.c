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
    //计算数字有多少位
    int len = 0;
    int tmp = K;
    while (tmp) {
        tmp = tmp / 10;
        len++;
    }

    //开辟数组ret，保存计算结果
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
        //判断是否有进位
        if (curRet > 9) {
            tmp = 1;
            curRet -= 10;
        }
        else {
            tmp = 0;
        }
        //保存结果
        ret[idx] = curRet;
        idx++;
        //printf("%d  " , curRet);
        //更新循环变量
        K = K / 10;
    }
    //判断最高位是否有进位
    if (tmp > 0) {
        ret[idx++] = 1;
    }
    //逆转数组
    reverse(ret, 0, idx - 1);
    *returnSize = idx;
    return ret;
}