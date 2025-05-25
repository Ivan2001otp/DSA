// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    string t = "";
    int N;

    cin >> N;
    cin >> s;

    int count = 1;

    int i = 1;
    while (i < N)
    {
        if (s[i] != s[i - 1])
            count++;
        
        i++;
    }
    cout << count << endl;

    return 0;
}