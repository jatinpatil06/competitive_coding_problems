/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> ans;
    vector<int> preorder(Node* root) {
        if (root == NULL)
            return ans;
        int temp = root->val;
        ans.emplace_back(temp);
        for (auto it = (root->children).begin(); it != (root->children).end();
             it++) {
            preorder(*it);
        }
        return ans;
    }
};