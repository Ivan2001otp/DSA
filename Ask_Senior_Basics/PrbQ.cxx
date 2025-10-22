#include <bits/stdc++.h>
using namespace std;

bool isNegative(float num)
{
    return num < 0;
}

bool isPositive(float num)
{
    return num > 0;
}

int main()
{
    float x, y;
    cin >> x >> y;

    if (x == 0 && y == 0)
    {
        cout << "Origem" << endl;
    }
    else if (x == 0 && y != 0)
    {
        cout << "Eixo Y" << endl;
    }
    else if (x != 0 && y == 0)
    {
        cout << "Eixo X" << endl;
    }
    else
    {

        if (isPositive(x) && isPositive(y))
        {
            cout << "Q1" << endl;
        }
        else if (isPositive(x) && isNegative(y))
        {
            cout << "Q4" << endl;
        }
        else if (isNegative(x) && isNegative(y))
        {
            cout << "Q3" << endl;
        }
        else if (isNegative(x) && isPositive(y))
        {
            cout << "Q2" << endl;
        }
    }

    return 0;
}