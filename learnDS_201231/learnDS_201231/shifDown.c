#include<stdio.h>
#include<stdlib.h>

typedef int HPDataType;
/*实现数组中两个位置值的交换*/
void Swap(HPDataType* arr, int idx1, int idx2) {
	int tmp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = tmp;
}

/*实现小根堆
向下调整算法，传入存储堆的数组及长度，需要执行向下调整的节点序号
*/
void shifDown(HPDataType* arr, int n, int cur) {
	//找到孩子的位置
	int child = cur * 2 + 1;
	while (child < n) {
		//存在孩子，比较两个孩子，找到值最小的一个
		if (child + 1 < n && arr[child + 1] < arr[child])
			child = child + 1;
		//和当前数据进行比较
		if (arr[cur] > arr[child]) {
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



void testShifDown(){
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	int n = sizeof(arr) / sizeof(arr[0]);
	shifDown(arr, n, 0);
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
}
