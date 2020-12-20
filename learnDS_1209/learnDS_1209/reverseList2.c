#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* reverseList2(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;
    //定义三个辅助指针变量并进行初始赋值
    struct ListNode* n1, * n2, * n3;
    n1 = head;
    n2 = head->next;
    n3 = n2->next;
    n1->next = NULL;

    //当n2不为空时进行循环
    while (n2) {
        //将n2节点指向反转
        n2->next = n1;
        //将三个辅助指针变量向后移动
        n1 = n2;
        n2 = n3;
        if (n3 != NULL) {
            n3 = n3->next;
        }
    }
    head = n1;
    return head;
}