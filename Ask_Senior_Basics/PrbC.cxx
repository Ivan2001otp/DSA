#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> pos;
    vector<int> neg;
    vector<int> eve;
    vector<int> odd;

    int n;
    cin>>n;

    while (n--){
        int num ;
        cin>>num;

        if (num%2==0) {
            eve.push_back(num);
        } else {
            odd.push_back(num);
        }

        if (num > 0) {
            pos.push_back(num);
        } else if(num < 0) {
            neg.push_back(num);
        }
    }

    cout <<"Even: "<<eve.size()<<endl;
    cout <<"Odd: "<<odd.size()<<endl;
    cout <<"Positive: "<<pos.size()<<endl;
    cout <<"Negative: "<<neg.size()<<endl;
    
    return 0;
}