#include <bits/stdc++.h>

using namespace std;

// TreeNode structure for the binary tree
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize
    // the TreeNode with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int f(TreeNode *root, int &ans)
{

    if (root == nullptr)
        return 0;

    int lh = f(root->left, ans);
    int rh = f(root->right, ans);

    int maxNode = max(root->data, max(lh + rh + root->data, max(root->data + lh, root->data + rh)));
    ans = max(ans, maxNode);

    return max(root->data, max(root->data + lh, root->data + rh));
}

int maxPathSum(TreeNode *root)
{
    int res = INT_MIN;
    f(root, res);
    return res;
}

int main()
{
    TreeNode *root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << maxPathSum(root) << endl;

    return 0;
}