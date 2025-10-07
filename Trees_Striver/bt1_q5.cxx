#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


vector<int> getPreorder(TreeNode* root) {
    vector<int>preorder;
    TreeNode* curr = root;

    while(curr != NULL) {

        if (curr->left == nullptr) {
            preorder.push_back(curr->val);
            curr = curr->right;
        } else {
            TreeNode* prev = curr->left;

            while(prev->right != nullptr && prev->right != curr) {
                prev = prev->right;
            }

            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr->left;
            } else {
                prev->right = nullptr;
                preorder.push_back(curr->val);
                curr = curr->right;
            }
        }
    }

    return preorder;
}