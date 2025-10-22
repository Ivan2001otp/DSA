#include <bits/stdc++.h>

using namespace std;

int main()
{
    double pi = 3.141592653;

    double radius;
    cin >> radius;

    double result = pi * radius * radius;

    cout << fixed << setprecision(9);
    cout << result << endl;
}