#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};
/*
Aliter:
unordered_set<int> s;
bool findTarget(TreeNode* root, int k) {
    if (!root) return false;
    if (s.count(k - root->val)) return true;
    s.insert(root->val);
    return findTarget(root->left, k) || findTarget(root->right, k);
}

*/

void f(TreeNode* root, vector<int>&v) {
        if (root==nullptr)return;

        f(root->left,v);
        v.push_back(root->data);

        f(root->right,v);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>v={};

        f(root, v);

        int l=0, r=v.size()-1;
        int sum;

        while(l<r) {
            sum = v[l] + v[r];
            if (sum == k) {
                return true;
            } else if(sum > k) {
                r--;
            } else{
                l++;
            }
        }

        return false;
    }