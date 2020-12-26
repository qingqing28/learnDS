#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList1(struct ListNode* head) {
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

struct ListNode* middleNode22(struct ListNode* head) {
    //���ÿ���ָ��
    struct ListNode* fast, * slow;
    fast = slow = head;
    //����ָ��Ϊ���һ���ڵ����Ϊ���ǽ���ѭ��
    while (fast && fast->next) {
        //��ָ�벽��Ϊ2����ָ�벽��Ϊ1
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}