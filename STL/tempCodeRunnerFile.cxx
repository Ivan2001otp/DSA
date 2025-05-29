#include <bits/stdc++.h>
using namespace std;

int flipBit(int n, int pos)
{
    return n ^ (1 << pos);
}

int setBitToOne(int n, int pos)
{
    return n | (1 << pos);
}

int setBitToZero(int n, int pos)
{
    return n & ~(1 << pos);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    int Q;
    cin >> Q >> N;

    while (Q--)
    {
        int num;
        cin >> num;

        if (num == 1)
        {
            int x;
            cin >> x;
            int bit = (N >> x) & 1;
            cout << bit << endl;
        }
        else if (num == 2)
        {
            int x;
            cin >> x;
            int flipped = setBitToOne(N, x);
            cout << flipped << endl;
            N = flipped;
        }
        else if (num == 3)
        {
            int x;
            cin >> x;
            int bitZ = setBitToZero(N, x);
            cout << bitZ << endl;
            N = bitZ;
        }
        else
        {
            int x;
            cin >> x;

            int toggleBit = flipBit(N, x);
            cout << toggleBit << endl;
            N = toggleBit;
        }
    }

    return 0;
}