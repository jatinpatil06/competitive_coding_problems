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
    TreeNode* invertTree(TreeNode* root) {
        queue<TreeNode*> qu;
        if(root == NULL)
            return NULL;
        qu.push(root);
        while(!qu.empty())
        {
            TreeNode* temp = qu.front();
            qu.pop();
            std::swap(temp->left, temp->right);
            if(temp -> left != NULL)
                qu.push(temp -> left);
            if(temp -> right != NULL)
                qu.push(temp -> right);
        }
        return root;
    }
};