#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
  public:
    
    int find_par(vector<int>& par, int node){
        if(node == par[node]) return node;
        return par[node] = find_par(par, par[node]);
    }
    
    void unite(int u, int v, vector<int> &rank, vector<int>&par){
        int ulp_u = find_par(par, u);
        int ulp_v = find_par(par, v);
        
        if(rank[ulp_u] < rank[ulp_v]){
            par[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            par[ulp_v] = ulp_u;
        }
        else{
            par[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    
    int spanningTree(int V, vector<vector<int>>& edges) {
        vector<int> par(V), rank(V, 0);
        for(int i=0; i<V; i++) par[i] = i;
        sort(edges.begin(),edges.end(), [](auto &a, auto &b){
            return a[2]< b[2];
        });
        int mstWeight = 0;
        
        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            
            if(find_par(par, u) != find_par(par, v)){
                unite(u, v, rank, par);
                mstWeight+= w;
            }
        }
        return mstWeight;
        
    }
};