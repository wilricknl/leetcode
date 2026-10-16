/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:    
    bool findPathToNode(TreeNode* current, TreeNode* node, std::vector<TreeNode*>& path)
    {
        if (!current) return false;

        path.push_back(current);
        if (current->val == node->val
            || findPathToNode(current->left, node, path)
            || findPathToNode(current->right, node, path))
        {
            return true;
        }

        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        std::vector<TreeNode*> pathP;
        if (!findPathToNode(root, p, pathP))
        {
            return nullptr;
        }
        
        std::vector<TreeNode*> pathQ;
        if (!findPathToNode(root, q, pathQ))
        {
            return nullptr;
        }
        
        while (!pathP.empty() && !pathQ.empty())
        {
            if (pathP.size() > pathQ.size())
            {
                pathP.pop_back();
            }
            else
            {
                pathQ.pop_back();
            }
            if (pathP.back()->val == pathQ.back()->val)
                return pathP.back();
        }
        
        return root;
    }
};

