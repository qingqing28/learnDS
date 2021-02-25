#include<stdio.h>
#include<stdlib.h>

/*选择排序:每一次从未排序的数据中找到一个最小的，
把最小的放到未排序的数据的头部，不断重复
*/
void selectSort(int* arr, int n) {
	//从未排序的序列中找到最值，存放到未排序的起始位置
	//未排序区间
	int start = 0; 
	int end = n - 1;
	while (start < end) {
		int minIdx = start;
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] < arr[minIdx])
				minIdx = i;
		}
		//把最小值存放在最开始的位置
		swap(arr, start, minIdx);
		//剩余的未排序区间[start + 1 , end]
		start++;
	}
}

void testSelectSort() {
	int arr[] = { 9 ,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selectSort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}