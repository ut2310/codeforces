using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005
ll process(map<pair<ll, ll>, vector<ll>> &curr)
{
    ll res = 0;
    for(auto j: curr)
    {
        map<ll, ll> track;
        ll size = j.second.size();
        res += (size) * (size - 1)/2;
        for(auto e: j.second)
        {
            track[e]++;
        }
        for(auto e: track)
        {
            res -= (e.second) * (e.second - 1)/2;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        map<pair<ll, ll>, vector<ll>> t1;
        map<pair<ll, ll>, vector<ll>> t2;
        map<pair<ll, ll>, vector<ll>> t3;
        for(int i = 0; i < n - 2; i++)
        {
            if(t1.count(make_pair(a[i], a[i + 1])) == 0)
            {
                vector<ll> temp;
                temp.push_back(a[i + 2]);
                t1[make_pair(a[i], a[i + 1])] = temp;
            }
            else
            {
                t1[make_pair(a[i], a[i + 1])].push_back(a[i + 2]);
            }
            if(t2.count(make_pair(a[i], a[i + 2])) == 0)
            {
                vector<ll> temp;
                temp.push_back(a[i + 1]);
                t2[make_pair(a[i], a[i + 2])] = temp;
            }
            else
            {
                t2[make_pair(a[i], a[i + 2])].push_back(a[i + 1]);
            }
            if(t3.count(make_pair(a[i + 1], a[i + 2])) == 0)
            {
                vector<ll> temp;
                temp.push_back(a[i]);
                t3[make_pair(a[i + 1], a[i + 2])] = temp;
            }
            else
            {
                t3[make_pair(a[i + 1], a[i + 2])].push_back(a[i]);
            }
        }
        ll res = 0;
        res += process(t1);
        res += process(t2);
        res += process(t3);
        cout << res << "\n";
    }
}