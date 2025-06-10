#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int maxSumDistinctTriplet(vector<int> &x, vector<int> &y)
{
    vector<pair<int, int>> v;
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        v.push_back({x[i], y[i]});
    }

    sort(v.begin(), v.end(), [](const pair<int, int> a, const pair<int, int> b)
         { return a.second < b.second; });

    unordered_map<int, bool> vis;
    int sum = 0;

    int k = 3;
    for (int i = v.size() - 1; i >= 0; i--)
    {
        if (!vis[v[i].first])
        {
            vis[v[i].first] = 1;
            sum = sum + v[i].second;
            if (--k == 0)
            {
                break;
            }
        }
        //  cout << v[i].first <<" - "<<v[i].second<<endl;
    }

    if (k != 0)
    {
        return -1;
    }

    return sum;
}

/*
You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.

You are allowed to make at most k transactions, where each transaction can be either of the following:

Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].

Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].

Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.

Return the maximum total profit you can earn by making at most k transactions.
*/
class Solution
{
private:
    vector<vector<vector<long long>>> dp;

public:
    // status: 0 no op, 1 hold, 2 short
    long long helper(const vector<int> &prices, int idx, int status, int cnt)
    {
        if (dp[idx][status][cnt] != INT_MIN)
            return dp[idx][status][cnt];
        if (cnt == 0)
            return 0;
        if (idx == prices.size() - 1)
        {
            if (status == 0)
                return 0;
            if (status == 1)
                return prices[idx];
            return -prices[idx];
        }
        long long noOp = helper(prices, idx + 1, status, cnt);
        if (status == 0)
        {
            // buy or short
            long long buy = -prices[idx] + helper(prices, idx + 1, 1, cnt);
            long long shortSell = prices[idx] + helper(prices, idx + 1, 2, cnt);
            return dp[idx][status][cnt] = max(noOp, max(buy, shortSell));
        }
        else if (status == 1)
        {
            // sell
            long long sell = prices[idx] + helper(prices, idx + 1, 0, cnt - 1);
            return dp[idx][status][cnt] = max(noOp, sell);
        }
        // short -> buy back
        long long cover = -prices[idx] + helper(prices, idx + 1, 0, cnt - 1);
        return dp[idx][status][cnt] = max(noOp, cover);
    }

    long long maximumProfit(vector<int> &prices, int k)
    {
        int n = prices.size();
        dp.resize(n, vector<vector<long long>>(3, vector<long long>(k + 1, INT_MIN)));
        return helper(prices, 0, 0, k);
    }
};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    return 0;
}