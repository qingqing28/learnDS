#include<stdio.h>
#include<stdlib.h>
/*ֱ�Ӳ�������
*/
void insertSort(int* arr, int n) {
	//�����һ����������
	//δ���������[1,n)
	for (int i = 1; i < n; i++) {
		int end = i - 1;
		int data = arr[i];
		while (end >= 0 && arr[end] > data) {
			//�����������ƶ�
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