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
    int findMaxDiff(TreeNode* root, int min, int max)
    {
        if (!root) return std::abs(max - min);
        
        min = std::min(min, root->val);
        max = std::max(max, root->val);
        
        if (!root->right)
        {
            return findMaxDiff(root->left, min, max);
        }
        
        if (!root->left)
        {
            return findMaxDiff(root->right, min, max);
        }
        
        return std::max(findMaxDiff(root->left, min, max), findMaxDiff(root->right, min, max));
    }
    
    int maxAncestorDiff(TreeNode* root) {
        return findMaxDiff(root, INT_MAX, INT_MIN);
    }
};

