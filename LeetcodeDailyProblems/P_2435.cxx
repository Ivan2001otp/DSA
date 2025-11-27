#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/?envType=daily-question&envId=2025-11-26
    int numberOfPaths(vector<vector<int> >& grid, int k) {
        int MOD = 1e9+7;
       
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<vector<int> > > dp(r, vector<vector<int> >(c, vector<int>(k, 0)));

        dp[0][0][grid[0][0]%k]=1;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++) {

                if (i==0 && j==0)continue;
                for(int r=0;r<k;r++) {
                    int newR = (r + grid[i][j]) % k;

                    // coming from top
                    if(i>0) dp[i][j][newR] = (dp[i][j][newR] + dp[i-1][j][r]) % MOD;

                    if(j>0)  dp[i][j][newR] = (dp[i][j][newR] + dp[i][j-1][r]) % MOD;
                }
            }
        } 


        return dp[r-1][c-1][0];
    }
};