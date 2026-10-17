/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        
        std::vector<std::vector<int>> answer;
        std::queue<TreeNode*> q;
        
        q.push(root);
        
        bool leftToRight = true;
        while (!q.empty())
        {
            int n = q.size();
            
            std::vector<int> nums;
            for (int i = 0; i < n; ++i)
            {
                auto* node = q.front();
                nums.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
            if (!leftToRight)
            {
                std::reverse(nums.begin(), nums.end());
            }
            answer.push_back(std::move(nums));
            leftToRight = !leftToRight;
        }
        
        return answer;
    }
};

