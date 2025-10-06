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
// https://leetcode.com/problems/kth-largest-element-in-a-stream/
class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>>pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(auto a : nums ){ 
            if (pq.size() < K) {
                pq.push(a);
            } else if (a > pq.top()) {
                pq.push(a);
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        
        if (pq.size() < K) {
            pq.push(val);
        } else if (pq.top() < val) {
            pq.push(val);
            pq.pop();
        }

        return pq.top();
    }
};