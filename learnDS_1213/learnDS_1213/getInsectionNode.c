#include<stdio.h>
#include<stdlib.h>

 struct ListNode {
     int val;
     struct ListNode *next;
  };
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    //统计两个链表的长度
    int size1, size2;
    size1 = size2 = 0;
    struct ListNode* cur1, * cur2;
    cur1 = headA;
    cur2 = headB;
    while (cur1) {
        size1++;
        cur1 = cur1->next;
    }
    while (cur2) {
        size2++;
        cur2 = cur2->next;
    }
    //长链表先走|size1 - size2|步
    int gap = abs(size1 - size2);
    struct ListNode* longList = headA, * shortList = headB;
    if (size2 > size1) {
        longList = headB;
        shortList = headA;
    }
    while (gap--) {
        longList = longList->next;
    }

    //同时向后遍历，两指针值相同为第一个公共节点
    while (longList && shortList) {
        if (longList == shortList)
            return longList;
        longList = longList->next;
        shortList = shortList->next;
    }
    return NULL;
}


struct ListNode* getIntersectionNode2(struct ListNode* headA, struct ListNode* headB) {
    // 统计两个链表的长度
    int size1, size2;
    size1 = size2 = 0;
    struct ListNode* cur1, * cur2;
    cur1 = headA;
    cur2 = headB;
    while (cur1) {
        size1++;
        cur1 = cur1->next;
    }
    while (cur2) {
        size2++;
        cur2 = cur2->next;
    }
    //长链表先走|size1 - size2|步
    cur1 = headA;
    cur2 = headB;
    if (size1 > size2) {
        int len = size1 - size2;
        while (len--) {
            cur1 = cur1->next;
        }
    }
    else {
        int len = size2 - size1;
        while (len--) {
            cur2 = cur2->next;
        }
    }

    //同时向后遍历，两指针值相同为第一个公共节点
    while (cur1 && cur2) {
        if (cur1 == cur2) {
            return cur1;
        }
        cur1 = cur1->next;
        cur2 = cur2->next;

    }
    return NULL;
}

int main() {
    return 0;
}