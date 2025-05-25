#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int n;

        cin >> n;

        vector<int> v(n);

        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        for (int i = 0; i < n; i++)
        {
            
            for (int j = i; j < n; j++)
            {
                int max_val = INT_MIN;
                for(int k=i;k<=j;k++) {
                    max_val = max(max_val, v[k]);
                }
                cout<<max_val<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}