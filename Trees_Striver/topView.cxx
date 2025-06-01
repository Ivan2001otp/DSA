#include <bits/stdc++.h>

using namespace std;

// TreeNode structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int leftB = INT_MAX;
int rightB = INT_MIN;
void f(Node *root, unordered_map<int, int> &mpp, int v_level)
{

    if (root == nullptr)
        return;

    if (!mpp[v_level])
    {
        mpp[v_level] = root->data;
    }
    leftB = min(leftB, v_level);
    rightB = max(rightB, v_level);

    f(root->left, mpp, v_level - 1);
    f(root->right, mpp, v_level + 1);
}

vector<int> topView(Node *root)
{
    // code here
    map<int, int> mp;
  
    queue<pair<Node *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        auto ele = q.front();
        q.pop();

        int level = ele.second;
        Node *curr = ele.first;

        if (mp.count(level) == 0)
        {
            mp[level] = curr->data;
        }

        if (curr->left)
        {
            q.push({curr->left, level - 1});
        }
        if (curr->right)
        {
            q.push({curr->right, level + 1});
        }
    }
    vector<int>t;
    for (auto a : mp)
    {
        t.push_back(a.second);
    }

    return t;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->right->left = new Node (90);
    // root->right->right = new Node(100);
    // root->left->left = new Node(40);
    root->left->right = new Node(4);
    root->left->right->right = new Node(5);
    root->left->right->right->right = new Node(6);

    topView(root);

    return 0;
}