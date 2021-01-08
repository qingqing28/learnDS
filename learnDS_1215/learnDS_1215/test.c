#include<stdio.h>
#include<stdlib.h>
#include"list.h"

//创建一个新节点
ListNode* createListNode(LDataType val) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = val;
	node->prev = NULL;
	node->next = NULL;
	return node;
}

//链表的初始化
void listInit(List* lst) {
	lst->head = createListNode(0);
	//头节点的前一个节点和后一个节点均为其自身
	lst->head->next = lst->head->prev = lst->head;
}

//尾插一个数据
void listPushBack(List* lst, LDataType val) {
	if (lst == NULL)
		return;
	//头节点的前一个节点为最后一个节点
	ListNode* node = createListNode(val);
	ListNode* last = lst->head->prev;
	//进行尾插
	last->next = node;
	node->next = lst->head;
	node->prev = last;
	lst->head->prev = node;
}

//尾删一个数据
void listPopBack(List* lst) {
	//链表不存在或者链表为空时直接返回程序
	if (lst == NULL || lst->head->next == lst->head) {
		return;
	}
	//头节点的前一个节点为最后一个节点
	ListNode* last = lst->head->prev;
	ListNode* prev = last->prev;

	//进行尾删
	prev->next = lst->head;
	lst->head->prev = prev;
	free(last);
}

//打印链表
void printList(List* lst) {
	if (lst == NULL || lst->head == NULL)
		return;
	ListNode* cur = lst->head->next;
	while (cur != lst->head) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//头插一个数据
void listPushFront(List* lst, LDataType val){
	if (lst == NULL)
		return;
	ListNode* node = createListNode(val);
	ListNode* next = lst->head->next;

	//进行头插
	lst->head->next = node;
	node->next = next;
	
	next->prev = node;
	node->prev = lst->head;
}

//头删一个数据
void listPopFront(List* lst) {
	//链表不存在或者链表为空时直接返回程序
	if (lst == NULL || lst->head->next == lst->head) {
		return;
	}
	ListNode* node = lst->head->next;
	ListNode* next = node->next;

	//进行头删
	lst->head->next = next;
	next->prev = lst->head;
	free(node);
}

//删除给定节点（不可删除头节点）
void listErase(List* lst, ListNode* node) {
	//若链表不存在 ； 链表为空链表；节点为头节点则直接返回
	if (lst == NULL || lst->head->next == lst->head || node == lst->head)
		return;
	ListNode* prev = node->prev;
	ListNode* next = node->next;

	//进行删除
	prev->next = next;
	next->prev = prev;
	free(node);
}

// 在node节点位置处插入新节点
void listInsert(List* lst,  ListNode* node,LDataType val) {
	//若链表不存在则返回
	if (lst == NULL)
		return;
	ListNode* prev = node->prev;
	ListNode* newNode = createListNode(val);

	//插入节点
	prev->next = newNode;
	newNode->next = node;
	node->prev = newNode;
	newNode->prev = prev;
}

//查找第n个位置的节点
ListNode* listFindByIdx(List* lst, int n) {
	if (lst == NULL || lst->head->next == lst->head)
		return;
	ListNode* cur = lst->head;
	int len = 0;
	while (len < n && cur) {
		len++;
		cur = cur->next;
	}
	return cur;
}

//查找某个节点
ListNode* listFind(List* lst, LDataType val) {
	if (lst == NULL || lst->head->next == lst->head)
		return;
	ListNode* cur = lst->head->next;
	while (cur != lst->head) {
		if (cur->data == val)
			break;
		cur = cur->next;
	}
}

//求链表的长度
int listSize(List* lst) {
	if (lst == NULL || lst->head->next == lst->head)
		return 0;
	int len = 0;
	ListNode* cur = lst->head->next;
	while (cur != lst->head) {
		len++;
		cur = cur->next;
	}
	return len;
}

//销毁链表
void listDestroy(List* lst) {
	if (lst == NULL || lst->head->next == lst->head)
		return;
	ListNode* cur = lst->head->next;
	while (cur != lst->head) {
		ListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	free(lst->head);
	lst->head = NULL; 
}

void test() {
	List lst;
	listInit(&lst);//初始化链表
	listPushBack(&lst, 1);//尾插1
	//链表为1
	printList(&lst); //打印链表
	listPushBack(&lst, 2);//尾插2
	//链表为1->2
	printList(&lst); //打印链表
	listPushFront(&lst, 0);//头插0
	//链表为0->1->2
	printList(&lst); //打印链表

	ListNode* cur = listFind(&lst, 1);//查找值为1的节点
	listInsert(&lst, cur, 11);//在值为1的节点前的插入11
	//链表为0->11->1->2
	printList(&lst); //打印链表
	listInsert(&lst , lst.head, 13);//尾插13
	//链表为0->11->1->2->13
	printList(&lst); //打印链表

	listPopBack(&lst);//尾删
	//链表为0->11->1->2
	printList(&lst); //打印链表
	listPopFront(&lst);//头删
	//链表为11->1->2
	printList(&lst); //打印链表
	cur = listFindByIdx(&lst, 1);
	listErase(&lst , cur);//删除位置为1的节点
	//链表为1->2
	printList(&lst); //打印链表
	listErase(&lst , lst.head->prev);//尾删
	//链表为1
	printList(&lst); //打印链表
	listDestroy(&lst);//销毁链表
	printList(&lst); //打印链表

}

int main() {
	test();
	return 0;
}