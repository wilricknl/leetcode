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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* iterator = head;
        while (iterator && iterator->next)
        {
            if (iterator->val == iterator->next->val)
            {
                ListNode* duplicate = iterator->next;
                iterator->next = duplicate->next;
                delete duplicate;
            }
            else
            {
                iterator = iterator->next;
            }
        }
        
        return head;
    }
};

