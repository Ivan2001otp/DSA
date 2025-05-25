// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string key = "PgEfTYaWGHjDAmxQqFLRpCJBownyUKZXkbvzIdshurMilNSVOtec#@_!=.+-*/";
    string original = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    int q;
    cin >> q;

    string s;
    cin >> s;

    if (q == 1)
    {
        // encrypt
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            for (int j = 0; j < original.size(); j++)
            {
                if (original[j] == ch)
                {
                    cout << key[j];
                    break;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < s.size(); i++)
        {
            char ch = s[i];
            for (int j = 0; j < key.size(); j++)
            {
                if (key[j] == ch)
                {
                    cout << original[j];
                    break;
                }
            }
        }
    }

    return 0;
}