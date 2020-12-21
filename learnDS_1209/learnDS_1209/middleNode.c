#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL)
        return head;
    int len = 0;
    struct ListNode* cur = head;
    //ͳ������ڵ���
    while (cur) {
        len++;
        cur = cur->next;
    }
    //�ҵ���len/2+1���ڵ�
    int middle = len / 2 + 1;
    cur = head;
    while (--middle) {
        cur = cur->next;
    }
    return cur;
}