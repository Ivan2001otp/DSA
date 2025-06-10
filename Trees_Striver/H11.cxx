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

string serialize(TreeNode *root)
{
    if (root == nullptr)
    {
        return "";
    }
    vector<string> result;

    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        int N = q.size();

        for (int i = 0; i < N; i++)
        {
            TreeNode *s = q.front();
            q.pop();

            if (s != nullptr)
            {
                result.push_back(to_string(s->data));
                result.push_back(",");
            }
            else
            {
                result.push_back("#");
                result.push_back(",");
                continue;
            }

            if (s->left)
            {
                q.push(s->left);
            }
            else
            {
                q.push(nullptr);
            }

            if (s->right)
            {
                q.push(s->right);
            }
            else
            {
                q.push(nullptr);
            }
        }
    }

    for (int i = result.size() - 1; i >= 0; i--)
    {
        if (result[i] == ",")
        {
            result.pop_back();
        }
        else if (result[i] == "#")
        {
            result.pop_back();
        }
        else
        {
            break;
        }
    }

    string ans = "";

    for (auto a : result)
        ans += a;

    return ans;
}

void constructTree(TreeNode *root, int index, int N, vector<int> v)
{
    cout << "index : " << index << endl;

    if (index >= N)
        return;

    TreeNode *leftNode = nullptr;
    TreeNode *rightNode = nullptr;

    int leftIndx = 2 * index + 1;
    int rightIndx = 2 * index + 2;
    cout << "left Index : " << leftIndx << ", right Index : " << rightIndx << endl;

    if (leftIndx < N)
    {

        if (v[leftIndx] != -1e4)
        {
            leftNode = new TreeNode(v[leftIndx]);
        }
        else
        {
            cout << "At index " << leftIndx << " got null node" << endl;
        }
    }

    if (rightIndx < N)
    {
        if (v[rightIndx] != -1e4)
        {
            rightNode = new TreeNode(v[rightIndx]);
        }
        else
        {
            cout << "At index " << rightIndx << " got null node" << endl;
        }
    }

    root->left = leftNode;
    root->right = rightNode;
    constructTree(root->left, 2 * index + 1, N, v);
    constructTree(root->right, 2 * index + 2, N, v);
}

void preOrder(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

TreeNode *deserialize(string data)
{
    if (data.size() == 0)
        return nullptr;
    queue<int> q;
    vector<int> v;

    for (int i = 0; i < data.size(); i++)
    {
        if (data[i] == ',')
        {
        }
        else
        {
            if (data[i] == '#')
            {
                v.push_back(-1e4);
            }
            else
            {
                int val = data[i] - '0';
                v.push_back(val);
            }
        }
    }

    int N = v.size();
    TreeNode *root = new TreeNode(v[0]);

    TreeNode *temp = root;
    constructTree(root, 0, N, v);
    if (root)
    {
        cout << "root exists";
    }
    else
    {
        cout << "root is null" << root;
    }
    preOrder(temp);
    return nullptr;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    deserialize(serialize(root));

    return 0;
}