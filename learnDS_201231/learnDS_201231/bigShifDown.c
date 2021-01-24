#include<stdio.h>
#include<stdlib.h>

typedef int HPDataType;

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

