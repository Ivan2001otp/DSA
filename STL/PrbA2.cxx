#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    string S;
    cin >> S;

    while (Q--)
    {
        string query;
        cin >> query;

        if (query == "pop_back")
        {
            S.pop_back();
        }
        else if (query == "front")
        {
            cout << S.front() << endl;
        }
        else if (query == "back")
        {
            cout << S.back() << endl;
        }
        else if (query == "sort")
        {
            int l, r;
            cin >> l >> r;

            if (l > r)
                swap(l, r);
            l--;

            sort(S.begin() + l, S.begin() + r);
        }
        else if (query == "reverse")
        {
            int l, r;
            cin >> l >> r;

            if (l > r)
                swap(l, r);
            l--;

            reverse(S.begin() + l, S.begin() + r);
        }
        else if (query == "print")
        {
            int pos;
            cin >> pos;
            cout << S[pos - 1] << endl;
        }
        else if (query == "substr")
        {
            int l, r;
            cin >> l >> r;
            if (l > r)
                swap(l, r);
            l--;

            string t = S.substr(l, r - l);
            cout << t << endl;
        }
        else
        {
            char ch;
            cin >> ch;
            S.push_back(ch);
        }
    }
    return 0;
}