#include <bits/stdc++.h>
using namespace std;
#define nl endl;
typedef long long ll;

int smallestNumber(int n)
{

    string s = "";

    while (n > 0)
    {
        int rem = n % 2;
        n = n / 2;
        s += std::to_string(rem);
    }

    reverse(s.begin(), s.end());
    cout << "before : " << s << endl;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            s[i] = '1';
        }
    }

    int i = s.size() - 1;
    cout << "after : " << s << endl;

    int p = 0;
    int num = 0;

    while (i >= 0)
    {
        num = num + (s[i] - '0') * (pow(2, p));
        i--;
        p++;
    }
    return num;
}

int main()
{
    cout << smallestNumber(10) << endl;
    return 0;
}