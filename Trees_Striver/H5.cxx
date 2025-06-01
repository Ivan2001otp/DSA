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
void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mpp)
{
    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        auto a = q.front();
        q.pop();

        if (a->left)
        {
            mpp[a->left] = a;
            q.push(a->left);
        }
        if (a->right)
        {
            mpp[a->right] = a;
            q.push(a->right);
        }
    }
}

vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> mp;
    markParents(root, mp);

    for (auto a : mp)
    {
        cout << a.first->val << "->" << a.second->val << endl;
    }

    vector<int> ans;
    unordered_map<TreeNode *, bool> vis;
    vis[target] = true;
    queue<TreeNode *> q;
    q.push(target);
    // int currlevel = 1;

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
                vis[mp[a]] = true;
                q.push(mp[a]);
            }
        }
    }

    while (!q.empty())
    {
        ans.push_back(q.front()->val);
        q.pop();
    }

    return ans;
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