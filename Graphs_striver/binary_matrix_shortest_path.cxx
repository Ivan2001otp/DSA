#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        queue<pair<int,pair<int,int>>>q;
        int N = grid.size();

        if (grid[0][0]!=0)return -1;
        if (grid[N-1][N-1]!=0) return -1;

        if (N==1) return grid[0][0]==0 ? 1 : -1;

        vector<vector<int>>dirs = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};

        q.push({0,{0, 0}});
        vector<vector<int>>dist(N, vector<int>(N,1e9));

        dist[0][0] = 0;

        

        while(! q.empty()) {
            auto item = q.front();
            q.pop();

            int curr_dist = item.first;
            int x = item.second.first;
            int y = item.second.second;

           

            for(auto it : dirs) {
                int newX = it[0] + x;
                int newY = it[1] + y;

                if (newX>=0 && newX < N && newY>=0 && newY<N && grid[newX][newY]==0 && curr_dist + 1 < dist[newX][newY]) {
                    dist[newX][newY] = curr_dist + 1;

                    if (newX==N-1 && newY==N-1) {
                        return dist[newX][newY] + 1;
                    }
                    q.push({dist[newX][newY],{newX, newY}});
                }
            }

        }

        return -1;
    }