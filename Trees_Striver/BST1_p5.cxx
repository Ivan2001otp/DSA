#include <bits/stdc++.h>
using namespace std;
// link : https://leetcode.com/problems/validate-binary-search-tree/submissions/1661880752/
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 bool checkBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        

        if (root==nullptr)return true;

        if (min != nullptr && root->val <= min->val) {
            return false;
        }

        if (max != nullptr && root->val>=max->val) {
            return false;
        }

        bool leftValid = checkBST(root->left, min, root);
        bool rightValid = checkBST(root->right, root,max);
        return leftValid & rightValid;
    }

    bool isValidBST(TreeNode* root) {
        return checkBST(root, nullptr, nullptr);
    }