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

bool f(TreeNode *root, int target, vector<int> &v)
{
    if (root == nullptr)
        return false;

    if (target == root->data)
    {
        v.push_back(root->data);
        return true;
    }

    bool lh = f(root->left, target, v);

    if (lh)
    {
        v.push_back(root->data);
        return true;
    }

    bool rh = f(root->right, target, v);

    if (rh)
    {
        v.push_back(root->data);
        return true;
    }

    return false;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    root->right->right->left = new TreeNode(6);

    int target = 12;

    vector<int> v = {};
    if (f(root, target, v))
    {
        reverse(v.begin(), v.end());
        for (auto a : v)
        {
            cout << a << " ";
        }
    }
    else
    {
        cout << "Path not exists " << endl;
    }
}