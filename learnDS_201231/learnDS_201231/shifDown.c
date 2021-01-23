#include<stdio.h>
#include<stdlib.h>

typedef int HPDataType;
/*ʵ������������λ��ֵ�Ľ���*/
void Swap(HPDataType* arr, int idx1, int idx2) {
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

/*ʵ��С����
���µ����㷨������洢�ѵ����鼰���ȣ���Ҫִ�����µ����Ľڵ����
*/
void shifDown(HPDataType* arr, int n, int cur) {
	//�ҵ����ӵ�λ��
	int child = cur * 2 + 1;
	while (child < n) {
		//���ں��ӣ��Ƚ��������ӣ��ҵ�ֵ��С��һ��
		if (child + 1 < n && arr[child + 1] < arr[child])
			child = child + 1;
		//�͵�ǰ���ݽ��бȽ�
		if (arr[cur] > arr[child]) {
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



void testShifDown(){
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(arr) / sizeof(arr[0]);
	shifDown(arr, n, 0);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}
