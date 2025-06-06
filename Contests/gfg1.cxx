#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int solve(vector<int>& arr, vector<int>& brr) {
        int i = 0, j = brr.size() - 1, ans = 0;

        while (i < arr.size() and j >= 0) {
            // valid pair
            if (arr[i] < 0 and brr[j] >= 0 and abs(arr[i]) > brr[j]) {
                ans++;
                i++;
                j--;
            }
            // larger positive value
            else if (arr[i] < 0 and brr[j] >= 0) {
                j--;
            } else
                break;
        }
        return ans;
    }

    int maxMatching(vector<int>& arr, vector<int>& brr) {
        // sort both the arrays in non-decreasing order
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        // calculate the pairs
        int ans = solve(arr, brr) + solve(brr, arr);
        return ans;
    }
};

int main() {
    vector<int>v1 = {-1,2,-3,4};
    vector<int>v2 = {1,-2,3,-4};

    f(v1, v2);

}