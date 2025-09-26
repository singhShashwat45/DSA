#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& v) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        vector<int> ans;
        for(int i=0; i<v.size(); i++){
            adj[v[i][1]].push_back(v[i][0]);
            indegree[v[i][0]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(ans.size()==n)
        return ans;
        return {};
    }
};