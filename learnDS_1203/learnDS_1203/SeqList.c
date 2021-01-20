#include<stdio.h>
#include<stdlib.h>
//#include"seq.h"
typedef int SLDataType;

typedef struct seqList {
	SLDataType* data;     //指向动态开辟的空间
	size_t size;           //有效元素的个数
	size_t capacity;        //动态申请的空间的大小，即容量空间的大小
}seqList;

//顺序表的初始化
void initSeqList(seqList* s1) {
	//初始化顺序表就是使开辟的数组长度和容量均为0
	//使data指向的数组为空
	s1->data = NULL;         //是data指向为空
	s1->size = 0;
	s1->capacity = 0;       //有效数据和容量均为空
}

void printSeqList(seqList* s1) {
	//打印顺序表就是依次将顺序表中元素打印出来
	for (int i = 0; i < s1->size; i++) {
		printf("%d ", s1->data[i]);
	}
	printf("\n");
}

//检查容量是否足够不够则进行扩容
void checkCapacity(seqList* s1) {
	//1.检查参数是否合理
	if (s1 == NULL)
		return;
	//2.如果有效元素个数和容量相同，则说明空间满了，需要扩容
	//扩容时每次将容量增加为原来的两倍
	if (s1->size == s1->capacity) {
		size_t newCapacity = s1->capacity == 0 ? 1 : 2 * s1->capacity;
		s1->data = (SLDataType*)realloc(s1->data, sizeof(SLDataType) * newCapacity);
		//3.更新数据
		s1->capacity = newCapacity;
	}	
}

//尾插一个数据
void pushBack(seqList* s1, SLDataType val) {
	//1.检查参数是否合理
	if (s1 == NULL)
		return;
	//2.检查是否需要扩容
	checkCapacity(s1);
	//3.进行尾插
	s1->data[s1->size] = val;
	s1->size++;
}

//尾删一个数据
void popBack(seqList* s1) {
	//1.检查参数是否合理
	if (s1 == NULL || s1->size == 0)
		return;
	//2.删除最后一个数据，只需是有效元素个数减一
	s1->size--;
}

//头插一个数据
void pushFront(seqList* s1, SLDataType val) {
	//1.检查参数是否合理
	if (s1 == NULL)
		return;
	//2.检查是否需要扩容
	checkCapacity(s1);
	//3.从后先前逐个向后移动元素，空出第0个位置
	for (int idx = s1->size - 1; idx >= 0; idx--) {
		s1->data[idx + 1] = s1->data[idx];
	}
	//4.插入数据
	s1->data[0] = val;
	s1->size++;
}

//头删一个数据
void popFront(seqList* s1) {
	//1.检查参数是否合理
	if (s1 == NULL || s1->size == 0)
		return;
	//2.从前往后逐次向前移动，空出有效元素的最后一位
	for (int idx = 1; idx < s1->size; idx++) {
		s1->data[idx - 1] = s1->data[idx];
	}
	//3.删除元素
	s1->size--;
}

//任意一个位置插入一个数据
void insert(seqList* s1, int pos , SLDataType val) {
	//1.检查参数是否合理
	if (s1 == NULL)
		return;

	//2.插入位置合理后进行数据的插入
	//有效插入位置[0,size]
	if (pos >= 0 && pos <= s1->size) {
		//3.检查容量
		checkCapacity(s1);
		//4.移动元素[pos,size),从后向前依次向后移动
		for (int idx = s1->size-1; idx >= pos; idx--) {
			s1->data[idx + 1] = s1->data[idx];
		}
		//5.插入元素
		s1->data[pos] = val;
		s1->size++;
	}
}

//任意一个位置删除一个数据
void erase(seqList* s1, int pos) {
	//1.检查参数是否合理
	if (s1 == NULL || s1->size == 0)
		return;
	//2.删除位置合理后进行删除
	//合理位置[0,size)
	if (pos >= 0 && pos < s1->size) {
		//3.移动元素[pos+1,size),
		//从前向后移动，每个元素向前移动
		for (int idx = pos + 1; idx < s1->size; idx++) {
			s1->data[idx - 1] = s1->data[idx];
		}
		//4.删除元素
		s1->size--;
	}
}

//判断顺序表是否为空表
int empty(seqList* s1) {
	if (s1 == NULL || s1->size == 0)
		return 1;
	else
		return 0;
}

//计算顺序表的长度
int size(seqList* s1) {
	if (s1 == NULL || s1->size == 0)
		return 0;
	else
		return s1->size;
}

//根据数据查找在数组中的索引
int findIdx(seqList* s1, SLDataType val) {
	if (s1 == NULL || s1->size == 0)
		return -1;
	//遍历整个数组[0,size)查找每一个元素
	for (int idx = 0; idx < s1->size; idx++) {
		if (s1->data[idx] == val)
			return idx;
	}
	return -1;
}


//根据索引查找数据
int getIdx(seqList* s1, int pos) {
	//这里要求数均为合理参数
	return s1->data[pos];
}

//销毁顺序表
void destroySeqList(seqList* s1) {
	if (s1) {
		if (s1->data) {
			free(s1->data);
			s1->data = NULL;
			s1->size = 0;
			s1->capacity = 0;
		}
	}
}

int main() {
	seqList s;
	initSeqList(&s);//初始化顺序表
	pushBack(&s, 1);//在尾部插入数字1
	//顺序表为[1]
	printSeqList(&s);//打印顺序表
	pushBack(&s, 2);//尾插数字2
	//顺序表为[1 2]
	printSeqList(&s);//打印顺序表
	pushFront(&s, 0);//头插数字0
	//顺序表为[0 1 2]
	printSeqList(&s);//打印顺序表
	insert(&s, 1, 11);//在位置1插入数字11
	//顺序表为[0 11 1 2]
	printSeqList(&s);//打印顺序表
	insert(&s, 0, 12);//在位置0插入数字12，相当于头插
	//顺序表为[12 0 11 1 2]
	printSeqList(&s);//打印顺序表
	insert(&s, s.size,13);//在最后位置插入数字13，相当于尾插
	//顺序表为[12 0 11 1 2 13]
	printSeqList(&s);//打印顺序表

	printf("顺序表是否为空：%d\n", empty(&s)); //结果为0
	printf("顺序表的长度为：%d\n", size(&s));//结果为6
	printf("数字13在顺序表中的索引：%d\n", findIdx(&s, 13));//结果为5
	printf("索引为3的数据为:%d\n", getIdx(&s, 3));//结果为1

	popBack(&s);//尾删一个数据
	//顺序表为[12 0 11 1 2]
	printSeqList(&s);//打印顺序表
	popFront(&s);//头删一个数据
	//顺序表为[0 11 1 2]
	printSeqList(&s);//打印顺序表
	erase(&s, 1);//删除位置1上的元素
	//顺序表为[0 1 2]
	printSeqList(&s);//打印顺序表
	erase(&s, 0);//删除0号位置的元素，相当于头删
	//顺序表为[1 2]
	printSeqList(&s);//打印顺序表
	destroySeqList(&s);
	printSeqList(&s);//打印顺序表
}



//int main() {
//	seqList s;
//	initSeqList(&s);
//	insert(&s, 0, 1);
//	printSeqList(&s);
//	insert(&s, 1, 2);
//	printSeqList(&s);
//	insert(&s, 0, 0);
//	printSeqList(&s);
//	insert(&s, 1, 11);
//	printSeqList(&s);
//
//	erase(&s, 1);
//	printSeqList(&s);
//	erase(&s, 0);
//	printSeqList(&s);
//	erase(&s, 1);
//	printSeqList(&s);
//	erase(&s, 0);
//	printSeqList(&s);
//
//}
//int main() {
//	seqList s;
//	initSeqList(&s);
//	pushFront(&s, 3);
//	printSeqList(&s);
//	pushFront(&s, 2);
//	printSeqList(&s);
//	pushFront(&s, 1);
//	printSeqList(&s);
//
//	popFront(&s);
//	printSeqList(&s);
//	popFront(&s);
//	printSeqList(&s);
//	popFront(&s);
//	printSeqList(&s);
//}

//int main() {
//	seqList s;
//	initSeqList(&s);
//	pushBack(&s, 1);
//	pushBack(&s, 2);
//	pushBack(&s, 3);
//	popBack(&s);
//	printSeqList(&s);
//	popBack(&s);
//	printSeqList(&s);
//	popBack(&s);
//	printSeqList(&s);
//	return 0;
//}

