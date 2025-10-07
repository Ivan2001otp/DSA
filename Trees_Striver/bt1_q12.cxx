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
 
 int widthOfBinaryTree(TreeNode* root) {
        
        if (root == nullptr) return 0;

        int max_width = 1;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});

        while(! q.empty()) {
            int level_size = q.size();
            int start_index = q.front().second;
            int end_index = q.back().second;

            max_width = max(max_width, end_index-start_index+1);

            for(int i=0; i<level_size ;i++) {
            auto curr = q.front();
            int index = curr.second;
            
            TreeNode* node = curr.first;
            q.pop();

            if (node->left) {
                q.push({node->left, 2LL * index  + 1});
            }

            if (node->right) {
                q.push({node->right, 2LL * index + 2});
            }
            }
        }

        return max_width;
    }