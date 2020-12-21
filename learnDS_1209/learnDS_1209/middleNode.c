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
    //统计链表节点数
    while (cur) {
        len++;
        cur = cur->next;
    }
    //找到第len/2+1个节点
    int middle = len / 2 + 1;
    cur = head;
    while (--middle) {
        cur = cur->next;
    }
    return cur;
}