#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList2(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    //������������ָ����������г�ʼ��ֵ
    struct ListNode* n1, * n2, * n3;
    n1 = head;
    n2 = head->next;
    n3 = n2->next;
    n1->next = NULL;

    //��n2��Ϊ��ʱ����ѭ��
    while (n2) {
        //��n2�ڵ�ָ��ת
        n2->next = n1;
        //����������ָ���������ƶ�
        n1 = n2;
        n2 = n3;
        if (n3 != NULL) {
            n3 = n3->next;
        }
    }
    head = n1;
    return head;
}