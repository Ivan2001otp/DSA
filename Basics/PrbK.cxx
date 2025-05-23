#include<bits/stdc++.h>
using namespace std;

int main() {
    int A,B,C;

    cin>>A>>B>>C;

    int a = min(A, min(C, B));
    int b = max(A, max(C, B));
    cout<<a<<endl;
    cout<<b<<endl;

    return 0;
}