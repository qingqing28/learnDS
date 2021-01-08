typedef int LDataType;
typedef struct ListNode {
	LDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

typedef struct List {
	struct ListNode* head;
}List;

//链表的初始化
void listInit(List* lst);
//尾插一个数据
void listPushBack(List* lst, LDataType val);
//尾删一个数据
void listPopBack(List* lst);
//打印链表
void printList(List* lst);
//头插一个数据
void listPushFront(List* lst, LDataType val);
//头删一个数据
void listPopFront(List* lst);
//删除给定节点（不可删除头节点）
void listErase(List* lst, ListNode* node);
// 在node节点位置处插入新节点
void listInsert(List* lst, ListNode* node, LDataType val);
//查找第n个位置的节点
ListNode* listFindByIdx(List* lst, int n);
//查找某个节点
ListNode* listFind(List* lst, LDataType val);
//求链表的长度
int listSize(List* lst);
//销毁链表
void listDestroy(List* lst);
void test();