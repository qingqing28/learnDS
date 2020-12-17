#include<stdio.h>
#include<stdlib.h>
//#include"list.h"
typedef int LDataType;
typedef struct listNode {
	LDataType data;         //存储的数据
	struct ListNode* next;   //指向下一个节点
}listNode;

typedef struct list {
	listNode* head;    //指向链表节点的指针
}list;

//链表的初始化
void listInit(list* lst) {
	//链表的初始化就是使head的指向为空
	if (lst == NULL)
		return;       //判断参数是否有效
	lst->head = NULL;
}

//创建一个新节点
listNode* creatNode(LDataType val) {
	//创建一个链表节点，使节点的数据值为val，next指向空
	//返回创建节点的地址
	listNode* node = (listNode*)malloc(sizeof(listNode));
	//申请一个大小为listNode类型的空间，并返回该空间的地址
	node->data = val;
	node->next = NULL;
	return node;
}

//尾插一个数据
void listPushBack(list* lst, LDataType val) {
	/*1、先判断链表是否为空链表，空链表直接进行尾插，非空则进行如下操作
	  2、得到链表的最后一个节点，地址保存在end中
	* 3、创建一个新的节点，地址保存在node中
	* 4、进行尾插
	*/
	if (lst == NULL)
		return;
	//1、先判断链表是否为空链表
	if (lst->head == NULL) {
		lst->head = creatNode(val);
		return;
	}
	//2、得到最后的节点end
	listNode * end;
	end = lst->head;
	while (end->next != NULL) {
		end = end->next;
	}                     

	//3、创建一个新的节点
	listNode* node = creatNode(val);

	//4、进行尾插
		end->next = node;
}

//尾删一个数据
void listPopBack(list* lst) {
	/*
	* 1、首先判断链表是否为空链表，若为空，则直接返回，若不为空，进行如下操作
	* 2、找到最后一个节点，记录在end中，并记录上一个节点的位置，记录在perv中
	* 3、释放最后一个节点，使prev->next=NULL
	*/
	//1、若链表为空，则直接返回
	if (lst == NULL || lst->head == NULL)
		return;
	//2、找到最后一个节点并记录前一个节点
	listNode* prev, * end;
	prev = NULL;
	end = lst->head;
	while (end->next != NULL) {
		prev = end;
		end = end->next;
	}
	//prev可能为NULL，也可能不为NULL

	//3、释放最后一个节点
	free(end);
	if (prev == NULL) {
		lst->head = NULL;
	}else
		prev->next = NULL;
}

//头插一个数据
void listPushFront(list* lst, LDataType val) {
	/*1、判断是否为空链表，空链表直接插入，非空则进行如下操作
	* 2、创建一个新的节点node
	* 3、node->next = lst->head , lst->head = node ;
	* 4、可以观察出，空链表和非空链表的插入过程相同，可以进行一个合并
	*/
	if (lst == NULL)
		return;
	listNode* node = creatNode(val);
	node->next = lst->head;
	lst->head = node;     
	//注意：上面两条语句的顺序不能发生变化，否则会使链表后面的语句丢失
	/*若不考虑两者的顺序，也可以写成
	* listNode* next = lst->head ;
	* lst->head = node ;
	* node->next = next ;
	*/
}

void listPopFront(list* lst) {
	/*1、首先判断链表是否为空，空链表直接返回
	* 2、记录第二个节点的位置next和第一个节点的位置node
	* 3、释放node
	* 4、lst->head = next 
	*/
	//1、空链表直接返回
	if (lst == NULL || lst->head == NULL) {
		return;
	}
	//2、记录节点位置
	listNode* next, * node;
	node = lst->head;
	next = node->next;
	//3、删除节点
	free(node);
	lst->head = next;

}

// 在给定节点后插入一个数据
void listInsertAfter(listNode* cur, LDataType val) {
	/*1、记录下一个节点的位置next
	* 2、创建一个新节点node
	* 3、node->next = next ; cur->next = node ;
	*/
	listNode* next = cur->next;
	listNode* node = creatNode(val);
	node->next = next;
	cur->next = node;
}

//在给定节点之后删除一个数据
void listEraseAfter(listNode* cur) {
	/*1、记录下一个节点的位置next和下下个节点的位置nextnext
	* 2、释放next；cur->next = nextnext
	*/
	listNode* next = cur->next;
	if (next == NULL)
		return;
	listNode* nextnext = next->next;
	free(next);
	cur->next = nextnext;
}

void printList(list* lst) {
	//遍历整个链表依次进行打印
	if (lst == NULL)
		return;
	listNode* cur = lst->head;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

//查找某个节点
listNode* listFind(list* lst, LDataType val) {
	/*1、若为空链表，则直接返回
	* 2、遍历整个链表，查找data==val的节点
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
//查找某个节点
listNode* listFindByIdx(list* lst, int n) {
	/*1、若为空链表，则直接返回
	* 2、遍历整个链表，查找第n个节点
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

//求链表的长度
int listSize(list* lst) {
	/*1、若为空链表，则直接返回0
	* 2、遍历整个链表，计算链表的长度
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

//销毁一个链表
void listDestroy(list* lst) {
	/*1、若为空链表则直接返回
	* 2、进行头删操作，直至链表清空
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
	
	listNode* cur = listFind(&lst ,0);//查找值为0的节点
	listInsertAfter(cur, 11);//在值为0的节点的后方插入11
	//链表为0->11->1->2
	printList(&lst); //打印链表
	cur = listFindByIdx(&lst, listSize(&lst) - 1);
	listInsertAfter(cur, 13);//尾插13
	//链表为0->11->1->2->13
	printList(&lst); //打印链表

	listPopBack(&lst);//尾删
	//链表为0->11->1->2
	printList(&lst); //打印链表
	listPopFront(&lst);//头删
	//链表为11->1->2
	printList(&lst); //打印链表
	cur = listFindByIdx(&lst, 0);
	listEraseAfter(cur);//删除位置0之后的节点
	//链表为11->2
	printList(&lst); //打印链表
	cur = listFindByIdx(&lst, listSize(&lst) - 2);
	listEraseAfter( cur);//尾删
	//链表为11
	printList(&lst); //打印链表
	listDestroy(&lst);//销毁链表
	printList(&lst); //打印链表
	system("pause");
	return 0;
}