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

// Link : https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
public:
    priority_queue<int>maxHp;
    priority_queue<int, vector<int>, greater<int>> minHp;

    MedianFinder() {
      
    }
    
    void addNum(int num) {
      maxHp.push(num);
      minHp.push(maxHp.top());
      maxHp.pop();

      if (minHp.size() > maxHp.size()) {
        maxHp.push(minHp.top());
        minHp.pop();
      }

    }
    
    double findMedian() {
       if (maxHp.size() > minHp.size()) return maxHp.top();
       return (minHp.top() + maxHp.top())/ 2.0;
    }
};  