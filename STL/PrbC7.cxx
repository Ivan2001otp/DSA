#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

// template <typename T>
using pbds = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    int Q;
    cin >> Q;

    int row[N], col[N];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));

    pbds freeRow, freeCol;

    for (int i = 0; i < N; i++)
    {
        freeRow.insert(i);
        freeCol.insert(i);
    }

    while (Q--)
    {
        int ch;
        cin >> ch;

        if (ch == 1)
        {
            int x, y;
            cin >> x >> y;

            x--, y--;
            row[x]++, col[y]++;

            if (row[x]==1)
            {
                freeRow.erase(x);
            }

            if (col[y]==1)
            {
                freeCol.erase(y);
            }
        }
        else if (ch == 2)
        {
            int x, y;
            cin >> x >> y;

            x--, y--;

            row[x]--;
            col[y]--;
            if (row[x]==0)
            {
                freeRow.insert(x);
            }

            
            if (col[y]==0)
            {
                freeCol.insert(y);
            }
        }
        else
        {
            int x1, y1, x2, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1--, y1--, x2--, y2--;

            int fR = freeRow.order_of_key(x2 + 1) - freeRow.order_of_key(x1);
            int fC = freeCol.order_of_key(y2 + 1) - freeCol.order_of_key(y1);

            if (fR == 0 || fC == 0)
            {
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
