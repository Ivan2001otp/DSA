#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int,int>>> q;
        map<int, map<int, multiset<int>>>mp;

        q.push({root, {0,0}});

        vector<vector<int>>res;

        while(!q.empty()) {
            auto ele = q.front();
            q.pop();
            TreeNode* node = ele.first;
            int x = ele.second.first;
            int y = ele.second.second;

            mp[x][y].insert(node->val);

            if (node->left) {
                q.push({node->left,{x-1, y+1}});
            }
            
            if (node->right) {
                q.push({node->right,{x+1, y+1}});
            }
        }

        for(auto a : mp) {
            vector<int>temp;
            for(auto b : a.second){
                temp.insert(temp.end(), b.second.begin(), b.second.end());
            }
            res.push_back(temp);
        }

        return res;
    }