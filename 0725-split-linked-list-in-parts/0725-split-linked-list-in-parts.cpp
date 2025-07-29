/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        ListNode* node = head;
        int len = 0;
        vector<ListNode*> result(k, nullptr);
        while(node)
        {
            len++;
            node = node->next;
        }
        int n = len / k;
        int remaining = len % k;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        for(int i = 0 ; i < k && curr ; i++, remaining--)
        {
            result[i] = curr;
            for(int count = 0 ; count < n + (remaining > 0 ? 1 : 0) ; count++)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = nullptr;
        }
        return result;
    }
};