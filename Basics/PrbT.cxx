#include <bits/stdc++.h>
using namespace std;

void print(string s, string key)
{
    int pos = s.find(key);
    int pos1 = s.find("=", pos + 1);
    int pos2 = s.find('&', pos1 + 1);

    cout << s.substr(pos, pos1 - pos) << ": " << s.substr(pos1 + 1, pos2 - pos1 - 1) << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s ;
    cin>>s;
    print(s, "username");
    print(s, "pwd");
    print(s, "profile");
    print(s, "role");
    print(s, "key");

    return 0;
}