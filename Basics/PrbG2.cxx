#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        int ele;
        cin >> ele;
        v.push_back(ele);
    }

    bool flag = true;

    for (int i = 0; i < N / 2; i++)
    {
        if (v[i] != v[N - i - 1])
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}