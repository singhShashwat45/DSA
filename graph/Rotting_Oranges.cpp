#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:

    void bfs(queue<pair<pair<int,int>, int>>& q, vector<vector<int>>& grid, int &ans, int &fresh) {
        int n = grid.size(), m = grid[0].size();
        int drow[4] = {1,-1,0,0};
        int dcol[4] = {0,0,1,-1};

        while(!q.empty()){
            auto it = q.front(); q.pop();
            int r = it.first.first, c = it.first.second, t = it.second;
            ans = max(ans, t);

            for(int k=0; k<4; k++){
                int nr = r + drow[k], nc = c + dcol[k];
                if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc] == 1){
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({{nr,nc}, t+1});
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<pair<int,int>, int>> q;
        int fresh = 0, ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j}, 0});
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        bfs(q, grid, ans, fresh);

        return fresh > 0 ? -1 : ans;
    }
};
