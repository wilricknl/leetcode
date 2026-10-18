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
    bool isValidBST(TreeNode* root) {
        return isValid(root, nullptr, nullptr);
    }

    bool isValid(TreeNode* node, TreeNode* low, TreeNode* high)
    {
        if (!node) return true;
        if (low && low->val >= node->val) return false;
        if (high && high->val <= node->val) return false;
        return isValid(node->left, low, node) && isValid(node->right, node, high);
    }
};

