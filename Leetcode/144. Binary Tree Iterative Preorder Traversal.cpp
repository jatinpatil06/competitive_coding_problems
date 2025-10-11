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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* temp = root;
        vector<int> preorder;
        while(true){
            while(temp != NULL){
                preorder.push_back(temp -> val);
                st.push(temp);
                temp = temp -> left;
            }
            if(st.empty())  break;
            temp = st.top();
            st.pop();
            temp = temp -> right;
        }
        return preorder;
    }
};