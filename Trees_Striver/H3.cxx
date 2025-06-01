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

int widthOfBinaryTree(TreeNode *root)
{
    int count = 0;
    queue<pair<TreeNode *, int>> q;

    q.push({root, count});

    while (!q.empty())
    {
        int first, last;
        int n = q.size();
        int mmin = q.front().second;

        for (int i = 0; i < n; i++)
        {
            auto p = q.front();
            q.pop();
            int curr_index = p.second - mmin;

            if (i == 0)
            {
                first = curr_index;
            }

            if (i == n - 1)
            {
                last = curr_index;
            }

            if (p.first->left)
            {
                q.push({p.first->left, 2 * curr_index + 1});
            }
            if (p.first->right)
            {
                q.push({p.first->right, 2 * curr_index + 2});
            }
        }

        cout << last - first + 1 << endl;
        count = max(count, last - first + 1);
    }
    return count;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);

    root->left->left = new TreeNode(5);
    root->left->left->left = new TreeNode(6);

    // root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(7);
    int ans = widthOfBinaryTree(root);
    cout << "Ans is : " << ans << endl;
}