#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    int isLeftToRight = true;
    queue<TreeNode *> q;
    q.push(root);

    vector<vector<int>> res;

    while (!q.empty())
    {
        int n = q.size();
        vector<int> ans;
        for (int i = 1; i <= n; i++)
        {
            auto curr = q.front();
            ans.push_back(curr->val);
            q.pop();

            if (isLeftToRight)
            {
                if (curr->right)
                {
                    q.push(curr->right);
                }

                if (curr->left)
                {
                    q.push(curr->left);
                }
            }
            else
            {
                if (curr->left)
                {
                    q.push(curr->left);
                }

                if (curr->right)
                {
                    q.push(curr->right);
                }
            }
        }
        res.push_back(ans);

        isLeftToRight = !isLeftToRight;
    }

    for (auto e1 : res)
    {
        for (auto ele : e1)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return res;
}


void markParents(unordered_map<TreeNode*, TreeNode*>& parents, TreeNode* root) {

    queue<TreeNode*>q;
    q.push(root);

    while (! q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr->left) {
            parents[curr->left] = curr;
        }

        if (curr->right) {
            parents[curr->right] = curr;
        }
    }
}

vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

    unordered_map<TreeNode*, bool> vis;
    unordered_map<TreeNode*, TreeNode*>parent;

    markParents(parent, root);

    queue<TreeNode*>q;
    q.push(root);
    vis[root] = true;
    vector<int>res;

    while(! q.empty()) {
        int n = q.size();
        if (k-- == 0){
            break;
        }

        for(int i=0;i<n;i++) {
            auto curr = q.front();
            q.pop();

            if (curr->left!= nullptr && !vis[curr->left]) {
                vis[curr->left] = true;
                q.push(curr->left);
            }

            if (curr->right != nullptr && !vis[curr->right]) {
                vis[curr->right] = true;
                q.push(curr->right);
            }

            if (parent[curr] != nullptr && !vis[parent[curr]]) {
                vis[parent[curr]] = true;
                q.push(parent[curr]);
            }
        }
    }

    while( !q.empty()) {
        res.push_back(q.front());
        q.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    f1(root);
    return 0;
}