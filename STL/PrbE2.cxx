#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int Q;
    cin >> Q;

    queue<int> q;

    while (Q--)
    {
        string s;
        cin >> s;

        if (s == "push")
        {
            int num;
            cin >> num;
            q.push(num);
        }
        else if (s == "pop")
        {
            q.pop();
        }
        else if (s == "front")
        {
            cout << q.front() << endl;
        }
        else
        {
            cout << q.back() << endl;
        }
    }

    return 0;
}