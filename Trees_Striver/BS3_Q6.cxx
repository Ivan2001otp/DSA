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
 

class BSTIterator {
public:
    TreeNode* temp = NULL;
    stack<TreeNode*>st;

    BSTIterator(TreeNode* root) {
        temp = root;
    }
    
    int next() {

        while (temp != NULL) {
            st.push(temp);
            temp = temp->left;
        }    

        TreeNode* x = st.top();
        st.pop();

        temp = x -> right;
        return x->val;
    }
    
    bool hasNext() {
        return !st.empty() ||  temp!=NULL;
    }
};