/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }

    struct ListNode *ptrA = headA;
    struct ListNode *ptrB = headB;

    while (ptrA != ptrB)
    {
        ptrA = (ptrA == NULL) ? headB : ptrA->next;
        ptrB = (ptrB == NULL) ? headA : ptrB->next;
    }

    return ptrA;
}