#include <bits/stdc++.h>
using namespace std;
#define nl endl;
typedef long long ll;

long long sumXorSubarrays(vector<int> &arr)
{
    int n = arr.size();
    long long totalXorSum = 0;

    for (int k = 0; k < 32; k++)
    {
        ll count_set_bit = 0;
        ll count_0 = 0, count_1 = 0;
        int current_prefix_sum = 0;

        for (int i = 0; i < n; i++)
        {
            current_prefix_sum ^= arr[i];

            if (current_prefix_sum & (1 << k))
            {
                // if odd bit found.
                count_set_bit += count_0;
                count_1++;
            }
            else
            {
                count_set_bit += count_1;
                ++count_0;
            }
        }
        totalXorSum += count_set_bit * (1LL << k);
    }

    return totalXorSum;
}

int main()
{
    vector<int> v = {1, 3};
    cout << sumXorSubarrays(v) << endl;
    return 0;
}