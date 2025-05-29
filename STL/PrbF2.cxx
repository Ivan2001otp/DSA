#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    deque<int> dq;

    int Q;
    cin >> Q;

    while (Q--)
    {
        string s;
        cin >> s;

        if (s == "push_back")
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }
        else if (s == "push_front")
        {
            int x;
            cin >> x;
            dq.push_front(x);
        }
        else if (s == "pop_front")
        {
            dq.pop_front();
        }
        else if (s == "pop_back")
        {
            dq.pop_back();
        }
        else if (s == "front")
        {
            cout <<"Res : "<< dq.front() << endl;
        }
        else if (s == "back")
        {
            cout <<"Res : "<< dq.back() << endl;
        }
        else
        {
            int x;
            cin >> x;
            cout <<"Res : "<< dq.at(x-1) << endl;
        }
    }
    return 0;
}