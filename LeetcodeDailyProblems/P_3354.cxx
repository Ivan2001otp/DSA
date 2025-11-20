#include <bits/stdc++.h>
using namespace std;
#define nl endl;

bool f(vector<int> nums, int index, bool isRight)
{

    int n = nums.size();
    while (true)
    {

        if (index < 0 || index > n - 1)
        {
            break;
        }

        if (nums[index] > 0)
        {
            nums[index] -= 1;
            isRight = !isRight;

            if (isRight)
            {
                index += 1;
            }
            else
            {
                index -= 1;
            }
        }

        else if (nums[index] == 0)
        {

            if (isRight)
            {
                index += 1;
            }
            else
            {
                index -= 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++)
        count = count | nums[i];

    return count == 0;
}

int countValidSelections(vector<int> &nums)
{
    /*


    This approach does not work  - 342/584

    int n = nums.size();
    vector<int> prefixSum(n + 1, 0);
    vector<int> suffixSum(n + 1, 0);

    prefixSum[0] = nums[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = nums[i] + prefixSum[i - 1];
    }

    suffixSum[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffixSum[i] = suffixSum[i + 1] + nums[i];
    }

    for (auto a : prefixSum)
        cout << a << " ";
    cout << endl;
    for (auto a : suffixSum)
        cout << a << " ";

    int count = 0;
    int prefix, suffix;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            prefix = (i - 1 >= 0) ? prefixSum[i - 1] : 0;
            suffix = (i + 1 <= n - 1) ? suffixSum[i + 1] : 0;

            if (prefix == suffix)
                count += 2;
        }
    }
    cout << nl;
    cout << "Result is " << count << nl;
    return count;
    */

    // tc - N * N  (naive)
    /*
    int n = nums.size();
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {

            if (f(nums, i, true))
                ++counter;

            if (f(nums, i, false))
                ++counter;
        }
    }

    return counter;
    */

    int n = nums.size();
    int ans = 0;
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int leftSum = 0, rightSum = sum;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            if (leftSum - rightSum >= 0 && leftSum - rightSum <= 1)
                ans++;
            if (rightSum - leftSum >= 0 && rightSum - leftSum <= 1)
                ans++;
        }
        else
        {
            leftSum += nums[i];
            rightSum -= nums[i];
        }
    }

    return ans;
}

int main()
{
    vector<int> v = {16, 13, 10, 0, 0, 0, 10, 6, 7, 8, 7};

    cout << "Result is " << countValidSelections(v) << endl;
    return 0;
}