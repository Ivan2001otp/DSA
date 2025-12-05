#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void f()
{
    ll n, coins;
    cin >> n >> coins;

    vector<ll> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = arr[i] + i+1;
    }

    
    sort(arr.begin(), arr.end());

    ll count = 0;

    for (ll i = 0; i < n; i++)
    {
        
        if (arr[i]<=coins){
            coins-=arr[i];
            ++count;
        } else {
            break;
        }
    }
    // cout << "ans is " << count << endl;
    cout<<count<<endl;
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