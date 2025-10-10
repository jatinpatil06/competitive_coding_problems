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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> right_view;
        if(root == NULL)    return right_view;
        queue<TreeNode*> qu;
        qu.push(root);
        while(!qu.empty()){
            vector<int> level;
            int num_nodes = qu.size();
            for(int i = 0; i < num_nodes; i++){
                TreeNode* temp = qu.front();
                qu.pop();
                level.push_back(temp -> val);
                if(temp -> left != NULL)    qu.push(temp -> left);
                if(temp -> right != NULL)   qu.push(temp -> right);
            }
            right_view.push_back(level[level.size() - 1]);
        }
        return right_view;
    }
};