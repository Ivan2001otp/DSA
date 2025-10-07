#include <iostream>
using namespace std;

// Node Structure
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Recursive helper function to
// check if two subtrees are mirror images
bool isMirror(Node* leftSub, Node* rightSub) {
    
    if (leftSub == nullptr && rightSub == nullptr) 
        return true;
    
    // One of them is null, so they aren't mirror images
    if (leftSub == nullptr || rightSub == nullptr || 
        			leftSub->data != rightSub->data) {
        return false;
    }
    
    // Check if the subtrees are mirrors
    return isMirror(leftSub->left, rightSub->right) &&
           isMirror(leftSub->right, rightSub->left);
}

bool isSymmetric(Node* root) {
    
    if (root == nullptr) 
        return true;
    
    return isMirror(root->left, root->right);
}

int main() {
    
    // Creating a sample symmetric binary tree
    //       10
    //       / \
    //      5   5
    //     /     \
    //    2       2
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->right->right = new Node(2);

    if(isSymmetric(root))
		cout << "true";
  	else 
      	cout << "false";
    
    return 0;
}