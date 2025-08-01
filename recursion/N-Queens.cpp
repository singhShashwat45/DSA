#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:

    void solve(int col, vector<string>& board, vector<vector<string>>&ans, vector<int>& lowerDia, vector<int>& upperDia, vector<int> &leftrow, int n){
        if(n==col){
            ans.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftrow[row]==0 && lowerDia[row+col]==0 && upperDia[n-1+col-row]==0){
                board[row][col]='Q';
                leftrow[row]=1;
                lowerDia[row+col]=1;
                upperDia[n-1+col-row]=1;
                solve(col+1, board, ans, lowerDia, upperDia, leftrow, n);
                board[row][col]='.';
                leftrow[row]=0;
                lowerDia[row+col]=0;
                upperDia[n-1+col-row]=0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string>board(n);
        vector<vector<string>>ans;
        vector<int>lowerDia(2*n-1,0);
        vector<int> upperDia(2*n-1,0);
        vector<int> leftrow(n,0);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i] = s;
        solve(0, board, ans, lowerDia, upperDia, leftrow, n);
        return ans;
    }
};