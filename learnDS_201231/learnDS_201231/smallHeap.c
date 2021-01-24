#include<stdio.h>
#include<stdlib.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* data;  //�洢�����ݵ�����
	int size;     //�����ʵ�ʴ洢��С
	int capacity;   //������ڴ��С
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

//�ѵĳ�ʼ��
void HeapInit(Heap* hp) {
	if (hp == NULL)
		return;
	hp->data = NULL;
	hp->capacity = hp->size = 0;
}

// �ѵĹ���
void HeapCreate(Heap* hp , HPDataType* arr ,int n ) {
	//��arr����һ�����������Ӷ������ĵ�һ����Ҷ�ӽڵ㿪ʼ����
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


// �ѵĲ���
void HeapPush(Heap* hp, HPDataType val) {
	checkCapcaity(hp);
	//β��
	hp->data[hp->size] = val;
	hp->size++;
	//���ϵ���
	shifUp(hp->data, hp->capacity, hp->size - 1);
}
// �ѵ�ɾ��
void HeapPop(Heap* hp) {
	if (hp->size > 0) {
		//�����Ѷ�����������һ��Ԫ��
		HPDataType tmp = hp->data[0];
		hp->data[0] = hp->data[hp->size - 1];
		hp->data[hp->size - 1] = hp->data[0];
		//ɾ�����һ��Ԫ��
		hp->size--;
		//�ԶѶ��������µ����㷨
		shifDown(hp->data, hp->size, 0);
	}
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp) {
	return hp->data[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp) {
	if (hp == NULL)
		return 0;
	return hp->size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp) {
	if(hp == NULL || hp->size == 0)
		return 1;
	return 0;
}
// �ѵ�����
void HeapDestory(Heap* hp) {
	free(hp->data);
	hp->data = NULL;
	hp->capacity = hp->size = 0;
}

//�ѵĴ�ӡ
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
	HeapInit(&hp);   //��ʼ��ջ
	HeapCreate(&hp, arr, n);   //�����鴴����ջ1 5 3 8 7 6
	HeapPrint(&hp);

	HeapPush(&hp, 0);//��ջ�в���Ԫ��0
	HeapPrint(&hp);
	//ջΪ0 5 1 8 7 6 3
	printf("ջ��Ԫ��=%d\n", HeapTop(&hp));
	printf("ջ�Ƿ�Ϊ��:%d\n", HeapEmpty(&hp));
	printf("ջ��Ԫ�ظ���=%d\n", HeapSize(&hp));
	
	HeapPop(&hp);//ɾ��ջ��
	HeapPrint(&hp);
	//ջΪ1 5 3 8 7 6
	HeapDestory(&hp);
	printf("ջ�Ƿ�Ϊ��:%d\n", HeapEmpty(&hp));
}