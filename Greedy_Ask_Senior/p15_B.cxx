#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://codeforces.com/problemset/problem/1704/C
/*
app1:
#include <bits/stdc++.h>
using namespace std;
long t,tt,n,m,sv[100005];
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    for(cin >> t;t--;cout << n << '\n'){
        cin >> n >> m;
        for(int i=0;i<m;++i)cin >> sv[i];
        sort(sv,sv+m);
        sv[m]=sv[tt=0]+n;
        for(int i=0;i<m;++i)
            if(sv[i+1]-sv[i]>1)
                sv[tt++]=sv[i+1]-sv[i]-1;
        sort(sv,sv+tt);
        for(int i=tt-1,j=1;i>=0&&j<=sv[i];--i,j+=4)
            n-=max(sv[i]-j,(long)1);
    }
}

app2:
const int N=1e5+5;
 
int T,n,m;
int a[N];
int c[N],cnt;
 
signed main(){
	cin>>T;
	while(T--){
		cin>>n>>m;
		int ans=0;
		for(int i=1;i<=m;++i) cin>>a[i];
        sort(a+1,a+m+1);
		for(int i=1;i<m;++i) c[i]=a[i+1]-a[i]-1;
		c[m]=a[1]-1+n-a[m];
		sort(c+1,c+m+1);
		for(int i=m;i;--i){
            if(c[i]-(m-i)*4==1) ++ans;
			else ans+=max(0,c[i]-(m-i)*2-(m-i)*2-1);
		}
		cout<<n-ans<<endl;
	}
}

app3:
#include<bits/stdc++.h>
using namespace std;
int a[200000],b[200000];
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,sum1=0;
		cin>>m>>n;
		cin>>a[0];
		for(int i=1;i<n;i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(int i=1;i<n;i++){
			b[i]=a[i]-a[i-1]-1;
		}
		b[0]=m-a[n-1]+a[0]-1;
		sort(b,b+n);
		int sum=0;
		int z=0;
		for(int i=n-1;i>=0;i--){
			if(b[i]>z){
				if(b[i]-z==1)sum+=1;
			else sum+=(b[i]-z-1);
			
			}
			else break;
			z+=4;
		}
		cout<<m-sum<<endl;
	}
} 
*/
void f()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(m);

    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> gaps;
    for (int i = 0; i < m - 1; i++)
    {
        gaps.push_back(a[i + 1] - a[i]);
    }

    gaps.push_back(n - a.back() - 1 + a[0]); // very important to add tail end houses.

    // start picking from max no.of houses
    sort(gaps.rbegin(), gaps.rend()); // sort desc
    int days = 0, safecount = 0;

    for (int i = 0; i < gaps.size(); i++)
    {
        int currgap = gaps[i];
        int lost = 2 * days;
        currgap = currgap - lost;
        if (currgap <= 0)
            break;

        safecount += (currgap - 1);
        if (currgap == 1)
        {
            safecount++;
        }
        days += 2;
    }

    cout << "safe : " << safecount << endl;
    cout << "infected : " << n - safecount << endl;
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