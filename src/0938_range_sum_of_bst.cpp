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
    int computeRangeSum(TreeNode* root, int sum, int low, int high)
    {
        if (!root) return sum;

        int value = root->val;

        // only keep exploring left if current node is in range of the low,
        // else all left elements will be too low
        if (value > low)
            sum = computeRangeSum(root->left, sum, low, high);

        if (value >= low && value <= high) sum += value;
        
        // only keep exploring right if current node is in range of the high,
        // else all right elements will be too high
        if (value < high)
            sum = computeRangeSum(root->right, sum, low, high);

        return sum;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return computeRangeSum(root, 0, low, high);
    }
};

