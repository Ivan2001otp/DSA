#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://codeforces.com/problemset/problem/1788/B
void f()
{
    int n;
    cin >> n;

    vector<int> sx;
    vector<int> sy;
    vector<int> number_arr;

    int size = n;
    while (size)
    {
        number_arr.push_back(size % 10);
        size = size / 10;
    }

    reverse(number_arr.begin(), number_arr.end());

    int cnt = 0;
    for (int i = 0; i < number_arr.size(); i++)
    {

        if ((number_arr[i] % 2 == 1) && (cnt % 2 == 1))
        {
            sy.push_back(number_arr[i] / 2);
            sx.push_back((number_arr[i] / 2) + 1);
            cnt++;
        }
        else if ((number_arr[i] % 2 == 1) && (cnt % 2 == 0))
        {
            sx.push_back(number_arr[i] / 2);
            sy.push_back((number_arr[i] / 2) + 1);
            cnt++;
        }
        else
        {
            sx.push_back(number_arr[i] / 2);
            sy.push_back(number_arr[i] / 2);
        }
    }

    int numx = 0, numy = 0;
    for (int i = 0; i < sx.size(); i++)
    {
        numx = (numx * 10) + sx[i];
    }

    for (int i = 0; i < sy.size(); i++)
    {
        numy = (numy * 10) + sy[i];
    }

    cout << numx << " " << numy << endl;

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
    {
        f();
    }
    return 0;
}