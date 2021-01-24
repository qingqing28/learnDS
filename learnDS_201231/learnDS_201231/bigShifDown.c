#include<stdio.h>
#include<stdlib.h>

typedef int HPDataType;

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

