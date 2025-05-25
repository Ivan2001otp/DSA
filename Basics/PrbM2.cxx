// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;

    string l = "hello";
    int i = 0, j = 0;

    int ns = s.size();
    int nl = l.size();

    while (i < ns && j < nl)
    {

        if (s[i] == l[j])
        {

            j++;
        }
        i++;
    }

    bool result = (j == nl);
    if (result)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}