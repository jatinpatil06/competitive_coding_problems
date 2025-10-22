#include<bits/stdc++.h>
using namespace std;
class graph{
    int num_nodes;
    vector<vector<int>> graph;
    public:
    graph(){
        cout << "How many nodes do you want in your graph ? ";
        cin >> num_nodes;
        graph.resize(num_nodes);
        cout << "Enter the adjacent nodes for each following node.\n";
        for(int i = 1; i <= num_nodes; i++){
            cout << "Node " << i << " -> ";
            
        }
    }
}
int main()
{
    return 0;
}