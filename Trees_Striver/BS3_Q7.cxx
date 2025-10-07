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

class SubTree {

    public :
        bool isBst;
        int sum;
        int min;
        int max;
};

SubTree f(TreeNode* root, int &ans) {

        if (root == NULL) {
            return {true, 0,INT32_MAX, INT32_MIN};
        }

        SubTree left = f(root->left, ans);
        SubTree right = f(root->right, ans);
        
        SubTree curr;
        curr.sum = left.sum + right.sum + root->val;
        curr.min = min(root->val, left.min);
        curr.max = max(root->val, right.max);

        curr.isBst = left.isBst && right.isBst && (root->val > left.max) && (root->val < right.min);

        if (curr.isBst) {
            ans = max(ans, curr.sum);
        }

        return curr;
    }

    int maxSumBST(TreeNode* root) {
        int totalSum = 0;
        f(root, totalSum);
        return totalSum;
    }

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

   
}
