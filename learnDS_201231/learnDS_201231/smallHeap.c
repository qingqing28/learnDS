#include<stdio.h>
#include<stdlib.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* data;  //存储堆数据的数组
	int size;     //数组的实际存储大小
	int capacity;   //数组的内存大小
}Heap;

void checkCapcaity(Heap* hp){
	if (hp == NULL)
		return;
	if (hp->size == hp->capacity) {
		int newCapacity = hp->capacity == 0 ? 1 : 2 * hp->capacity;
		hp->data = (HPDataType*)realloc(hp->data, sizeof(HPDataType) * newCapacity);
		hp->capacity = newCapacity;
	}
}

//堆的初始化
void HeapInit(Heap* hp) {
	if (hp == NULL)
		return;
	hp->data = NULL;
	hp->capacity = hp->size = 0;
}

// 堆的构建
void HeapCreate(Heap* hp , HPDataType* arr ,int n ) {
	//将arr看作一个二叉树，从二叉树的第一个非叶子节点开始调整
	int idx = (n - 2) / 2;
	while (idx >= 0) {
		shifDown(arr, n, idx);
		idx--;
	}
	hp->data = (HPDataType*)malloc(sizeof(HPDataType) * n);
	for (int i = 0 ; i < n; i++) {
		hp->data[i] = arr[i];
	}
	hp->capacity = n;
	hp->size = n ;
}


// 堆的插入
void HeapPush(Heap* hp, HPDataType val) {
	checkCapcaity(hp);
	//尾插
	hp->data[hp->size] = val;
	hp->size++;
	//向上调整
	shifUp(hp->data, hp->capacity, hp->size - 1);
}
// 堆的删除
void HeapPop(Heap* hp) {
	if (hp->size > 0) {
		//交换堆顶与数组的最后一个元素
		HPDataType tmp = hp->data[0];
		hp->data[0] = hp->data[hp->size - 1];
		hp->data[hp->size - 1] = hp->data[0];
		//删除最后一个元素
		hp->size--;
		//对堆顶进行向下调整算法
		shifDown(hp->data, hp->size, 0);
	}
}
// 取堆顶的数据
HPDataType HeapTop(Heap* hp) {
	return hp->data[0];
}
// 堆的数据个数
int HeapSize(Heap* hp) {
	if (hp == NULL)
		return 0;
	return hp->size;
}
// 堆的判空
int HeapEmpty(Heap* hp) {
	if(hp == NULL || hp->size == 0)
		return 1;
	return 0;
}
// 堆的销毁
void HeapDestory(Heap* hp) {
	free(hp->data);
	hp->data = NULL;
	hp->capacity = hp->size = 0;
}

//堆的打印
void HeapPrint(Heap* hp) {
	for (int i = 0; i < hp->size; i++) {
		printf("%d ", hp->data[i]);
	}
	printf("\n");
}
void testHeap() {
	int arr[] = { 8,7,6,5,1,3 };
	int n = sizeof(arr) / sizeof(arr[0]);
	Heap hp;
	HeapInit(&hp);   //初始化栈
	HeapCreate(&hp, arr, n);   //将数组创建成栈1 5 3 8 7 6
	HeapPrint(&hp);

	HeapPush(&hp, 0);//向栈中插入元素0
	HeapPrint(&hp);
	//栈为0 5 1 8 7 6 3
	printf("栈顶元素=%d\n", HeapTop(&hp));
	printf("栈是否为空:%d\n", HeapEmpty(&hp));
	printf("栈的元素个数=%d\n", HeapSize(&hp));
	
	HeapPop(&hp);//删除栈顶
	HeapPrint(&hp);
	//栈为1 5 3 8 7 6
	HeapDestory(&hp);
	printf("栈是否为空:%d\n", HeapEmpty(&hp));
}