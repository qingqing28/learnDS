#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    int len = 0;
    struct ListNode* cur = pListHead;
    while (cur) {
        len++;
        cur = cur->next;
    }
    cur = pListHead;
    int ret = len - k;
    while (ret-- && cur) {
        cur = cur->next;
    }
    return cur;
}