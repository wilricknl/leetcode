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
    int closestValue(TreeNode* root, double target) {
        int minimum = root->val;

        for (auto* node = root; node; node = node->val > target ? node->left : node->right)
        {
            if (std::pair(std::abs(node->val - target), node->val)
                < std::pair(std::abs(minimum - target), minimum))
            {
                minimum = node->val;
            }   
        }

        return minimum;
    }
};

