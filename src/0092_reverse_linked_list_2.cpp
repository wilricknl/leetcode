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
    ListNode* reverseBetween(ListNode* head, int left, int right)
    {
        ListNode dummy(0, head);
        ListNode* before = &dummy;
        for (int i = 1; i < left; ++i)
        {
            before = before->next;
        }

        ListNode* tail = before->next;
        ListNode* previous = nullptr;
        ListNode* current = tail;
        for (int i = left; i <= right; ++i)
        {
            ListNode* next = current->next;
            current->next = previous;
            previous = current;
            current = next;
        }

        before->next = previous;
        tail->next = current;
        return dummy.next;
    }
};

