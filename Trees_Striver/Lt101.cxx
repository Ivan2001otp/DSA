#include <bits/stdc++.h>

using namespace std;

// TreeNode structure for the binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

bool f(TreeNode *r1, TreeNode *r2)
{

    if (r1 == nullptr && r2 == nullptr)
        return true;

    if ((r1 == nullptr && r2 != nullptr) || (r1 != nullptr && r2 == nullptr))
        return false;

    if (r1->val != r2->val)
        return false;

    bool res1 = f(r1->left, r2->right);
    bool res2 = f(r1->right, r2->left);

    return res1 & res2;
}

bool isSymmetric(TreeNode *root)
{
    return f(root->left, root->right);
}