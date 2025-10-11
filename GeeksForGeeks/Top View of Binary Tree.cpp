/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        map<int, int> node_map;
        vector<int> top_view;
        
        queue<pair<Node*, int>> qu;
        qu.push({root, 0});
        
        while(!qu.empty()){
            Node *cur_node = qu.front().first;
            int j = qu.front().second;
            qu.pop();
            if(node_map.find(j) == node_map.end())  node_map[j] = cur_node -> data;
            if(cur_node -> left != NULL)    qu.push({cur_node -> left, j - 1});
            if(cur_node -> right != NULL)   qu.push({cur_node -> right, j + 1});
        }
        for(auto p : node_map)
            top_view.push_back(p.second);
        return top_view;
    }
};