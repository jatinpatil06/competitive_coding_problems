/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> bottom_view;
        if(root == NULL)    return bottom_view;
        map<int, int> node_view;
        queue<pair<Node*, int>> qu;
        qu.push({root, 0});
        while(!qu.empty()){
            Node* cur_node = qu.front().first;
            int line = qu.front().second;
            qu.pop();
            node_view[line] = cur_node -> data;
            if(cur_node -> left != NULL)    qu.push({cur_node -> left, line - 1});
            if(cur_node -> right != NULL)   qu.push({cur_node -> right, line + 1});
        }
        for(auto p : node_view) 
            bottom_view.push_back(p.second);
        return bottom_view;
    }
};