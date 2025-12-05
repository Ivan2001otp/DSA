// https:leetcode.com/problems/count-distinct-integers-after-removing-zeros/
/*
class Solution {
public:
    long long countDistinct(long long n) {
        string digits = std::to_string(n);
        int m = digits.size();

        vector<long long>pow9(m+1, 1);
        for(int i=1;i<=m;i++) {
            pow9[i] = pow9[i-1] * 9LL;
        }

        long long total = 0;
        for(int l=1;l<n;l++) {
            total += pow9[l];
        }


        for(int i=0;i<m;i++) {
            int num = digits[i]-'0';
            if (num==0) {
                return total;
            }

            total += (long long)(num-1) * pow9[m-1-i];
        }

        return total + 1;
    }
};
*/