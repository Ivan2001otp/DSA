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

int f(TreeNode *root)
{

    if (root == nullptr)
    {
        return 0;
    }

    int leftNode = f(root->left);

    int rightNode = f(root->right);

    if (leftNode == -1 || rightNode == -1)
    {
        return -1;
    }

    if (leftNode == 0 && rightNode == 0)
    {
        // its a child node.
        return root->data;
    }

    // cout << "(leftNode :) " << leftNode << "  + (rightNode :) " << rightNode << " => (root) " << root->data << endl;

    if (leftNode + rightNode == root->data)
    {
        return root->data;
    }

    return -1;
}

int isSumProperty(TreeNode *root)
{
    // Add your code here

    bool result = (-1 != f(root));
    if (result)
    {
        cout << "result : " << 1 << endl;
    }
    else
    {
        cout << "result : " << 0 << endl;
    }

    return result;
}

int main()
{
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(4);
    root->right = new TreeNode(6);

    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);

    isSumProperty(root);

    return 0;
}