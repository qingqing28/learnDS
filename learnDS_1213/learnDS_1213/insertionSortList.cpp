#include<stdio.h>
#include<stdlib.h>


struct ListNode {  
 int val;
    struct ListNode *next;
 };
 


struct ListNode* insertionSortList(struct ListNode* head) {
    //假设前n个元素已经排好序
    struct ListNode* cur, * tail;
    cur = head;
    if (head == NULL || head->next == NULL)
        return head;
    tail = head;
    cur = head->next;

    while (cur) {
        //查找cur应该插入的位置
        struct ListNode* inst, * prev, * next;
        next = cur->next;

        inst = head;
        prev = NULL;
        while (inst->val < cur->val) {
            prev = inst;
            inst = inst->next;
        }
        //进行插入操作
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