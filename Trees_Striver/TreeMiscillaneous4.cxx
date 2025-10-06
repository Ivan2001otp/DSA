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



// link : https://takeuforward.org/plus/dsa/problems/distinct-numbers-in-each-subarray
vector<int> distinctNumbers(vector<int> &nums, int k)
{
    // Your code goes here
    unordered_map<int, int> mp;
    vector<int> v;

    for (int i = 0; i < k; i++)
    {
        mp[nums[i]]++;
    }

    v.push_back(mp.size());

    for (int i = k; i < nums.size(); i++)
    {

        if (mp.count(nums[i - k]) > 0)
        {
            mp[nums[i - k]]--;

            if (mp[nums[i - k]] == 0)
            {
                mp.erase(nums[i - k]);
            }
        }

        mp[nums[i]]++;
        v.push_back(mp.size());
    }

    return v;
}

int main()
{

    vector<int> v = {1, 1, 1, 1, 2, 3, 4};
    int k = 4;
    vector<int> t = distinctNumbers(v, k);
    for (auto a : t)
    {
        cout << a << " ";
    }

    return 0;
}