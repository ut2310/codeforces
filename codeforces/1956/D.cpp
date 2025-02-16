#include <bits/stdc++.h>
#define ll long long
using namespace std;
pair<ll, vector<ll>> dp[19][19];
vector<pair<ll, ll>> dp2[19][19];
vector<pair<ll, ll>> final_output;
void process(ll l, ll r, vector<ll> &a, vector<ll> &ps)
{
    if(ps[r] - ps[l - 1] < (r - l + 1) * (r - l + 1))
    {
        for(int i = l; i <= r; i++)
        {
            if(a[i] != 0) final_output.push_back(make_pair(i, i));
        }
        final_output.insert(final_output.end(), dp2[l][r].begin(), dp2[l][r].end());
    }
}   
int main()
{
    ll n; cin >> n;
    vector<ll> a(n + 1);
    vector<ll> ps(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        ps[i] = ps[i - 1] + a[i];
    }
    for(int i = 1; i <= n; i++)
    {
        vector<ll> temp;
        dp[i][i] = make_pair(max(a[i], 1LL), temp);
    }
    for(ll i = 2; i <= n; i++)
    {
        for(ll j = 1; j <= n - i + 1; j++)
        {
            //range is j to j + i - 1
            ll res = max(ps[j + i - 1] - ps[j - 1], i * i);
            vector<ll> temp;
            for(ll k = j; k < j + i - 1; k++)
            {
                ll curr = dp[j][k].first + dp[k + 1][j + i - 1].first;
                if(curr >= res)
                {
                    temp.clear();
                    temp.insert(temp.end(), dp[j][k].second.begin(), dp[j][k].second.end());
                    temp.push_back(k);
                    temp.insert(temp.end(), dp[k + 1][j + i - 1].second.begin(), dp[k + 1][j + i - 1].second.end());
                    res = curr;
                }
            }
            dp[j][j + i - 1] = make_pair(res, temp);
        }
    }
    for(int i = 1; i <= n; i++)
    {
        dp2[i][i].push_back(make_pair(i, i));
    }
    for(int l = 2; l <= n; l++)
    {
        for(int s = 1; s <= n - l + 1; s++)
        {
            //range is s to s + l - 1
            vector<pair<ll, ll>> store;
            for(int j = s; j <= s + l - 2; j++)
            {
                if(j != s) store.push_back(make_pair(j, s + l - 2));
                store.insert(store.end(), dp2[j][s + l - 2].begin(), dp2[j][s + l - 2].end());
            }
            store.push_back(make_pair(s, s + l - 1));
            dp2[s][s + l - 1] = store;
        }
    }
    
    cout << dp[1][n].first << " ";
    vector<ll> splits = dp[1][n].second;
    splits.push_back(n);
    for(int i = 0; i < splits.size(); i++)
    {
        if(i == 0)
        {
            process(1, splits[i], a, ps);
        }
        else
        {
            process(splits[i - 1] + 1, splits[i], a, ps);
        }
    }   
    cout << final_output.size() << "\n";
    for(auto i: final_output)
    {
        cout << i.first << " " << i.second << "\n";
    }
    // for(auto i: dp[1][n].second)
    // {
    //     cout << i << " ";
    // }
    // cout << "\n";
}