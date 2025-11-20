#include <bits/stdc++.h>
using namespace std;
#define nl endl;

int numberOfBeams(vector<string> &bank)
{

    if (bank.empty())
        return 0;

    int row = bank.size();
    int col = bank[0].size();

    vector<int> arr;

    for (int i = 0; i < row; i++)
    {
        int count = 0;
        for (int j = 0; j < col; j++)
        {

            if (bank[i][j] - '0' == 1)
            {
                ++count;
            }
        }

        if (count > 0)
        {
            arr.push_back(count);
        }
    }

    int res = 0;
    for (int i = 0; i < (int)arr.size() - 1; i++) {
        res += arr[i] * arr[i + 1];
    }
    
    return res;
}

int main()
{
    vector<string> v = {"010001", "010101", "101010"};

    cout << "Result is " << numberOfBeams(v) << endl;
    return 0;
}