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
    int goodNodes(TreeNode* root) {
        return countGoodNodes(root, INT_MIN);
    }

    int countGoodNodes(TreeNode* node, int greatestValue)
    {
        if (!node) return 0;

        greatestValue = std::max(greatestValue, node->val);

        return (node->val >= greatestValue)
            + countGoodNodes(node->left, greatestValue)
            + countGoodNodes(node->right, greatestValue);
    }
};

