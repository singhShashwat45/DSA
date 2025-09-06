//Any graph containing odd length cycle is not bipartite graph.
//All linear graphs are bipartite.
//All graphs containing even length cycle is bipartite graph.

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:

    bool bfs_check(int start, vector<vector<int>>& adj, vector<int> &col){
        queue<int> q;
        q.push(start);
        col[start] = 0;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto &it: adj[node]){
                if(col[it] == -1){
                    col[it] = 1-col[node];
                    q.push(it);
                }
                else if(col[it] == col[node]){
                    return false;
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n, -1);
        for(int i=0; i<n; i++){
            if(col[i]==-1){
                if(bfs_check(i, graph, col)== false){
                    return false;
                }
            }
        }
        return true;
    }
};


//dfs
// class Solution {
// public:

//     bool dfs(int src, vector<int>& color, vector<vector<int>>& adj, int col){
//         color[src] = col;
//         for(int child: adj[src])
//         {
//             if(color[child]==-1)
//             {
//                 if(dfs(child, color, adj, 1-col)==false) return false;
//             }
//             else if(color[child]==color[src]) return false;
            
//         }
//         return true;
//     }

//     bool isBipartite(vector<vector<int>>& adj) {
//         int n = adj.size();
//         vector<int> color(n,-1);
//         for(int i=0;i<n;i++){
//             if(color[i]==-1){
//                 if(dfs(i,color,adj,0)==false) return false;
//             }
//         }
//         return true;
//     }
// };