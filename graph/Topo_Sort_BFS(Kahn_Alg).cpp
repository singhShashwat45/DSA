#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n);
        for (auto &it: pre) {
            adj[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q; int cnt = 0;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            cnt ++;
            for(auto &it : adj[node]){
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return cnt == n;
    }
};