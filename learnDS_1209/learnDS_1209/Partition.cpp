#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};

class Partition{
public:
    ListNode* partition(ListNode* pHead, int x) {
        //创建两个链表
        ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
        ListNode* cur = pHead;
        lessHead = lessTail = greaterHead = greaterTail = NULL;

        //将链表的分隔成两个链表
        while (cur) {
            if (cur->val < x) {
                //链表为空时
                if (lessTail == NULL) {
                    lessHead = lessTail = cur;
                }
                else {
                    lessTail->next = cur;
                    lessTail = lessTail->next;
                }
            }
            else {
                //链表为空时
                if (greaterTail == NULL) {
                    greaterHead = greaterTail = cur;
                }
                else {
                    greaterTail->next = cur;
                    greaterTail = greaterTail->next;
                }
            }
            cur = cur->next;
        }

        //合并两个链表
        if (lessTail) {
            lessTail->next = greaterHead;
        }
        if (greaterTail) {
            greaterTail->next = NULL;
        }
        if (lessHead) {
            return lessHead;
        }
        else
            return greaterHead;
    }
};