#include <bits/stdc++.h>
using namespace std;
#define nl endl;
 int countOperations(int num1, int num2) {

        int steps = 0;

        if ((num1==0 && num2==0) || (num1==0) || (num2==0)){
            return steps;
        }

        if (num1 == num2 ) {
            steps++;
            num1 = 0;
            num2 = 0;
        }

        while (num1 > 0 || num2 > 0) {

            if (num1 > num2) {
                num1 = num1 - num2;
            } else if (num1 < num2) {
                num2 = num2 - num1;
            } else {
                num2 = 0;
                num1 = 0;
            }
            ++steps;
        }

        return steps;
    }

int main()
{
    cout << countOperations(2, 2) << endl;
    return 0;
}