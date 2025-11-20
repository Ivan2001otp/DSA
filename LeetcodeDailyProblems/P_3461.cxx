#include <bits/stdc++.h>
using namespace std;
#define nl endl;
typedef long long ll;

bool hasSameDigits(string s)
{
    int n = s.size();

    string temp = "";
    int num;
    while (n > 2)
    {

        for (int i = 0; i < s.size() - 1; i++)
        {
            num = ((s[i] - '0') + (s[i + 1] - '0')) % 10;
            temp.push_back(num + '0');
        }
        n = temp.size();
        s = temp;
        temp.clear();
    }

    return s[0] == s[1];
}

int main()
{
    string s = "34789";
    hasSameDigits(s);
    return 0;
}