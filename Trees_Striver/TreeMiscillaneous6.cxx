#include <bits/stdc++.h>
using namespace std;
//  link : https://leetcode.com/problems/flood-fill/submissions/1674591485/
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    
    if (image[sr][sc]==color)return image;

    int oldColor = image[sr][sc];
    int row = image.size();
    int col = image[0].size();


    queue<pair<int,int>>q;
    vector<vector<int>>dirs = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    q.push({sr, sc});

    while(!q.empty()) {
        auto a = q.front();
        q.pop();
        int x = a.first, y = a.second;

        for(auto d : dirs) {
            int newX = d[0] + x;
            int newY = d[1] + y;

            if (newX >=0 && newX < row && newY < col && newY>=0 && oldColor == image[newX][newY]) {
                image[newX][newY] = color;
                q.push({newX, newY});
            }
        }
    }

    return image;
}