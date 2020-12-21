#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL)
        return head;
    int len = 0;
    struct ListNode* cur = head;
    //统计链表节点数
    while (cur) {
        len++;
        cur = cur->next;
    }
    //找到第len/2+1个节点
    int middle = len / 2 + 1;
    cur = head;
    while (--middle) {
        cur = cur->next;
    }
    return cur;
}

struct ListNode* middleNode2(struct ListNode* head){
    //设置快慢指针
    struct ListNode* fast , *slow ;
    fast = slow = head ;
    //当快指针为最后一个节点或者为空是结束循环
    while(fast && fast->next){
        //快指针步长为2，慢指针步长为1
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow ;
}
