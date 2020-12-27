#include<stdio.h>
#include<stdlib.h>
struct ListNode {
    int val;
    struct ListNode *next;
    //ListNode(int x) : val(x), next(NULL) {}
};
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        // write code here
        //�ҵ��м�ڵ�
        ListNode* slow, * fast;
        slow = fast = A;
        if (fast == NULL || fast->next == NULL)
            return true;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //��ת��벿������
        ListNode* cur, * prev;
        cur = slow;
        prev = NULL;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }

        //prevΪ��벿�ֵ�ͷ�ڵ�
        while (A && prev) {
            if (A->val != prev->val)
                return false;
            else {
                A = A->next;
                prev = prev->next;
            }
        }
        return true;
    }
};