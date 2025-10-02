#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int findCeil(TreeNode *root, int val)
{
    TreeNode *curr = root;
    int res = -1;
    while (curr != nullptr)
    {

        if (curr->data > val)
        {
            res = curr->data;
            curr = curr->left;
        }
        else if (curr->data < val)
        {
            curr = curr->right;
        }
        else
        {
            return curr->data;
        }
    }

    return res;
}

int findFloor(TreeNode *root, int val)
{

    TreeNode *temp = root;
    int res = -1;

    while (temp != NULL)
    {
        if (temp->data < val)
        {
            res = temp->data;
            temp = temp->right;
        }
        else if (temp->data > val)
        {
            temp = temp->left;
        }
        else
        {
            return temp->data;
        }
    }

    return res;
}

int main()
{
    TreeNode *root = new TreeNode(8);
    root->left = new TreeNode(4);
    root->right = new TreeNode(12);

    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);

    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(14);

    int n = findFloor(root, 11);
    cout << n << endl;
    return 0;
}