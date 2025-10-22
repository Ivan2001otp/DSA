#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long int N;
    cin >> N;

    string X;
    cin >> X;
    int sum = 0;

    for(int i=0;i<X.size();i++) {
        int num = X[i]-'0';
        sum += num;
    }

    cout << sum << endl;

    return 0;
}