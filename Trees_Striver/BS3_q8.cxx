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

string serialize(TreeNode* root) {
    if (!root)return "#,";

    string ans = "";

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()) {

        TreeNode* node = q.front();
        q.pop();

        if (node==NULL)ans += "#,";
        else ans += std::to_string(root->val) + ",";

        if (node)q.push(node->left);
        if (node)q.push(node->right);
    }

    return ans;
}


TreeNode* deserialize(string data) {
    if (data == "#,") {
        return NULL;
    }

    vector<string>words;
    string word;
    stringstream ss;
    while(getline(ss, word, ',')) {
        words.push_back(word);
    }

    TreeNode* root = new TreeNode(std::stoi(words[0]));
    int i=1;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()) {
        int sz = q.size();

        for(int k=0;k<sz;k++) {
            auto tp = q.front();
            q.pop();

            string x = words[i];
            i++;
            string y = words[i];
            i++;

            if (x!="#") {
                tp->left = new TreeNode(tp->val);
            }
            if (y != "#") {
                tp->right = new TreeNode(tp->val);
            }
        }
    }

    return root;
}

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);

    cout << inorder(root);
    return 0;
}