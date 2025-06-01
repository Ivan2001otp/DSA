#include <bits/stdc++.h>

using namespace std;

// TreeNode structure for the binary tree
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void leftBoundaryT(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
        return;

    if (root->left || root->right)
    {
        ans.push_back(root->data);
    }
    else
        return;

    if (root->left)
    {
        leftBoundaryT(root->left, ans);
    }
    else
    {
        leftBoundaryT(root->right, ans);
    }
}

void rightBoundaryT(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
        return;

    if (root->right || root->left)
    {
        ans.push_back(root->data);
    }
    else
        return;

    if (root->right)
    {
        rightBoundaryT(root->right, ans);
    }
    else
    {
        rightBoundaryT(root->left, ans);
    }
}

void leafNodes(TreeNode *root, vector<int> &ans)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(root->data);
    }

    leafNodes(root->left, ans);
    leafNodes(root->right, ans);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);

    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(9);
    root->left->right->left = new TreeNode(8);

    root->right = new TreeNode(3);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(6);

    vector<int> ans;
    vector<int> r;
    ans.push_back(root->data);
    leftBoundaryT(root->left, ans);
    leafNodes(root, ans);
    rightBoundaryT(root->right, r);

    for (int i = r.size() - 1; i >= 0; i--)
    {
        ans.push_back(r[i]);
    }
    for (auto a : ans)
        cout << a << " ";
    return 0;
}