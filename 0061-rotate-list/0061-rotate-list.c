/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (!head || !head->next || k == 0)
        return head;
    int length = 1;
    struct ListNode *tail = head;
    while (tail->next) {
        tail = tail->next;
        length++;
    }
    tail->next = head;
    k = k % length;
    int stepsToNewHead = length - k;
    struct ListNode *newTail = head;
    for (int i = 1; i < stepsToNewHead; i++) {
        newTail = newTail->next;
    }
    struct ListNode *newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
