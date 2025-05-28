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

    vector<pair<string, pair<vector<int>, int>>> v(N);

    for (int i = 0; i < N; i++)
    {
        string name;
        cin >> name;

        int A, M, S, E;
        cin >> A >> M >> S >> E;

        int total = A + M + S + E;
        vector<int> temp(4);

        temp[0] = A, temp[1] = M, temp[2] = S, temp[3] = E;
        v[i] = {name, {temp, total}};
    }

    sort(v.begin(), v.end(), [](const pair<string, pair<vector<int>, int>> &a, const pair<string, pair<vector<int>, int>> &b)
         {
        if (a.second.second==b.second.second) {
            return a.first < b.first;
        }
        return a.second.second > b.second.second; });

    for (auto a : v)
    {
        cout << a.first << " " <<a.second.second<<" "<< a.second.first[0] << " " << a.second.first[1] << " " << a.second.first[2] << " " << a.second.first[3] << endl;
    }
    return 0;
}