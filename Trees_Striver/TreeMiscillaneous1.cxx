#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void flatten(TreeNode *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return;

    if (root->left)
    {
        flatten(root->left);

        TreeNode *temp = root->right;
        root->right = root->left;
        TreeNode *t = root->right;
        root->left = NULL;

        while (t->right != NULL)
            t = t->right;

        t->right = temp;
    }

    flatten(root->right);
}

void print(TreeNode *root)
{
    TreeNode *temp = root;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->right;
    }
    delete temp;
    return;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->right = new TreeNode(4);
    root->left->left = new TreeNode(3);

    root->right->right = new TreeNode(6);

    flatten(root);

    print(root);
    return 0;
}
