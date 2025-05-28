#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Q;
    cin >> Q;

    priority_queue<int> pq;

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
        else if (s == "top")
        {
            cout << pq.top() << endl;
        }
        else
        {
            pq.pop();
        }
    }
    return 0;
}