#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int data;
    ListNode *next;
};

void initList(ListNode *&L)
{
    int n;
    scanf("%d", &n);
    if (n != 0) {
        L = (ListNode *)malloc(sizeof(ListNode));
        L -> data = n;
        L -> next = NULL;
        initList(L -> next);
    }
}

ListNode *reverseList(ListNode *L)
{
    ListNode *p = L;
    ListNode *q = L -> next;
    p -> next = NULL;
    while (q != NULL) {
        ListNode *r = q -> next;
        q -> next = p;
        p = q;
        q = r;
    }
    return p;
}

ListNode *getKValue(ListNode *L, int k)
{
    if (k == 0) {
        return 0;
    }
    ListNode *p = reverseList(L);
    ListNode *q = p;
    for (int i = 0; q != NULL && i < k - 1; i ++) {
        q = q -> next;
    }
    reverseList(p);
    return q;
}

void display(ListNode *L)
{
    ListNode *p =L;
    while (p != NULL) {
        printf("%d ", p -> data);
        p = p -> next;
    }
    printf("\n");
}

int main()
{
    ListNode *L = NULL;
    int k;
    scanf("%d", &k);
    initList(L);
    getKValue(L, k);
    display(L);
    return 0;
}

