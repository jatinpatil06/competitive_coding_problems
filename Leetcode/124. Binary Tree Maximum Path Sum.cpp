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
    int max_path_sum = INT_MIN;
    int calculate_max_sum(TreeNode *root){
        if(root == NULL)    return 0;
        int left = max(0, calculate_max_sum(root -> left));
        int right = max(0, calculate_max_sum(root -> right));
        max_path_sum = max(max_path_sum, left + right + root -> val);
        return root -> val + max(left, right);
    }
    int maxPathSum(TreeNode* root) {
        calculate_max_sum(root);
        return max_path_sum;
    }
};