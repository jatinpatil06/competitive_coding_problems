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
    int max_path_sum;
    int calculate(TreeNode *root){
        if(root == NULL)    return 0;
        int left = max(0, calculate(root -> left));
        int right = max(0, calculate(root -> right));
        max_path_sum = max(max_path_sum, root -> val + left + right);
        return max(root -> val + left, root -> val + right);
    }
    int maxPathSum(TreeNode* root) {
        max_path_sum = INT_MIN;
        calculate(root);
        return max_path_sum;
    }
};