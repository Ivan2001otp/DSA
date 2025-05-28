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

    string s;

    cin >> s;

    while (Q--)
    {
        int type;
        string choice;
        cin >> choice;
        cin >> type;

        if (choice == "next_permutation")
        {
            for (int i = 0; i < type; i++)
            {
                std::next_permutation(s.begin(), s.end());
            }
        }
        else
        {
            for (int i = 0; i < type; i++)
            {
                std::prev_permutation(s.begin(), s.end());
            }
        }

        cout << s << endl;
    }

    return 0;
}