#include<stdio.h>
#include<stdlib.h>

/*ѡ������:ÿһ�δ�δ������������ҵ�һ����С�ģ�
����С�ķŵ�δ��������ݵ�ͷ���������ظ�
*/
void selectSort(int* arr, int n) {
	//��δ������������ҵ���ֵ����ŵ�δ�������ʼλ��
	//δ��������
	int start = 0; 
	int end = n - 1;
	while (start < end) {
		int minIdx = start;
		for (int i = start + 1; i <= end; i++) {
			if (arr[i] < arr[minIdx])
				minIdx = i;
		}
		//����Сֵ������ʼ��λ��
		swap(arr, start, minIdx);
		//ʣ���δ��������[start + 1 , end]
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