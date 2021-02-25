#include<stdio.h>
#include<stdlib.h>

void selectSort2(int* arr, int n) {
	int start = 0;
	int end = n - 1;
	//每次从未排序的区间中找到一个最大值，一个最小值
	//min放在头部，max放在尾部
	while (start < end) {
		int maxIdx = start;
		int minIdx = start;
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] > arr[maxIdx])
				maxIdx = i;
			if (arr[i] < arr[minIdx])
				minIdx = i;
		}
		swap(arr, start, minIdx);
		//判断最大值是否为start
		if (maxIdx == start)
			maxIdx = minIdx;
		swap(arr, end, maxIdx);
		start++;
		end--;
	}
}

void testSelectSort2() {
	int arr[] = { 9 ,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	selectSort2(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}