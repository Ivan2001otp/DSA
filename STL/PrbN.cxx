#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<int, int> createNewPair(const pair<int, int> &a, const pair<int, int> &b)
{

    int leftEle = min(a.first, b.first);
    int rightEle = max(a.second, b.second);
    return {leftEle, rightEle};
}

bool isIntersecting(const pair<int, int> a, const pair<int, int> b)
{
    int l1, r1, l2, r2;
    l1 = a.first, r1 = a.second;

    l2 = b.first, r2 = b.second;

    if (l1 > l2)
    {
        if (r2 < l1)
        {
            return false;
        }
        else if (r2 >= l1 && r2 <= r1)
        {
            return true;
        }
        else if (r2 > r1)
            return true;
    }
    else
    {
        if (r2 <= r1 || r2 > r1)
            return true;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;

        pq.push({a, b});
    }



    while (!pq.empty())
    {
        pair<int, int> e2;
        pair<int, int> e1 = pq.top();
        pq.pop();

        if (pq.empty())
        {
            cout << e1.first << " " << e1.second << endl;
            break;
        }

        if (e1.second >= pq.top().first)
        {
            e2 = pq.top();
            pq.pop();

            bool result = isIntersecting(e1, e2);
            if (result)
            {
                pair<int, int> newE = createNewPair(e1, e2);
                pq.push(newE);
            }
        }
        else
        {
            cout << e1.first << " " << e1.second << endl;
        }
    }
    return 0;
}