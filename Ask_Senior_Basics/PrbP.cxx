// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

bool isLetter(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int main()
{
    string s;
    getline(cin, s);

    int wordCount = 0;
    bool inWord = false;

    for (char c : s)
    {
        if (isLetter(c))
        {
            if (!inWord)
            {
                inWord = true;
                wordCount++;
            }
        }
        else
        {
            inWord = false;
        }
    }

    cout << wordCount << '\n';
    return 0;
}