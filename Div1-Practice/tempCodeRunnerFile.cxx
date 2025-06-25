#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve()
{
    int H, M;
    cin >> H >> M;

    string hh = std::to_string(H);
    string mm = std::to_string(M);

    string temp_hh = hh;
    string temp_mm = mm;

    if (temp_hh.size() == 1)
    {
        temp_hh = "0" + temp_hh;
    }

    if (temp_mm.size() == 1)
    {
        temp_mm = "0" + temp_mm;
    }

    swap(temp_hh[1], temp_mm[0]);
    // cout << temp_hh << " " << temp_mm << endl;
    int num_hh = std::stoi(temp_hh), num_mm = std::stoi(temp_mm);

    if ((num_mm >= 0 && num_mm <= 59) || (num_hh >= 0 && num_hh <= 23))
    {
        cout << H << " " << M << endl;
    }
    else
    {
        H = (H + 1 >= 24) ? 0 : H + 1;
        cout << H << " " << 0 << endl;
    }
}

int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}