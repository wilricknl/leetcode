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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* start = head->next;
        
        ListNode* iterator = head;
        while (iterator && iterator->next)
        {
            ListNode* temp = iterator->next->next;
            iterator->next->next = iterator;
            iterator->next = temp && temp->next ? temp->next : temp;
            iterator = temp;
        }

        return start;
    }
};

