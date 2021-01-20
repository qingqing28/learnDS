#include<stdio.h>
#include<stdlib.h>
//#include"seq.h"
typedef int SLDataType;

typedef struct seqList {
	SLDataType* data;     //ָ��̬���ٵĿռ�
	size_t size;           //��ЧԪ�صĸ���
	size_t capacity;        //��̬����Ŀռ�Ĵ�С���������ռ�Ĵ�С
}seqList;

//˳���ĳ�ʼ��
void initSeqList(seqList* s1) {
	//��ʼ��˳������ʹ���ٵ����鳤�Ⱥ�������Ϊ0
	//ʹdataָ�������Ϊ��
	s1->data = NULL;         //��dataָ��Ϊ��
	s1->size = 0;
	s1->capacity = 0;       //��Ч���ݺ�������Ϊ��
}

void printSeqList(seqList* s1) {
	//��ӡ˳���������ν�˳�����Ԫ�ش�ӡ����
	for (int i = 0; i < s1->size; i++) {
		printf("%d ", s1->data[i]);
	}
	printf("\n");
}

//��������Ƿ��㹻�������������
void checkCapacity(seqList* s1) {
	//1.�������Ƿ����
	if (s1 == NULL)
		return;
	//2.�����ЧԪ�ظ�����������ͬ����˵���ռ����ˣ���Ҫ����
	//����ʱÿ�ν���������Ϊԭ��������
	if (s1->size == s1->capacity) {
		size_t newCapacity = s1->capacity == 0 ? 1 : 2 * s1->capacity;
		s1->data = (SLDataType*)realloc(s1->data, sizeof(SLDataType) * newCapacity);
		//3.��������
		s1->capacity = newCapacity;
	}	
}

//β��һ������
void pushBack(seqList* s1, SLDataType val) {
	//1.�������Ƿ����
	if (s1 == NULL)
		return;
	//2.����Ƿ���Ҫ����
	checkCapacity(s1);
	//3.����β��
	s1->data[s1->size] = val;
	s1->size++;
}

//βɾһ������
void popBack(seqList* s1) {
	//1.�������Ƿ����
	if (s1 == NULL || s1->size == 0)
		return;
	//2.ɾ�����һ�����ݣ�ֻ������ЧԪ�ظ�����һ
	s1->size--;
}

//ͷ��һ������
void pushFront(seqList* s1, SLDataType val) {
	//1.�������Ƿ����
	if (s1 == NULL)
		return;
	//2.����Ƿ���Ҫ����
	checkCapacity(s1);
	//3.�Ӻ���ǰ�������ƶ�Ԫ�أ��ճ���0��λ��
	for (int idx = s1->size - 1; idx >= 0; idx--) {
		s1->data[idx + 1] = s1->data[idx];
	}
	//4.��������
	s1->data[0] = val;
	s1->size++;
}

//ͷɾһ������
void popFront(seqList* s1) {
	//1.�������Ƿ����
	if (s1 == NULL || s1->size == 0)
		return;
	//2.��ǰ���������ǰ�ƶ����ճ���ЧԪ�ص����һλ
	for (int idx = 1; idx < s1->size; idx++) {
		s1->data[idx - 1] = s1->data[idx];
	}
	//3.ɾ��Ԫ��
	s1->size--;
}

//����һ��λ�ò���һ������
void insert(seqList* s1, int pos , SLDataType val) {
	//1.�������Ƿ����
	if (s1 == NULL)
		return;

	//2.����λ�ú����������ݵĲ���
	//��Ч����λ��[0,size]
	if (pos >= 0 && pos <= s1->size) {
		//3.�������
		checkCapacity(s1);
		//4.�ƶ�Ԫ��[pos,size),�Ӻ���ǰ��������ƶ�
		for (int idx = s1->size-1; idx >= pos; idx--) {
			s1->data[idx + 1] = s1->data[idx];
		}
		//5.����Ԫ��
		s1->data[pos] = val;
		s1->size++;
	}
}

//����һ��λ��ɾ��һ������
void erase(seqList* s1, int pos) {
	//1.�������Ƿ����
	if (s1 == NULL || s1->size == 0)
		return;
	//2.ɾ��λ�ú�������ɾ��
	//����λ��[0,size)
	if (pos >= 0 && pos < s1->size) {
		//3.�ƶ�Ԫ��[pos+1,size),
		//��ǰ����ƶ���ÿ��Ԫ����ǰ�ƶ�
		for (int idx = pos + 1; idx < s1->size; idx++) {
			s1->data[idx - 1] = s1->data[idx];
		}
		//4.ɾ��Ԫ��
		s1->size--;
	}
}

//�ж�˳����Ƿ�Ϊ�ձ�
int empty(seqList* s1) {
	if (s1 == NULL || s1->size == 0)
		return 1;
	else
		return 0;
}

//����˳���ĳ���
int size(seqList* s1) {
	if (s1 == NULL || s1->size == 0)
		return 0;
	else
		return s1->size;
}

//�������ݲ����������е�����
int findIdx(seqList* s1, SLDataType val) {
	if (s1 == NULL || s1->size == 0)
		return -1;
	//������������[0,size)����ÿһ��Ԫ��
	for (int idx = 0; idx < s1->size; idx++) {
		if (s1->data[idx] == val)
			return idx;
	}
	return -1;
}


//����������������
int getIdx(seqList* s1, int pos) {
	//����Ҫ������Ϊ�������
	return s1->data[pos];
}

//����˳���
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
	initSeqList(&s);//��ʼ��˳���
	pushBack(&s, 1);//��β����������1
	//˳���Ϊ[1]
	printSeqList(&s);//��ӡ˳���
	pushBack(&s, 2);//β������2
	//˳���Ϊ[1 2]
	printSeqList(&s);//��ӡ˳���
	pushFront(&s, 0);//ͷ������0
	//˳���Ϊ[0 1 2]
	printSeqList(&s);//��ӡ˳���
	insert(&s, 1, 11);//��λ��1��������11
	//˳���Ϊ[0 11 1 2]
	printSeqList(&s);//��ӡ˳���
	insert(&s, 0, 12);//��λ��0��������12���൱��ͷ��
	//˳���Ϊ[12 0 11 1 2]
	printSeqList(&s);//��ӡ˳���
	insert(&s, s.size,13);//�����λ�ò�������13���൱��β��
	//˳���Ϊ[12 0 11 1 2 13]
	printSeqList(&s);//��ӡ˳���

	printf("˳����Ƿ�Ϊ�գ�%d\n", empty(&s)); //���Ϊ0
	printf("˳���ĳ���Ϊ��%d\n", size(&s));//���Ϊ6
	printf("����13��˳����е�������%d\n", findIdx(&s, 13));//���Ϊ5
	printf("����Ϊ3������Ϊ:%d\n", getIdx(&s, 3));//���Ϊ1

	popBack(&s);//βɾһ������
	//˳���Ϊ[12 0 11 1 2]
	printSeqList(&s);//��ӡ˳���
	popFront(&s);//ͷɾһ������
	//˳���Ϊ[0 11 1 2]
	printSeqList(&s);//��ӡ˳���
	erase(&s, 1);//ɾ��λ��1�ϵ�Ԫ��
	//˳���Ϊ[0 1 2]
	printSeqList(&s);//��ӡ˳���
	erase(&s, 0);//ɾ��0��λ�õ�Ԫ�أ��൱��ͷɾ
	//˳���Ϊ[1 2]
	printSeqList(&s);//��ӡ˳���
	destroySeqList(&s);
	printSeqList(&s);//��ӡ˳���
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

