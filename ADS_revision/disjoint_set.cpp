#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank, parent, size;
    public:
    DisjointSet(int n){
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++)  parent[i] = i;
        size.resize(n + 1, 1);
    }

    int findUltimateParent(int u){
        if(u == parent[u])  return u;
        return parent[u] = findUltimateParent(parent[u]);
    }

    void unionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v)  return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v)  return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main(){
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(1, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(4, 6);
    if(ds.findUltimateParent(4) == ds.findUltimateParent(3))    cout << "Same Parent!";
    else    cout << "Not Same Parent.";
    return 0;
}