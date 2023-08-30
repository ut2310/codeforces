using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
long long int t, a, b;
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> a >> b;
        long long int res = 10e15;
        for(int i = 1; i < 100000; i++)
        {
            long long int temp = a/i + b/i + i - 1;
            if(a % i != 0)
            {
                temp += 1;
            }
            if(b % i != 0)
            {
                temp += 1;
            }
            if(temp < res)
            {
                res = temp;
                //cout << res << "\n";
            }
        }
        cout << res << "\n";
    }
}