#include <bits/stdc++.h>
using namespace std;


void solve(int &c, multiset<pair<int, int>> &st1, multiset<int> &st2, unordered_map<int, int> &mp)
{

    int ch;
    cin >> ch;

    if (ch == 1)
    {
        c++;
        int amt;
        cin >> amt;
        st1.insert({-amt, c});
        st2.insert(c);
        mp[c] = amt;
    }
    else if (ch == 2)
    {

        int cust_no = *st2.begin();
        cout << cust_no << " ";
        st2.erase(cust_no);

        int amt = mp[cust_no];
        st1.erase({-amt, cust_no});
        }
    else
    {
        pair<int, int> p = *st1.begin();
        st1.erase(p);

        int cust_no = p.second;
        st2.erase(cust_no);
        cout << cust_no << " ";
    }
}

int main()
{
    int q;
    cin >> q;
    multiset<pair<int, int>> st1;
    multiset<int> st2;

    unordered_map<int, int> m_map;
    int c = 0;

    while (q--)
    {
        solve(c, st1, st2, m_map);
    }
}
