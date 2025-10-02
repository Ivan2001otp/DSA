#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Note : for kth maximum do reverse inorder traversal

// for kth minimum element.
void inorder(TreeNode* node, int& counter, int k, int& ksmall) {

    if (!node || counter>=k)return;
    
    inorder(node->left, counter, k ,ksmall);
    ++counter;

    if (counter == k) {
        ksmall = node->data;
        return;
    }
    inorder(node->right, counter, k ,ksmall);
}