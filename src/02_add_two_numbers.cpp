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
    ListNode* unwind(ListNode* l)
    {
        auto value = l->val;
        if (value > 9)
        {
            value -= 10;
            if (l->next)
                l->next->val += 1;
            else
                l->next = new ListNode(1);
        }


        auto* result = new ListNode(value);
        if (l->next)
        {
            result->next = unwind(l->next);
        }    
        return result;

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 && !l2) { return unwind(l1); }
        if (l2 && !l1) { return unwind(l2); }
        if (!l1 && !l2) { return nullptr; }

        auto value = l1->val + l2->val;
        if (value > 9)
        {
            value -= 10;
            if (l1->next)
                l1->next->val += 1;
            else
                l1->next = new ListNode(1);
        }

        auto* result = new ListNode(value);
        result->next = addTwoNumbers(l1->next, l2->next);  
        return result;
    }
};
