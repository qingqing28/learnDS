#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* copyRandomList(struct Node* head) {
    //��ÿ���ڵ������һ���µĽڵ㲢��ֵΪ�ýڵ��ֵ
    struct Node* cur = head;
    while (cur) {
        struct Node* newCur = (struct Node*)malloc(sizeof(struct Node));
        newCur->val = cur->val;
        newCur->next = cur->next;
        cur->next = newCur;
        cur = cur->next->next;
    }

    //��ÿ��������ڵ�����ָ�븳ֵ
    cur = head;
    while (cur) {
        struct Node* copy = cur->next;
        if (cur->random) {
            copy->random = cur->random->next;
        }
        else {
            copy->random = NULL;
        }
        cur = copy->next;
    }

    //�����������
    struct Node* newHead = NULL;
    cur = head;
    while (cur) {
        struct Node* copy = cur->next;
        if (newHead == NULL) {
            newHead = copy;
        }
        cur->next = copy->next;
        cur = copy->next;
        if (copy->next != NULL) {
            copy->next = copy->next->next;
        }
    }
    return newHead;
}