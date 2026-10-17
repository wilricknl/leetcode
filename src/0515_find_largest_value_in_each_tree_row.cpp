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
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};

        std::vector<int> answer;
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            int rowMaximum = q.front()->val;
            for (int i = 0; i < n; ++i)
            {
                auto* node = q.front();
                rowMaximum = std::max(rowMaximum, node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                q.pop();
            }
            answer.push_back(rowMaximum);
        }
        return answer;
    }
};

