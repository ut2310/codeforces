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
        if(b % 2== 1)
        {
            if(a < b && a % 2 == 1)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
        else
        {
            if(a % 2 == 1)
            {
                cout << "NO\n";
            }
            else
            {
                cout << "YES\n";
            }
        }
    }
}