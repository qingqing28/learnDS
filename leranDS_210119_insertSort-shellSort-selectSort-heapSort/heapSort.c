#include<stdio.h>
#include<stdlib.h>

typedef int HPDataType;
/*实现数组中两个位置值的交换*/
void Swap(HPDataType* arr, int idx1, int idx2) {
	HPDataType tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}
/*实现大根堆
向下调整算法，传入存储堆的数组及长度，需要执行向下调整的节点序号
*/
void bigShifDown(HPDataType* arr, int n, int cur) {
	//找到孩子的位置
	int child = cur * 2 + 1;
	while (child < n) {
		//存在孩子，比较两个孩子，找到值最小的一个
		if (child + 1 < n && arr[child + 1] > arr[child])
			child = child + 1;
		//和当前数据进行比较
		if (arr[cur] < arr[child]) {
			//交换当前节点与值最小的孩子
			Swap(arr, child, cur);
			//更新位置，继续调整
			cur = child;
			child = 2 * cur + 1;
		}
		else
			break;
	}
}

//堆排序
void heapSort(int* arr, int n) {
	//建堆
	for (int i = (n - 2) / 2; i >= 0; i--) {
		bigShifDown(arr, n, i);
	}

	//堆排序
	int end = n - 1;
	while (end > 0) {
		//堆顶元素的删除：交换+向下调整
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
