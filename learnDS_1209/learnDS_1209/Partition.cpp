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
        //������������
        ListNode* lessHead, * lessTail, * greaterHead, * greaterTail;
        ListNode* cur = pHead;
        lessHead = lessTail = greaterHead = greaterTail = NULL;

        //������ķָ�����������
        while (cur) {
            if (cur->val < x) {
                //����Ϊ��ʱ
                if (lessTail == NULL) {
                    lessHead = lessTail = cur;
                }
                else {
                    lessTail->next = cur;
                    lessTail = lessTail->next;
                }
            }
            else {
                //����Ϊ��ʱ
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

        //�ϲ���������
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