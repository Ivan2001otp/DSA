#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    unordered_map<string, int> db;

    while (N--)
    {
        string s;
        cin >> s;

        if (!db[s])
        {
            db[s]++;
            cout << "OK" << endl;
        }
        else
        {
            string username = s + std::to_string(db[s]);
            db[s]++;
            cout << username << endl;
        }
    }

    return 0;
}