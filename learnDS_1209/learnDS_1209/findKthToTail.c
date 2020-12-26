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

struct ListNode* FindKthToTail2(struct ListNode* pListHead, int k) {
    // write code here
    //设置快慢指针`fast = slow = head`
    struct ListNode* fast, * slow;
    fast = slow = pListHead;
    //先让快指针先走k步
    while (k && fast) {
        k--;
        fast = fast->next;
    }
    if (k > 0)
        return NULL;
    //快慢指针同时向后移动，当快指针为空时，慢指针指向返回结点
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

