#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode* head) {
    //设置快慢指针
    struct ListNode* fast, * slow;
    fast = slow = head;
    if (fast == NULL || fast->next == NULL)
        return false;

    //使快慢指针不断向前移动
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}