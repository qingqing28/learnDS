#include<stdio.h>
#include<stdlib.h>

void merge1(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int* nums3 = (int*)malloc(sizeof(int) * (m + n));
    int idx, idx1, idx2;
    idx = idx1 = idx2 = 0;
    while (idx1 < m && idx2 < n) {
        if (nums1[idx1] <= nums2[idx2]) {
            nums3[idx++] = nums1[idx1++];
        }
        else {
            nums3[idx++] = nums2[idx2++];
        }
    }
    if (idx1 < m) {
        memcpy(nums3 + idx, nums1 + idx1, sizeof(int) * (m - idx1));
    }
    if (idx2 < n) {
        memcpy(nums3 + idx, nums2 + idx2, sizeof(int) * (n - idx2));
    }
    memcpy(nums1, nums3, sizeof(int) * (m + n));
    free(nums3);
}

