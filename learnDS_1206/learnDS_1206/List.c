#include<stdio.h>
#include<stdlib.h>
//#include"list.h"
typedef int LDataType;
typedef struct listNode {
	LDataType data;         //�洢������
	struct ListNode* next;   //ָ����һ���ڵ�
}listNode;

typedef struct list {
	listNode* head;    //ָ������ڵ��ָ��
}list;

//����ĳ�ʼ��
void listInit(list* lst) {
	//����ĳ�ʼ������ʹhead��ָ��Ϊ��
	if (lst == NULL)
		return;       //�жϲ����Ƿ���Ч
	lst->head = NULL;
}

//����һ���½ڵ�
listNode* creatNode(LDataType val) {
	//����һ������ڵ㣬ʹ�ڵ������ֵΪval��nextָ���
	//���ش����ڵ�ĵ�ַ
	listNode* node = (listNode*)malloc(sizeof(listNode));
	//����һ����СΪlistNode���͵Ŀռ䣬�����ظÿռ�ĵ�ַ
	node->data = val;
	node->next = NULL;
	return node;
}

//β��һ������
void listPushBack(list* lst, LDataType val) {
	/*1�����ж������Ƿ�Ϊ������������ֱ�ӽ���β�壬�ǿ���������²���
	  2���õ���������һ���ڵ㣬��ַ������end��
	* 3������һ���µĽڵ㣬��ַ������node��
	* 4������β��
	*/
	if (lst == NULL)
		return;
	//1�����ж������Ƿ�Ϊ������
	if (lst->head == NULL) {
		lst->head = creatNode(val);
		return;
	}
	//2���õ����Ľڵ�end
	listNode * end;
	end = lst->head;
	while (end->next != NULL) {
		end = end->next;
	}                     

	//3������һ���µĽڵ�
	listNode* node = creatNode(val);

	//4������β��
		end->next = node;
}

//βɾһ������
void listPopBack(list* lst) {
	/*
	* 1�������ж������Ƿ�Ϊ��������Ϊ�գ���ֱ�ӷ��أ�����Ϊ�գ��������²���
	* 2���ҵ����һ���ڵ㣬��¼��end�У�����¼��һ���ڵ��λ�ã���¼��perv��
	* 3���ͷ����һ���ڵ㣬ʹprev->next=NULL
	*/
	//1��������Ϊ�գ���ֱ�ӷ���
	if (lst == NULL || lst->head == NULL)
		return;
	//2���ҵ����һ���ڵ㲢��¼ǰһ���ڵ�
	listNode* prev, * end;
	prev = NULL;
	end = lst->head;
	while (end->next != NULL) {
		prev = end;
		end = end->next;
	}
	//prev����ΪNULL��Ҳ���ܲ�ΪNULL

	//3���ͷ����һ���ڵ�
	free(end);
	if (prev == NULL) {
		lst->head = NULL;
	}else
		prev->next = NULL;
}

//ͷ��һ������
void listPushFront(list* lst, LDataType val) {
	/*1���ж��Ƿ�Ϊ������������ֱ�Ӳ��룬�ǿ���������²���
	* 2������һ���µĽڵ�node
	* 3��node->next = lst->head , lst->head = node ;
	* 4�����Թ۲����������ͷǿ�����Ĳ��������ͬ�����Խ���һ���ϲ�
	*/
	if (lst == NULL)
		return;
	listNode* node = creatNode(val);
	node->next = lst->head;
	lst->head = node;     
	//ע�⣺������������˳���ܷ����仯�������ʹ����������䶪ʧ
	/*�����������ߵ�˳��Ҳ����д��
	* listNode* next = lst->head ;
	* lst->head = node ;
	* node->next = next ;
	*/
}

void listPopFront(list* lst) {
	/*1�������ж������Ƿ�Ϊ�գ�������ֱ�ӷ���
	* 2����¼�ڶ����ڵ��λ��next�͵�һ���ڵ��λ��node
	* 3���ͷ�node
	* 4��lst->head = next 
	*/
	//1��������ֱ�ӷ���
	if (lst == NULL || lst->head == NULL) {
		return;
	}
	//2����¼�ڵ�λ��
	listNode* next, * node;
	node = lst->head;
	next = node->next;
	//3��ɾ���ڵ�
	free(node);
	lst->head = next;

}

// �ڸ����ڵ�����һ������
void listInsertAfter(listNode* cur, LDataType val) {
	/*1����¼��һ���ڵ��λ��next
	* 2������һ���½ڵ�node
	* 3��node->next = next ; cur->next = node ;
	*/
	listNode* next = cur->next;
	listNode* node = creatNode(val);
	node->next = next;
	cur->next = node;
}

//�ڸ����ڵ�֮��ɾ��һ������
void listEraseAfter(listNode* cur) {
	/*1����¼��һ���ڵ��λ��next�����¸��ڵ��λ��nextnext
	* 2���ͷ�next��cur->next = nextnext
	*/
	listNode* next = cur->next;
	if (next == NULL)
		return;
	listNode* nextnext = next->next;
	free(next);
	cur->next = nextnext;
}

void printList(list* lst) {
	//���������������ν��д�ӡ
	if (lst == NULL)
		return;
	listNode* cur = lst->head;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//����ĳ���ڵ�
listNode* listFind(list* lst, LDataType val) {
	/*1����Ϊ��������ֱ�ӷ���
	* 2������������������data==val�Ľڵ�
	*/
	if (lst == NULL || lst->head == NULL)
		return;
	listNode* cur = lst->head;
	while (cur) {
		if (cur->data == val) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//����ĳ���ڵ�
listNode* listFindByIdx(list* lst, int n) {
	/*1����Ϊ��������ֱ�ӷ���
	* 2�����������������ҵ�n���ڵ�
	*/
	if (lst == NULL || lst->head == NULL)
		return;
	listNode* cur = lst->head;
	int len = 0;
	while (len < n && cur != NULL) {
		cur = cur->next;
		len++;
	}
	if (len >= n)
		return cur;
	if (cur == NULL)
		return NULL;
}

//������ĳ���
int listSize(list* lst) {
	/*1����Ϊ��������ֱ�ӷ���0
	* 2����������������������ĳ���
	*/
	if (lst == NULL || lst->head == NULL)
		return;
	listNode* cur = lst->head;
	int len = 0;
	while (cur) {
		len++;
		cur = cur->next;
	}
	return len;
}

//����һ������
void listDestroy(list* lst) {
	/*1����Ϊ��������ֱ�ӷ���
	* 2������ͷɾ������ֱ���������
	*/
	if (lst == NULL || lst->head == NULL)
		return;
	listNode* cur = lst->head;
	while (cur) {
		lst->head = cur->next;
		free(cur);
		cur = lst->head;
	}
}
int main() {
	list lst;
	listInit(&lst);//��ʼ������
	listPushBack(&lst, 1);//β��1
	//����Ϊ1
	printList(&lst); //��ӡ����
	listPushBack(&lst, 2);//β��2
	//����Ϊ1->2
	printList(&lst); //��ӡ����
	listPushFront(&lst, 0);//ͷ��0
	//����Ϊ0->1->2
	printList(&lst); //��ӡ����
	
	listNode* cur = listFind(&lst ,0);//����ֵΪ0�Ľڵ�
	listInsertAfter(cur, 11);//��ֵΪ0�Ľڵ�ĺ󷽲���11
	//����Ϊ0->11->1->2
	printList(&lst); //��ӡ����
	cur = listFindByIdx(&lst, listSize(&lst) - 1);
	listInsertAfter(cur, 13);//β��13
	//����Ϊ0->11->1->2->13
	printList(&lst); //��ӡ����

	listPopBack(&lst);//βɾ
	//����Ϊ0->11->1->2
	printList(&lst); //��ӡ����
	listPopFront(&lst);//ͷɾ
	//����Ϊ11->1->2
	printList(&lst); //��ӡ����
	cur = listFindByIdx(&lst, 0);
	listEraseAfter(cur);//ɾ��λ��0֮��Ľڵ�
	//����Ϊ11->2
	printList(&lst); //��ӡ����
	cur = listFindByIdx(&lst, listSize(&lst) - 2);
	listEraseAfter( cur);//βɾ
	//����Ϊ11
	printList(&lst); //��ӡ����
	listDestroy(&lst);//��������
	printList(&lst); //��ӡ����
	system("pause");
	return 0;
}