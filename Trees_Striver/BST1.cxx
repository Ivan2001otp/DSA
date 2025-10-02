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

void f22(TreeNode *root, vector<int> &arr)
{
    if (root == nullptr)
        return;

    f22(root->left, arr);

    arr.push_back(root->data);
    f22(root->right, arr);
}

int f2(TreeNode *root, int input)
{
    vector<int> v = {};
    f22(root, v);
    for (auto a : v)
    {
        cout << a << " ";
    }

    auto it = lower_bound(v.begin(), v.end(), input);
    cout << "ceil is ";
    if (it != v.end())
    {
        cout << *it << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return -1;
}

void f(TreeNode *root, int &leftMx, int &rightMx)
{

    if (root == nullptr)
        return;
    if (root->data < leftMx)
    {
        leftMx = root->data;
    }

    if (root->data > rightMx)
    {
        rightMx = root->data;
    }

    f(root->left, leftMx, rightMx);
    f(root->right, leftMx, rightMx);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    int leftMx = INT_MAX;
    int rightMx = INT_MIN;

    // f(root, leftMx, rightMx);

    // cout << "right Mx : " << rightMx << " " << "left Mx : " << leftMx << endl;
    
    f2(root, 3);
    return 0;
}