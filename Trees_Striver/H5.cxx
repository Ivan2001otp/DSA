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

int getHeight(TreeNode *root)
{

    if (root == nullptr)
        return 0;
    int lh = getHeight(root->left);
    int rh = getHeight(root->right);

    return max(lh, rh) + 1;
}

void f1(unordered_map<TreeNode *, TreeNode *> &mp, TreeNode *root)
{

    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {

        TreeNode *p = q.front();
        q.pop();

        if (p->left)
        {
            mp[p->left] = p;
            q.push(p->left);
        }
        if (p->right)
        {
            mp[p->right] = p;
            q.push(p->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{

    unordered_map<TreeNode *, TreeNode *> mp;
    f1(mp, root);

    vector<int> v;
    unordered_map<TreeNode *, bool> vis;
    vis[target] = true;

    queue<TreeNode *> q;

    q.push(target);

    while (!q.empty())
    {
        int n = q.size();

        if (k-- == 0)
        {

            break;
        }

        for (int i = 0; i < n; i++)
        {
            auto a = q.front();
            q.pop();

            if (a->left && !vis[a->left])
            {
                vis[a->left] = true;
                q.push(a->left);
            }

            if (a->right && !vis[a->right])
            {
                vis[a->right] = true;
                q.push(a->right);
            }

            if (mp[a] && !vis[mp[a]])
            {
                q.push(mp[a]);
                vis[mp[a]] = true;
            }
        }
    }

    while (!q.empty())
    {
        v.push_back(q.front()->data);
        q.pop();
    }

    for (auto a : v)
    {
        cout << a << " ";
    }

    return {};
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(5);
    root->right = new TreeNode(1);

    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);

    // root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(8);
    root->right->left = new TreeNode(0);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    TreeNode *t = new TreeNode(5);
    distanceK(root, t, 2);
    return 0;
}