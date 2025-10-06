#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* f1(TreeNode* r) {

    while(r->left != NULL) {
        r = r->left;
    }

    return r;
}


TreeNode* f2(TreeNode* r) {
    while(r->right != NULL)r = r->right;

    return r;
}

TreeNode* f(TreeNode* key) {
    // successor inorder
    TreeNode* r1 = f1(key->right);

    TreeNode* r2 = f2(key->left);

    cout << "successor : "<<r1->val<<endl;
    cout << "predecessor : "<<r2->val<<endl;

    return nullptr;
}

