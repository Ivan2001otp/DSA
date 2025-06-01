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

    v.push_back(root->data);

    if (root->data == target)
    {
        return true;
    }

    bool lh = f(root->left, target, v);
    bool rh = f(root->right, target, v);

    if (rh || lh)
    {
        return true;
    }

    v.pop_back();

    return false;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    // base case
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    // result
    if (left == NULL)
    {
        return right;
    }
    else if (right == NULL)
    {
        return left;
    }
    return root;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(7);

    vector<int> v1, v2;
    int n1 = 7, n2 = 6;

    if (f(root, n1, v1) && f(root, n2, v2))
    {
        int s1 = v1.size();
        int s2 = v2.size();

        int index;
        for (int i = 0; i < min(s1, s2); i++)
        {
            if (v1[i] != v2[i])
            {
                index = i - 1;
                break;
            }
        }

        cout << "LCA : " << v1[index] << endl;
    }
    else
    {
        cout << "Nodes not found !" << endl;
    }
}