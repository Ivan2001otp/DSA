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

void preorder(TreeNode *root)
{
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void insertNode(TreeNode *root, int val)
{

    if (root->left == nullptr && root->right == nullptr)
    {
        TreeNode *newNode = new TreeNode(val);

        if (root->data < val)
        {
            root->right = new TreeNode(val);
        }
        else if (root->data > val)
        {
            root->right = new TreeNode(val);
        }
        else
        {
            return;
        }
    }
    if (root->data < val)
    {
        insertNode(root->right, val);
    }

    if (root->data > val)
    {
        insertNode(root->left, val);
    }
}

TreeNode *deleteNode(TreeNode *root, int key)
{

    if (root->data < key)
    {
        root->right = deleteNode(root->right, key);
    }

    else if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return NULL;
        }

        // last but one node has one branch
        if (root->left == nullptr || root->right == nullptr)
        {
            return root->left ? root->left : root->right;
        }

        else
        { // pick the predecessor of inorder
            TreeNode *tmp = root->left;
            while (tmp->right != NULL)
                tmp = tmp->right;

            root->data = tmp->data;
            root->left = deleteNode(root->left, key);
        }
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

    int leftMx = INT_MAX;
    int rightMx = INT_MIN;
    preorder(root);
    insertNode(root, 6);
    cout << endl;
    preorder(root);

    return 0;
}