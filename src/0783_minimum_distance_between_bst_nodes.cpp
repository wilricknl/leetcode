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
    int minDiffInBST(TreeNode* root) {
        std::vector<int> values;
        collectValues(root, values);

        int answer = INT_MAX;
        for (int i = 0; i < values.size() - 1; ++i)
        {
            answer = std::min(answer, values[i+1] - values[i]);
        }

        return answer;
    }

    void collectValues(TreeNode* node, std::vector<int>& values)
    {
        if (!node) return;

        collectValues(node->left, values);
        values.push_back(node->val);
        collectValues(node->right, values);
    }
};

