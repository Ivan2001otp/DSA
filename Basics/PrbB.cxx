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

    int x;
    cin >> x;

    int flag = -1;

    for (int i = 0; i < N; i++)
    {
        if (x == v[i])
        {
            flag = i;
            break;
        }
    }

    cout << flag << endl;

    return 0;
}