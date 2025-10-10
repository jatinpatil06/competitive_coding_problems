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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> answers;
        if(root == NULL)    return answers;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            int num_nodes = qu.size();
            vector<int> level;
            for(int i = 0; i < num_nodes; i++){
                TreeNode *temp = qu.front();
                qu.pop();
                level.push_back(temp -> val);
                if(temp -> left != NULL)    qu.push(temp -> left);
                if(temp -> right != NULL)   qu.push(temp -> right);
            }
            answers.push_back(level);
        }
        return answers;
    }
};