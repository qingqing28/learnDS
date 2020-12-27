#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if (pHead == NULL || pHead->next == NULL)
            return pHead;
        ListNode* prev, * start, * end;
        prev = NULL;
        start = pHead;
        end = pHead->next;

        //进行移动，查找重复区间[start , end)
        while (end) {
            if (start->val != end->val) {
                prev = start;
                start = end;
                end = end->next;
            }
            else {
                while (end && start->val == end->val) {
                    //不断删除重复元素
                    ListNode* node = start->next;
                    end = end->next;
                    free(node);
                    start->next = end;
                }
                free(start);
                if (prev == NULL) {
                    pHead = end;
                }
                else {
                    prev->next = end;
                }
                start = end;
                if (end)
                    end = end->next;
            }
        }
        return pHead;
    }
};