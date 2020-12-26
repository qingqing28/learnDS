#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    // write code here
    int len = 0;
    struct ListNode* cur = pListHead;
    while (cur) {
        len++;
        cur = cur->next;
    }
    cur = pListHead;
    int ret = len - k;
    while (ret-- && cur) {
        cur = cur->next;
    }
    return cur;
}

struct ListNode* FindKthToTail2(struct ListNode* pListHead, int k) {
    // write code here
    //���ÿ���ָ��`fast = slow = head`
    struct ListNode* fast, * slow;
    fast = slow = pListHead;
    //���ÿ�ָ������k��
    while (k && fast) {
        k--;
        fast = fast->next;
    }
    if (k > 0)
        return NULL;
    //����ָ��ͬʱ����ƶ�������ָ��Ϊ��ʱ����ָ��ָ�򷵻ؽ��
    while (fast) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}

