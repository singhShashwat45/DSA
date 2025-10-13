#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n,vector<int>(n, 0));
        vis[0][0] = 1;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        pq.push({grid[0][0], 0, 0}); //time, i, j

        int dr[] = {-1, 0, 1, 0}; //u, r, d, l
        int dc[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto [time, x, y] = pq.top();
            pq.pop();
            
            if (x == n - 1 && y == n - 1)
                return time;
            for(int i=0; i<4; i++){
                int nr = dr[i] + x;
                int nc = dc[i] + y;
                if(nr >=0 && nc >= 0 && nr<n && nc<n && !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    pq.push({max(grid[nr][nc], time), nr, nc});
                }
            }
        }
        return -1;
    }
};