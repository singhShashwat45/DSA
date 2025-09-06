#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:

    void bfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        queue<pair<int, int>> q;
        q.push({row, col});
        int n = grid.size();
        int m = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int dir_x[] = {-1, 0, 1, 0}; //left, up, right, down
            int dir_y[] = {0, 1, 0, -1};
            for(int i = 0; i<4; i++){
                int nrow = row + dir_x[i];
                int ncol = col + dir_y[i];
                if(nrow >= 0 && ncol >= 0 && nrow <n && ncol <m && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow, ncol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    bfs(i, j, grid, vis);
                }
            }
        }
        return cnt;

    }
};


//dfs

// class Solution {
// private:
//     void dfs(vector<vector<char>>& grid, int i, int j)
//     {
//         if(i<0||j<0|| i>=grid.size() || j>=grid[0].size()|| grid[i][j]!='1')
//         return;

//         grid[i][j]='0';
//         dfs(grid, i+1, j);
//         dfs(grid, i-1, j);
//         dfs(grid, i, j-1);
//         dfs(grid, i, j+1);
//     }
// public:
//     int numIslands(vector<vector<char>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();
//         int cn=0;
//         for(int i=0;i<n;i++)
//         {
//             for(int j=0;j<m;j++)
//             {
//                 if(grid[i][j]=='1')
//                 {
//                     cn++;
//                     dfs(grid,i, j);
//                 }
//             }
//         }
//         return cn;
//     }
// };