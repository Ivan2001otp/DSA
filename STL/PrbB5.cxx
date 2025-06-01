#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isTwoGram(string chars)
{
    int diff = abs(chars[1] - chars[0]);
    return (diff == 0 || diff == 25);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    string s;
    cin >> s;

    map<string, int> mp;
    int maxi = INT_MIN;
    string res = "";

    for (int i = 1; i < N; i++)
    {
        string temp = s.substr(i - 1, 2);
        mp[temp]++;
        
        if (maxi < mp[temp]) {
            maxi = mp[temp];
            res = temp;
        }
    }

    cout << res<<endl;
    return 0;
}