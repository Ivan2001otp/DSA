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

void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
{
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {

        auto a = q.front();
        q.pop();

        if (a->left)
        {
            parent[a->left] = a;
            q.push(a->left);
        }

        if (a->right)
        {
            parent[a->right] = a;
            q.push(a->right);
        }
    }
}

TreeNode *findNode(TreeNode *root, int target)
{
    if (root == nullptr)
        return nullptr;

    if (root->data == target)
    {
        return root;
    }

    TreeNode *lt = findNode(root->left, target);

    if (lt != nullptr)
        return lt;

    TreeNode *rt = findNode(root->right, target);

    return rt;
}

int minTime(TreeNode *root, int target)
{
    unordered_map<TreeNode *, TreeNode *> parent;
    markParents(root, parent);

    queue<TreeNode *> q;
    unordered_map<TreeNode *, bool> vis;

    TreeNode *startNode = findNode(root, target);

    vis[startNode] = true;

    q.push(startNode);

    int time = 0;

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 1; i <= n; i++)
        {
            auto a = q.front();
            q.pop();

            if (a->left && !vis[a->left])
            {
                q.push(a->left);
                vis[a->left] = true;
            }

            if (a->right && !vis[a->right])
            {
                q.push(a->right);
                vis[a->right] = true;
            }

            if (parent[a] && !vis[parent[a]])
            {
                q.push(parent[a]);
                vis[parent[a]] = true;
            }
        }

                ++time;
    }

    return --time;
}

int main()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // root->right->left->left = new TreeNode(6);

    cout << minTime(root, 2) << endl;

    return 0;
}