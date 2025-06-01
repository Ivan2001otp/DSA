#include <bits/stdc++.h>

using namespace std;

// TreeNode structure for the binary tree
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize
    // the TreeNode with a value
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

// int rightMax = INT_MIN;
// int leftMax = INT_MAX;
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    queue<pair<TreeNode *, pair<int, int>>> q;
    map<int, map<int, multiset<int>>> mp;

    q.push({root, {0, 0}});

    vector<vector<int>> res;

    while (!q.empty())
    {
        auto ele = q.front();
        q.pop();
        TreeNode *node = ele.first;
        int x = ele.second.first;
        int y = ele.second.second;

        mp[x][y].insert(node->val);

        if (node->left)
        {
            q.push({node->left, {x - 1, y + 1}});
        }

        if (node->right)
        {
            q.push({node->right, {x + 1, y + 1}});
        }
    }

    for (auto a : mp)
    {
        vector<int> temp;
        for (auto b : a.second)
        {
            temp.insert(temp.end(), b.second.begin(), b.second.end());
        }
        res.push_back(temp);
    }

    return res;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    // root->left->left = new TreeNode(0);
    // root->left->right = new TreeNode(2);

    vector<vector<int>> v;

    v = verticalTraversal(root);

    for (auto a : v)
    {
        for (auto a1 : a)
        {
            cout << a1 << " ";
        }
        cout << endl;
    }

    return 0;
}