#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// subsequence addition - g2
void f()
{
    int n, m;
    cin >> n >> m;

    vector<int> infected(m);
    for (int i = 0; i < m; i++)
    {
        cin >> infected[i];
    }

    sort(infected.begin(), infected.end());
    vector<int> gaps;

    for (int i = 1; i < m; i++)
    {
        gaps.push_back(infected[i] - infected[i - 1]);
    }

    gaps.push_back(n - infected.back() - 1 + infected[0]);
    sort(gaps.rbegin(), gaps.rend());

    int days = 0, saved = 0;

    for (int i = 0; i < gaps.size(); i++)
    {

        int currgap = gaps[i];
        int lost = 2 * days;
        currgap -= lost;

        if (currgap <= 0)
        {
            break;
        }
        saved += (currgap - 1);
        if (currgap == 1)
        {
            saved++;
        }
        days += 2;
    }

    cout << "saved : " << saved << endl;
    cout << "infected : " << n - saved << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;

    // cin >> T;
    while (T--)
    {
        f();
    }
    return 0;
}