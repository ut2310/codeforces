using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
#define ll long long 
ll t, m, k, a, b;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> m >> k >> a >> b;
        int res = 0;
        if(k * b  + a >= m)
        {
            if(a < m % k)
            {
                res = m % k - a;
            }   
        }
        else
        {
            if(a < m % k)
            {
                res += m % k - a;
                if((m/k) > b)
                {
                    res += (m/k) - b;
                }
            }
            else
            {

                if((m/k) > b)
                {
                    ll current = b * k;
                    current += m % k;
                    a -= m % k;
                    current += (a/k) * k;
                    res += (m - current)/k;
                }
            }
        }
        cout << res << "\n";
    }
}