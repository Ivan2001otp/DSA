#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    bool isBalanced(Node *root)
    {
        return dfsHeight(root) != -1;
    }

    int dfsHeight(Node *root)
    {

        if (root == nullptr)
        {
            return 0;
        }

        int lh = dfsHeight(root->left);
        if (lh == -1)
        {
            return -1;
        }

        int rh = dfsHeight(root->right);
        if (rh == -1)
            return -1;

        if (abs(lh - rh) > 1)
        {
            return -1;
        }

        return max(lh, rh) + 1;
    }
};

// Main function
int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class
    Solution solution;

    // Checking if the tree is balanced
    if (solution.isBalanced(root))
    {
        cout << "The tree is balanced." << endl;
    }
    else
    {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}