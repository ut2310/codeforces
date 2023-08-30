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
long long int t, n, m;
int smallestDivisor(int n)
{
    // if divisible by 2
    if (n % 2 == 0)
        return 2;
 
    // iterate from 3 to sqrt(n)
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0)
            return i;
    }
 
    return n;
}
int main()
{
    cin >> t;
    while(t-->0)
    {
        cin >> n >> m; //n programmer, m algorithms
        if(n <= m)
        {
            if(n == 1)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            if(m == 1)
            {
                cout << "YES\n";
            }
            else
            {
                long long int x = smallestDivisor(n);
                if(x <= m)
                {
                    cout << "NO\n";
                }
                else
                {
                    cout << "YES\n";
                }
            }
            //Can n be distributed into a * b such that at least one of a and b is between 1 and m?

        }
    }
}