#include<stdio.h>
#include<stdlib.h>
/*直接插入排序
*/
void insertSort(int* arr, int n) {
	//假设第一个数据有序
	//未插入的数据[1,n)
	for (int i = 1; i < n; i++) {
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] > data) {
			//大的数据向后移动
			arr[end + 1] = arr[end];
			end--;
		}
		arr[end + 1] = data;
	}
}

void testInsertSort() {
	int arr[] = { 9 ,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	insertSort(arr , n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}