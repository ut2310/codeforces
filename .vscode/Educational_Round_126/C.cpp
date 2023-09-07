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
ll t, n;
bool check(ll days, ll M, vector<ll> a)
{
    ll cnt1 = 0;
    ll cnt2 = 0;
    for(int i = 0; i < n; i++)
    {
        if((M - a[i]) % 2 == 1)
        {
            cnt1 += 1;
        }
        cnt2 += (M - a[i])/2;
    }
    ll check2 = days/2;
    ll check1 = days/2;
    if(days % 2 == 1)
    {
        check1++;
    }
    if(cnt2 >= check2)
    {
        cnt1 += 2 * (cnt2 - check2);
    }
    if(check1 >= cnt1)
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
        vector<ll> input;
        ll M = 0;
        for(int i = 0; i < n; i++)
        {
            ll temp; cin >> temp;
            input.push_back(temp);
            M = max(M, temp);
        }
        ll low = 0;
        ll high = 1e18;
        while(low < high)
        {
            ll mid = (low + high)/2;
            if(check(mid, M, input) || check(mid, M + 1, input))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << low << "\n";
    }
}