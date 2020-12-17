#include<stdio.h>
#include<stdlib.h>

void rotateOnes(int* nums, int numsSize) {
    int val = nums[numsSize - 1];
    //移动[0,n-2],从后向前移动
    for (int i = numsSize - 2; i >= 0; i--) {
        nums[i + 1] = nums[i];
    }
    nums[0] = val;
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    while (k--) {
        rotateOnes(nums, numsSize);
    }
}

int main3() {
    int nums[4] = { 1,2,3,4 };
    rotate(nums, sizeof(nums) / sizeof(nums[0]), 2);
    for (int i = 0; i < 4; i++) {
        printf("%d ", nums[i]);
    }
}
