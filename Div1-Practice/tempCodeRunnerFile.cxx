
void solve2()
{
    string S, T;
    cin >> S >> T;

    unordered_map<char, int> mp;
    for (int i = 0; i < T.size(); i++)
    {
        mp[i]++;
    }

    for (int i = 1; i < S.size(); i++)
    {
        if (S[i] - 'a' < 0)
        {
            if (!mp[S[i - 1]])
            {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
    return;
}
int main()
{
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve2();
    }
    return 0;
}