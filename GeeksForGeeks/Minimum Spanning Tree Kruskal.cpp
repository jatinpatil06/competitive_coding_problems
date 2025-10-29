class DisjointSet{
  vector<int> size, parent;
  public:
  DisjointSet(int n){
      size.resize(n, 1);
      parent.resize(n);
      for(int i = 0; i < n; i++)    parent[i] = i;
  }
  
  int findUltimateParent(int u){
      if(u == parent[u])    return u;
      return parent[u] = findUltimateParent(parent[u]);
  }
  
  void unionBySize(int u, int v){
      int ulp_u = findUltimateParent(u);
      int ulp_v = findUltimateParent(v);
      if(ulp_u == ulp_v)    return;
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

class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        //we need to sort the edges by their weights in non-decreasing order
        sort(edges.begin(), edges.end(), [](const vector<int> &a, const vector<int> &b){
            return a[2] < b[2];
        });
        int sum = 0;
        DisjointSet ds(V);
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            if(ds.findUltimateParent(u) != ds.findUltimateParent(v)){
                ds.unionBySize(u, v);
                sum += wt;
            }
        }
        return sum;
    }
};