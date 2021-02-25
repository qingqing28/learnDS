#include<stdio.h>
#include<stdlib.h>

typedef int HPDataType;
/*ʵ������������λ��ֵ�Ľ���*/
void Swap(HPDataType* arr, int idx1, int idx2) {
	HPDataType tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}
/*ʵ�ִ����
���µ����㷨������洢�ѵ����鼰���ȣ���Ҫִ�����µ����Ľڵ����
*/
void bigShifDown(HPDataType* arr, int n, int cur) {
	//�ҵ����ӵ�λ��
	int child = cur * 2 + 1;
	while (child < n) {
		//���ں��ӣ��Ƚ��������ӣ��ҵ�ֵ��С��һ��
		if (child + 1 < n && arr[child + 1] > arr[child])
			child = child + 1;
		//�͵�ǰ���ݽ��бȽ�
		if (arr[cur] < arr[child]) {
			//������ǰ�ڵ���ֵ��С�ĺ���
			Swap(arr, child, cur);
			//����λ�ã���������
			cur = child;
			child = 2 * cur + 1;
		}
		else
			break;
	}
}

//������
void heapSort(int* arr, int n) {
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
	int arr[] = { 9 ,1,2,5,7,4,8,6,3,5 };
	int n = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}
