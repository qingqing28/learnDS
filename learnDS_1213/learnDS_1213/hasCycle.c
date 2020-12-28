#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

bool hasCycle(struct ListNode* head) {
    //���ÿ���ָ��
    struct ListNode* fast, * slow;
    fast = slow = head;
    if (fast == NULL || fast->next == NULL)
        return false;

    //ʹ����ָ�벻����ǰ�ƶ�
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow)
            return true;
    }
    return false;
}