#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* head2 = NULL;
    //��ԭ�нڵ㲻Ϊ��ʱ����ѭ��
    while (head != NULL) {
        //��ԭ�нڵ���ȡ����һ���ڵ�
        struct ListNode* cur = head;
        head = head->next;

        //��ȡ���Ľڵ�ͷ����head2������
        cur->next = head2;
        head2 = cur;
    }
    return head2;
}