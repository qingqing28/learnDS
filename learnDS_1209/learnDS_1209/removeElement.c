#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
 
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur, * prev;
    cur = head;
    prev = NULL;
    while (cur) {
        //���ݵ���val����ɾ���ýڵ�
        if (cur->val == val) {
            struct ListNode* next = cur->next;
            if (prev == NULL) {
                head = next;
            }
            else {
                prev->next = next;
            }
            free(cur);
            cur = next;
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}

int main() {

}