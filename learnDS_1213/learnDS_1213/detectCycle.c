#include<stdio.h>
#include<stdlib.h>



struct ListNode {
      int val;
     struct ListNode *next;
 };

struct ListNode* detectCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return NULL;
    //�ҵ�����ָ���������
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

    //һ��ָ�����㿪ʼ����ƶ���һ��ָ��ӿ���ָ��������㿪ʼ����ƶ���
    struct ListNode* cur = head;
    while (cur) {
        if (cur == fast)
            return cur;
        cur = cur->next;
        fast = fast->next;
    }
    return NULL;
}