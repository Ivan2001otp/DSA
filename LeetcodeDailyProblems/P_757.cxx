/*
    757. Set Intersection Size At Least Two
You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.

A containing set is an array nums where each interval from intervals has at least two integers in nums.

For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
Return the minimum possible size of a containing set.


Examples :
Input: intervals = [[1,3],[3,7],[8,9]]
Output: 5
Explanation: let nums = [2, 3, 4, 8, 9].
It can be shown that there cannot be any containing array of size 4.

Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
Output: 3
Explanation: let nums = [2, 3, 4].
It can be shown that there cannot be any containing array of size 2.

Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
Output: 5
Explanation: let nums = [1, 2, 3, 4, 5].
It can be shown that there cannot be any containing array of size 4.

Constraints:
1 <= intervals.length <= 3000
intervals[i].length == 2
0 <= starti < endi <= 108
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int> > &intervals)
    {
        int n = intervals.size();

        auto lambda = [](auto &vec1, auto &vec2)
        {
            if (vec1[1] != vec2[1])
            {
                return vec1[1] < vec2[1];
            }
            return vec1[0] > vec2[0];
        };
        sort(intervals.begin(), intervals.end(), lambda);

        int result = 0, first = -1, second = -1;

        for (int i = 0; i < n; i++)
        {
            int l = intervals[i][0];
            int r = intervals[i][1];

            if (l <= first)
                continue;

            if (l > second)
            {
                result += 2;
                second = r;
                first = r - 1;
            }
            else
            {
                result += 1;
                first = second;
                second = r;
            }
        }

        return result;
    }
};