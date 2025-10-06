#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>>pq;

        for(auto a : nums) {
            if (pq.size() < k){
                pq.push(a);
            } else if (pq.top() < a) {
                pq.push(a);
                pq.pop();
            }
        }

        return pq.top();
}