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
ll t, n, k;
ll y, j, x;
string convert(ll a, ll k)
{
    vector<ll> output(k);
    int track = k - 1;
    while(a > 0)
    {
        output[track] = a % 2;
        track--;
        a/=2;
    }
    while(track >= 0)
    {
        output[track] = 0;
        track--;
    }
    string res = "";
    for(int i = 0; i < k; i++)
    {
        res.append(to_string(output[i]));
    }
    return res;
}
pair<ll, ll> compare(ll a, ll b, ll k)
{
    string s1 = convert(a, k);
    string s2 = convert(b, k);
    ll res = 0;
    ll res2 = 0;
    for(int i = 0; i < k; i++)
    {
        if(s1.at(i) == s2.at(i))
        {
            if(s1.at(i) == '0')
            {
                res2 += pow(2, k - 1 - i);
            }
            res += pow(2, k - 1 - i);
        }
    }
    return make_pair(res, res2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t-->0)
    {
        cin >> n >> k;
        vector<pair<ll, ll>> input;
        for(int i = 0; i < n; i++)
        {
            ll temp; cin >> temp;
            input.push_back(make_pair(temp, i + 1));
        }
        sort(input.begin(), input.end());
        ll res = -1;
        for(ll i = 0; i < n - 1; i++)
        {
            pair<ll, ll> value = compare(input[i].first, input[i + 1].first, k);
            if(value.first > res)
            {
                res = value.first;
                y = input[i].second;
                j = input[i + 1].second;
                x =  value.second;
            }
        }
        cout << y << " " << j << " " << x << "\n"; 
    }
}