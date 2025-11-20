#include <bits/stdc++.h>
using namespace std;
#define nl endl;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int n = s.length();
        vector<int> cumOneCount(n, 0);

        cumOneCount[0] = (s[0] == '1' ? 1 : 0);

        for (int i = 1; i < n; i++)
        {
            cumOneCount[i] = cumOneCount[i - 1] + ((s[i] == '1') ? 1 : 0);
        }

        int result = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                int oneC = cumOneCount[j] - (i - 1 >= 0 ? cumOneCount[i - 1] : 0);
                int zeroC = (j - i + 1) - oneC;

                if ((zeroC * zeroC) > oneC)
                {
                    // waste indices
                    int w = (zeroC * zeroC) - oneC;

                    j += (w - 1);
                }
                else if ((zeroC * zeroC) == oneC)
                {
                    result += 1;
                }
                else
                {
                    result += 1;
                    int k = sqrt(oneC) - zeroC;
                    int next = j + k;
                    if (next >= n)
                    {
                        result += (n - j - 1);
                        break;
                    }
                    else
                    {
                        result += k;
                    }
                    j = next;
                }
            }
        }

        return result;
    }
};