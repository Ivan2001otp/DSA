#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Q;
    cin >> Q;

    priority_queue<int, vector<int>, greater<int>> pq;

    while (Q--)
    {
        string s;
        cin >> s;

        if (s == "push")
        {
            int num;
            cin >> num;
            pq.push(num);
        }
        else if (s == "pop")
        {
            pq.pop();
        }
        else
        {
            cout << pq.top() << endl;
        }
    }

    return 0;
}