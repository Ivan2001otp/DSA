#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<long long >&dat, int mid, int r, int k, int n) {
        vector<long long>tempDiff = dat;

        long long cumSum = 0;
        for(int i=0;i<n;i++) {
            cumSum += tempDiff[i];

            if (cumSum < mid) {
                int need = mid-cumSum;

                if (need > k)return false;

                k = k - need;
                cumSum += need;

                if (i + 2*r + 1 <n) {
                    tempDiff[i + 2*r + 1] -= need;
                }
            }
        }

        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {

        long long result;
        int n = stations.size();
        vector<long long>dat(n, 0);

        for(int i=0; i<n; i++) {
            dat[max(0,i-r)] += stations[i];
            if (i+r+1 < n) {
                dat[i+r+1] -= stations[i];
            }
        }


        long long left = *min_element(begin(stations), end(stations));
        long long right = accumulate(begin(stations), end(stations), 0LL) + k;

        while(left <= right) {
            int mid = left + (right- left)/2;

            if (check(dat,mid, r, k, n )) {
                result = mid;
                low = mid+1;
            } else {
                high = mid-1;
            }
        }

        return result;
    }
};