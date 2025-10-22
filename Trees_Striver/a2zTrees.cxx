#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// pre-post-in
vector<vector<int>> preInPostTraversal(TreeNode *root)
{
    vector<int> inorder, preorder, postorder;
    vector<vector<int>> res;

    if (root == nullptr)
        return {{}};

    stack<pair<TreeNode *, int>> st;
    st.push({root, 1});

    while (!st.empty())
    {
        auto curr = st.top();
        st.pop();

        if (curr.second == 1)
        {

            preorder.push_back(curr.first->val);
            curr.second = 2;
            st.push(curr);

            if (curr.first->left != nullptr)
            {
                st.push({curr.first->left, 1});
            }
        }
        else if (curr.second == 2)
        {

            inorder.push_back(curr.first->val);
            curr.second = 3;
            st.push(curr);

            if (curr.first->right != nullptr)
            {
                st.push({curr.first->right, 1});
            }
        }
        else
        {
            postorder.push_back(curr.first->val);
        }
    }
}

// iterative postorder
vector<int> postorderTraversal(TreeNode *root)
{
    TreeNode *curr;
    vector<int> post;

    if (root == nullptr)
        return post;
    curr = root;

    stack<TreeNode *> st;

    while (curr != nullptr || !st.empty())
    {

        if (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == nullptr)
            {
                temp = st.top();
                st.pop();
                post.push_back(temp->val);

                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    post.push_back(temp->val);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
}

// iterative inorder
vector<int> inorderTraversal(TreeNode *root)
{
    vector<int> inorder;
    stack<TreeNode *> st;

    TreeNode *curr = root;

    while (curr != nullptr || !st.empty())
    {

        while (curr != nullptr)
        {
            st.push(curr);
            curr = curr->left;
        }

        inorder.push_back(st.top()->val);
        st.pop();
        curr = st.top();
        curr = curr->right;
    }

    return inorder;
}

// max height of the tree
int maxDepth(TreeNode *root)
{

    if (root == nullptr)
    {
        return 0;
    }

    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);

    return max(lh, rh) + 1;
}

// is Tree balanced or not
int f(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    int lhR = f(root->left);
    if (lhR == -1)
        return -1;

    int rhR = f(root->right);
    if (rhR == -1)
        return -1;

    if (abs(lhR - rhR) > 1)
        return -1;

    return max(lhR, rhR) + 1;
}

bool isBalanced(TreeNode *root)
{

    return f(root) != -1;
}

// diameter of the tree
int res = 0;
int f(TreeNode *root)
{

    if (root == nullptr)
        return 0;
    int lh = f(root->left);
    int rh = f(root->right);

    res = max(res, lh + rh);
    return max(lh, rh) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{

    f(root);

    return res;
}