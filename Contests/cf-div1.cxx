#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
#include <bits/stdc++.h>
using namespace std;

int t,n,m,k,a[100005],i,j;

string s;

int main(){
cin>>t;

while(t--){

cin>>n>>m>>k;
for(i=0,j=0;i<m;i++)cin>>a[i];

sort(a,a+m);

if(a[m-1]<=n/k+1 && a[m-1-n%k]<=n/k) cout<<"YES\n";

else cout<<"NO\n";
}

}
*/
void solveC()
{
    int N;
    string s;
    cin >> s;

    int st = 0;
    cout << "1";
    for (int i = 1; i < N; i++)
    {
        if (s[i] != s[i - 1])
        {
            st = i;
        }
        cout << st + 1 << endl;
    }
}
void solve()
{
    int N, M, k;

    cin >> N >> M >> k;
    vector<int> freq(M);
    for (int i = 0; i < M; i++)
    {
        cin >> freq[i];
    }

    vector<int> v(N);
    sort(freq.begin(), freq.end());
    queue<pair<int, int>> q;

    for (int i = 0; i < M; i++)
    {
        q.push({i, freq[i]});
    }

    while (!q.empty())
    {
        auto a = q.front();
        if (a.second < k)
        {
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (--t)
    {
        solve();
    }
    return 0;
}