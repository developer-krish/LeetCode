/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) 
    {
        if(head == nullptr) return head;
        Node* curr = head;
        while(curr != nullptr)
        {
            if(curr->child != nullptr)
            {
                // step1flatten linked list
                Node* node = curr->next;
                curr->next = flatten(curr->child);
                curr->next->prev = curr;
                curr->child = nullptr;
    
                // step 2 find the last node
                while(curr->next != nullptr)
                   curr = curr->next;
                
                // step3 now finally connect them
                if(node != nullptr)
                {
                    curr->next = node;
                    node->prev = curr;
                }   
            }
            curr = curr->next;
        }
        
        return head;
    }
};