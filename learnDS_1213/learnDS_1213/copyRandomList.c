#include<stdio.h>
#include<stdlib.h>

struct Node {
    int val;
    struct Node* next;
    struct Node* random;
};

struct Node* copyRandomList(struct Node* head) {
    //在每个节点后申请一个新的节点并赋值为该节点的值
    struct Node* cur = head;
    while (cur) {
        struct Node* newCur = (struct Node*)malloc(sizeof(struct Node));
        newCur->val = cur->val;
        newCur->next = cur->next;
        cur->next = newCur;
        cur = cur->next->next;
    }

    //给每个新申请节点的随机指针赋值
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

    //拆分两个链表
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