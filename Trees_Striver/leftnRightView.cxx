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

void leftView(Node *root)
{
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {

        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (i == 1)
            {
                
                cout << curr->data << "L ";
            }

            if (i==n) {
                
                cout<<curr->data<<"R ";
            }



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

    leftView(root);

    return 0;
}