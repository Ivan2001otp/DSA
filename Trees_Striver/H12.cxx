#include <bits/stdc++.h>
using namespace std;


// morris traversal preorder/inorder
// TreeNode structure for the binary tree
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void f(TreeNode* root, vector<int> &ans) {

    TreeNode* curr = root;

    while(curr != nullptr) {
        
        if (curr->left == nullptr) {
            ans.push_back(curr->data);
            curr = curr->right;
        } else {

            TreeNode* prev = root->left;

            while(prev->right && prev->right != curr)prev = prev->right;

            if (prev->right == nullptr) {
                prev->right = curr;
                curr = curr -> left;
            } else {
                prev->right = nullptr;
                ans.push_back(curr->data);
                curr=curr->right;
            }

        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    vector<int> ans;
    f(root, ans);
}