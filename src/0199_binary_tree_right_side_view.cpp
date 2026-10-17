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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        std::vector<int> answer;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            answer.push_back(q.back()->val);
            
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                auto* node = q.front();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
        }

        return answer;
    }
};

