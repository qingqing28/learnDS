#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* head2 = NULL;
    //当原有节点不为空时进行循环
    while (head != NULL) {
        //从原有节点上取出第一个节点
        struct ListNode* cur = head;
        head = head->next;

        //将取出的节点头插入head2链表中
        cur->next = head2;
        head2 = cur;
    }
    return head2;
}