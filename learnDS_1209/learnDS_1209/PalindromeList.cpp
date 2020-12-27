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
        //找到中间节点
        ListNode* slow, * fast;
        slow = fast = A;
        if (fast == NULL || fast->next == NULL)
            return true;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        //反转后半部分链表
        ListNode* cur, * prev;
        cur = slow;
        prev = NULL;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;

            prev = cur;
            cur = next;
        }

        //prev为后半部分的头节点
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