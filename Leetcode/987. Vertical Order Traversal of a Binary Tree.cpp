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
    map<int, vector<pair<int, int>>> nodes;

    static bool customSort(const pair<int, int> &a, const pair<int, int> &b){
        if(a.second == b.second)    return a.first < b.first;
        return a.second < b.second;
    }
    void vertical(TreeNode* root, int i, int j){
        if(root != NULL){
            nodes[j].push_back({root -> val, i});
            if(root -> left != NULL)    vertical(root -> left, i + 1, j - 1);
            if(root -> right != NULL)   vertical(root -> right, i + 1, j + 1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vertical(root, 0, 0);
        vector<vector<int>> answers;
        for(auto it = nodes.begin(); it != nodes.end(); it++){
            vector<pair<int, int>> &vec = it -> second;
            sort(vec.begin(), vec.end(), customSort);
            vector<int> answer;
            for(auto value : vec){
                answer.push_back(value.first);
            }
            answers.push_back(answer);
        }
        return answers;
    }
};