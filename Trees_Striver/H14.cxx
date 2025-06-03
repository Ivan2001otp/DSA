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

void preorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    preorder(root->left);
    preorder(root->right);
    cout << root->data << " ";
}

void flatten(TreeNode *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    if (root->left)
    {
        flatten(root->left);

        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = NULL;

        TreeNode *t = root->right;
        while (t->right != nullptr)
            t = t->right;

        t->right = temp;
    }

    flatten(root->right);
}

// count the total nodes in tree
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    preorder(root);
    flatten(root);
    cout << endl;
    preorder(root);
    return 0;
}