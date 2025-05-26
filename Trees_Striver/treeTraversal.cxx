#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        this->left = this->right = nullptr;
    }
};

void preorder(Node *root)
{
    if (root == nullptr)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void inorder(Node *root)
{

    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorderIt(Node *root)
{
    if (root == nullptr)
        return;
    stack<Node *> st;
    st.push(root);
    vector<int> ds;

    while (!st.empty())
    {
        Node *ele = st.top();
        st.pop();

        ds.push_back(ele->data);
        if (ele->right)
        {
            st.push(ele->right);
        }
        if (ele->left)
        {
            st.push(ele->left);
        }
    }

    for (auto a : ds)
    {
        cout << a << " ";
    }
}

void postorderIt(Node *root)
{
    if (root == nullptr)
    {
        return;
    }

    vector<int> ds;
    stack<Node *> st;

    st.push(root);

    while (!st.empty())
    {
        Node *curr = st.top();
        st.pop();
        ds.push_back(curr->data);

        if (curr->left)
        {
            st.push(curr->left);
        }

        if (curr->right)
        {
            st.push(curr->right);
        }
    }

    reverse(ds.begin(), ds.end());

    for (auto a : ds)
    {
        cout << a << " ";
    }
}

void inorderIt(Node *root)
{
    stack<Node *> st;
    vector<int> ds;
    Node *current = root;

    while (current || !st.empty())
    {

        while (current)
        {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();
        ds.push_back(current->data);
        current = current->right;
    }

    for (auto a : ds)
    {
        cout << a << " ";
    }
}

void levelOrderTraversal(Node *root)
{

    if (root == NULL)
        return;
    queue<Node *> q;

    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            Node *curr = q.front();
            q.pop();

            cout << curr->data << " ";

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

void prePostInorderTraversal(Node* root) {
    vector<int>pre, post, in;

    if (root == nullptr) {
        return;
    }

    stack<pair<Node*, int>> st;

    st.push({root, 1});

    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if (it.second == 1) {
            //preorder
            pre.push_back(it.first->data);

            it.second = 2;//inorder state

            st.push(it);

            if (it.first -> left != nullptr) {
                st.push({it.first -> left, 1});
            }
        } else if (it.second == 2) {

            in.push_back(it.first->data);
            it.second = 3;

            st.push(it);

            if (it.first -> right != nullptr) {
                st.push({it.first->right, 1});
            }
        } else {
            post.push_back(it.first -> data);
        }
    }


    vector<vector<int>>result;
    result.push_back(pre);
    result.push_back(in);
    result.push_back(post);

    return;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(2);
    root->right = new Node(1);
    root->right->left = new Node(4);

    levelOrderTraversal(root);
    // postorder(root);
    //  cout << endl;
    //  postorderIt(root);
    //  postorder(root);
    //  cout << endl;
    //  inorder(root);

    return 0;
}