#include <bits/stdc++.h>
using namespace std;
#define nl endl;
typedef long long ll;


// https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2025-11-02
class Solution {
public:
    void markGuards(int row, int col, vector<vector<int>>&grid) {
        // up
        for(int r = row-1;r>=0;r--) {
            
            if (grid[r][col]==2 || grid[r][col]==3) {
                break;
            }

            grid[r][col]=1;
        }

        // down
        for(int r=row+1;r<grid.size();r++) {
            if (grid[r][col]==2 || grid[r][col]==3) {
                break;
            }

            grid[r][col]=1;
        }

        // left
        for(int c=col-1;c>=0;c--) {
            if (grid[row][c]==2 || grid[row][c]==3) {
                break;
            }
            grid[row][c] = 1;
        }

        // right
        for(int c=col+1;c<grid[0].size();c++) {
            if (grid[row][c] == 2 || grid[row][c]==3) {
                break;
            }
            grid[row][c]=1;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m, vector<int>(n,0));

        for(vector<int>&g : guards) {
            int x = g[0];
            int y = g[1];

            grid[x][y] = 2;
        }

        for(vector<int>&w : walls) {
            int x = w[0];
            int y = w[1];

            grid[x][y] = 3;
        }

        for(vector<int>&guard: guards) {
            int i = guard[0];
            int j = guard[1];

            markGuards(i, j, grid);
        }

       for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
               cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

        int c = 0;
        for(int i=0;i<grid.size();i++) {
            for(int j=0;j<grid[0].size();j++) {
                if (grid[i][j]==0) {
                    ++c;
                }
            }
        }

        return c;
    }
};