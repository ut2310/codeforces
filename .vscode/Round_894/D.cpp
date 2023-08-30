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
#define MAXN 200005
#define ll long long
ll t, n;
bool check(ll x, ll number)
{
    if(x * (x - 1) <= number)
    {
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n;
        ll low = 0; 
        ll high = 2e9;
        while(low < high)
        {
            ll mid = (low + high + 1)/2;
            ll number = 2 * n;
            if(check(mid, number))
            {
                low = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        ll final_calc = low * (low - 1)/2;
        ll res = low + (n - final_calc);
        cout << res << "\n";
    }
}