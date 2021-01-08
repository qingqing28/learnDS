typedef int LDataType;
typedef struct ListNode {
	LDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}ListNode;

typedef struct List {
	struct ListNode* head;
}List;

//����ĳ�ʼ��
void listInit(List* lst);
//β��һ������
void listPushBack(List* lst, LDataType val);
//βɾһ������
void listPopBack(List* lst);
//��ӡ����
void printList(List* lst);
//ͷ��һ������
void listPushFront(List* lst, LDataType val);
//ͷɾһ������
void listPopFront(List* lst);
//ɾ�������ڵ㣨����ɾ��ͷ�ڵ㣩
void listErase(List* lst, ListNode* node);
// ��node�ڵ�λ�ô������½ڵ�
void listInsert(List* lst, ListNode* node, LDataType val);
//���ҵ�n��λ�õĽڵ�
ListNode* listFindByIdx(List* lst, int n);
//����ĳ���ڵ�
ListNode* listFind(List* lst, LDataType val);
//������ĳ���
int listSize(List* lst);
//��������
void listDestroy(List* lst);
void test();