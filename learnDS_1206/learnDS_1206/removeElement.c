#include<stdio.h>
#include<stdlib.h>

int removeElement(int* nums, int numsSize, int val) {
    int i, idx = 0;
    //������������
    for (i = 0; i < numsSize; i++) {
        //Ԫ��ֵΪval������ѭ��
        //Ԫ��ֵ��Ϊval�򱣴���nums[idx]��
        if (nums[i] != val) {
            nums[idx++] = nums[i];
        }
    }
    return idx;
}

int main1() {
    int nums[5] = { 1 ,4 , 2, 3, 3 };
    int len = removeElement(nums , sizeof(nums)/sizeof(nums[0]) , 3);
    printf("%d \n", len);
    for (int i = 0; i < len; i++) {
        printf("%d ", nums[i]);
    }
}