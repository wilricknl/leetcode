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
    int pairSum(ListNode* head) {
        auto* middle = reverse(findMiddle(head));
        
        int maxSum = 0;
        while (head && middle)
        {
            maxSum = std::max(maxSum, head->val + middle->val);
            head = head->next;
            middle = middle->next;
        }
        
        return maxSum;
    }
    
    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* node)
    {
        ListNode* previous = nullptr;
        while (node)
        {
            auto* temp = node->next;
            node->next = previous;
            previous = node;
            node = temp;
        }
        return previous;
    }
};

