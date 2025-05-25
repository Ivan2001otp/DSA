#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s;
    cin>>s;

    vector<long long>cost(26);
    for(long long i=0;i<26;i++) {
        cin>>cost[i];
    }
    long long n = s.size();
    vector<long long>lf(n),rf(n);

    long long c = -1;
    for (long long i=0;i<n;i++) {
        if (s[i] != '?') {
            c = cost[s[i]-97];
        } else {
            lf[i]=c;
        }
    }

    for(long long i=n-1;i>=0;i--) {
        if (s[i]!='?') {
            c = cost[s[i]-97];
        } else {
            rf[i]=c;
        }
    }

    for(long long i=0;i<n;i++) {
        if (s[i]=='?') {
            long long l = lf[i];
            long long r = rf[i];
            
            if (l!=-1 && r==-1) {
                r = l;
            } 

            if (r!=-1 && l==-1) {
                l = r;
            }

            if (l==-1 && r == -1) {
                l = 0, r=1e5;
            }

            if (l>r) swap(l, r);

            for (long long j=0;j<26;j++) {
                if (l<=cost[j] && cost[j]<=r){ 
                    s[i] = 97 + j;
                    break;
                }
            }
        }
    }

    long long min_cost = 0;
    for(long long i=1;i<n;i++ ){
        min_cost += abs(cost[s[i]-97]-cost[s[i-1]-97]);
    }

    cout<<min_cost<<endl;
    cout<<s<<endl;

    return 0;
}