#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// TreeNode structure for the binary tree
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize
    // the TreeNode with a value
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isSameTree(TreeNode *r1, TreeNode *r2)
{
    if (r1 == nullptr && r2 == nullptr)
    {
        return true;
    }

    if ((r1 == nullptr && r2 != nullptr) || (r1 != nullptr && r2 == nullptr))
        return false;

    if (r1->data != r2->data)
        return false;

    bool left = isSameTree(r1->left, r2->left);
    bool right = isSameTree(r1->right, r2->right);

    return left & right;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(1);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(1);
    root2->right = new TreeNode(2);

    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->left->right->right = new TreeNode(6);
    // root->left->right->right->right = new TreeNode(7);

    if (isSameTree(root, root2))
        cout << "Is Same";
    else
        cout << "not same";

    return 0;
}