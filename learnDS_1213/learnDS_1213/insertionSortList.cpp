#include<stdio.h>
#include<stdlib.h>


struct ListNode {  
 int val;
    struct ListNode *next;
 };
 


struct ListNode* insertionSortList(struct ListNode* head) {
    //����ǰn��Ԫ���Ѿ��ź���
    struct ListNode* cur, * tail;
    cur = head;
    if (head == NULL || head->next == NULL)
        return head;
    tail = head;
    cur = head->next;

    while (cur) {
        //����curӦ�ò����λ��
        struct ListNode* inst, * prev, * next;
        next = cur->next;

        inst = head;
        prev = NULL;
        while (inst->val < cur->val) {
            prev = inst;
            inst = inst->next;
        }
        //���в������
        if (prev == NULL) {
            tail->next = next;
            cur->next = inst;
            head = cur;
        }
        else if (prev == tail) {
            tail = tail->next;
        }
        else {
            tail->next = next;
            cur->next = inst;
            prev->next = cur;
        }
        cur = next;
    }
    return head;
}