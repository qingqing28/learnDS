#include<stdio.h>
#include<stdlib.h>


// ��������ж�����
void HeapSort(int* arr, int n) {
	//����
	for (int i = (n - 2) / 2; i >= 0; i--) {
		bigShifDown(arr, n, i);
	}

	//������
	int end = n - 1;
	while (end > 0) {
		//�Ѷ�Ԫ�ص�ɾ��������+���µ���
		Swap(arr, 0, end);
		bigShifDown(arr, end, 0);
		end--;
	}
}

void testHeapSort() {
	int arr[] = { 8,7,6,5,1,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	HeapSort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}