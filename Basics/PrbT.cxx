#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s = "http://www.cleartrip.com/signin/service?username=test&pwd=test&profile=developer&role=ELITE&key=manager";

    string temp="";
    int i=0;
    bool found = false;
    for(i=0;i<s.size();i++) {
        if(s[i]=='?'){
            found = true;
            
            break;
        }
    }

    bool inKey = true;
    bool inValue = false;
    if (found){
        temp = s.substr(i+1);

        for(int i=0;i<temp.size() ;i++) {
            if()
        }
    }


    return 0;
}