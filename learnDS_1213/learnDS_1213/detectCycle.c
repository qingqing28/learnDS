#include<stdio.h>
#include<stdlib.h>



struct ListNode {
      int val;
     struct ListNode *next;
 };

struct ListNode* detectCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    //找到快慢指针的相遇点
    struct ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            break;
    }

    if (fast != slow) {
        return NULL;
    }

    //一个指针从起点开始向后移动，一个指针从快慢指针的相遇点开始向后移动；
    struct ListNode* cur = head;
    while (cur) {
        if (cur == fast)
            return cur;
        cur = cur->next;
        fast = fast->next;
    }
    return NULL;
}