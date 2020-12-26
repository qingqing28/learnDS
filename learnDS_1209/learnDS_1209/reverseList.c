#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList1(struct ListNode* head) {
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

struct ListNode* middleNode22(struct ListNode* head) {
    //设置快慢指针
    struct ListNode* fast, * slow;
    fast = slow = head;
    //当快指针为最后一个节点或者为空是结束循环
    while (fast && fast->next) {
        //快指针步长为2，慢指针步长为1
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}