using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n;cin >> n;
        string s; cin >> s;
        set<ll> visited;
        vector<char> store;
        map<char, char> mp;
        for(int i = 0; i < n; i++)
        {
            if(visited.count(s[i]) == 0)
            {
                store.push_back(s[i]);
                visited.insert(s[i]);
            }
        }
        sort(store.begin(), store.end());
        for(int i = 0; i < store.size(); i++)
        {
            ll size = store.size();
            mp[store[i]] = store[size - 1 - i];
        }
        string res = "";
        for(int i = 0; i < n; i++)
        {
            res.push_back(mp[s[i]]);
        }
        cout << res << "\n";
    }
}