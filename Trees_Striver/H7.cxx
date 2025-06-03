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

void f(TreeNode *root, int &count)
{
    if (root == nullptr)
        return;

    count++;
    f(root->left, count);
    f(root->right, count);
}

// count the total nodes in tree
int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    int count = 0;
    f(root, count);

    cout << count << endl;

    return 0;
}