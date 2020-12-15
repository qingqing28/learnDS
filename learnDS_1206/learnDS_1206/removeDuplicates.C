#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    if (nums == NULL || numsSize < 2)
        return numsSize;
    int start, end, idx;
    start = 0;
    end = 1;
    idx = 0;
    //������������
    while (end < numsSize) {
        //�ж�nums[end]��nums[start]�Ƿ����
        //�����end����ƶ�
        //�����򱣴�nums[start]��ֵ
        if (nums[start] != nums[end]) {
            nums[idx++] = nums[start];
            start = end;
            end++;
        }
        else {
            while (end < numsSize && nums[start] == nums[end]) {
                end++;
            }
        }
    }
    if (start < numsSize)
        nums[idx++] = nums[start];
    return idx;
}

int main2() {
    int nums[2] = { 1,1 };
    int len = removeDuplicates(nums, sizeof(nums) / sizeof(nums[0]));
    for (int i = 0; i < len; i++)
        printf("%d ", nums[i]);
    return 0;
}