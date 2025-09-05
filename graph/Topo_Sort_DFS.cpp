#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>>& pre, vector<int> &vis, stack<int> &st){
        vis[node] = 1;
        for(auto &it : pre[node]){
            if(vis[it]== 0){
                dfs(it, pre, vis, st);
            }
            else if (vis[it] == 1) {
                return;
            }
        }
        vis[node] = 2;
        st.push(node);

    }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int> vis(numCourses, 0);
        stack<int> st;
        vector<vector<int>> adj(numCourses);
        for(auto &it : pre){
            adj[it[1]].push_back(it[0]);
        }
        for(int i=0; i<numCourses; i++){
            if(vis[i] == 0){
                dfs(i, adj, vis, st);
            }
        }
        return (st.size() == numCourses);
    }
};