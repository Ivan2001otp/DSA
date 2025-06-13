#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// You are given a 2D string array responses where each responses[i] is an array of strings representing survey responses from the ith day.
// Return the most common response across all days after removing duplicate responses within each responses[i]. If there is a tie, return the lexicographically smallest response.

class Solution
{
public:
    string findCommonResponse(vector<vector<string>> &responses)
    {

        int row = responses.size();
        unordered_map<string, int> mp;
        set<string> st;

        for (int i = 0; i < row; i++)
        {

            for (int j = 0; j < responses[i].size(); j++)
            {
                string s = responses[i][j];

                if (st.find(s) == st.end())
                {
                    // not in set then add
                    st.insert(s);
                    mp[s]++;
                }
                else
                {
                    // cout <<"string "<<s<<" already present !"<<endl;
                }
            }
            st.clear();
        }

        vector<pair<string, int>> v;
        for (auto a : mp)
        {
            // cout <<a.first<<" : "<<a.second<<endl;
            v.push_back({a.first, a.second});
        }

        sort(v.begin(), v.end(), [](const pair<string, int> &a, const pair<string, int> &b)
             {
            if (a.second==b.second) {
                int i=0;
                
                while(a.first[i] == b.first[i] && i<a.first.size() && i<b.first.size()) i++;
                
                return a.first[i]-'a' < b.first[i] - 'a';
            }

            return a.second < b.second; });

        string res = "";
        int maxi = INT_MIN;

        for (auto a : v)
        {
            int freq = a.second;
            string s1 = a.first;

            if (freq > maxi)
            {
                maxi = freq;
                res = s1;
            }
        }

        return res;
    }
};


void solve() {
// check this problem and its solution as well 
//https://leetcode.com/problems/count-cells-in-overlapping-horizontal-and-vertical-substrings/solutions/6689467/c-kmp-beginner-friendly-clean-intuitive-solution
// also dry run it.
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}