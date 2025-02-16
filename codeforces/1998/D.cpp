using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, m; cin >> n >> m;
        vector<ll> dp(n + 1);
        map<ll, vector<ll>> track;
        vector<pair<ll, ll>> portals;
        for(int i = 0; i < m; i++)
        {
            ll a, b; cin >> a >> b;
            track[b].push_back(a);
            portals.push_back(make_pair(a, b));
        }
        dp[1] = 0;
        for(int i = 2; i <= n; i++)
        {
            dp[i] = dp[i - 1] + 1;
            for(auto j: track[i])
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
            //cerr << dp[i] << " ";
        }
        //cerr << "\n";
        vector<pair<ll, ll>> intervals2;
        for(int i = 0; i < portals.size(); i++)
        {
            ll len = dp[portals[i].first] + 1;
            ll start = portals[i].second - len - 1;
            pair<ll, ll> interval = make_pair(portals[i].first + 1, start);
            if(start > portals[i].first)
            {
                intervals2.push_back(interval);
            }
        }
        vector<pair<ll, ll>> res;   
        sort(intervals2.begin(), intervals2.end());
        int start = -1;
        int end = -1;
        if(intervals2.size() > 0)
        {
            start = intervals2[0].first;
            end = intervals2[0].second;
        }
       
        for(int i = 1; i < intervals2.size(); i++)
        {
            if(intervals2[i].first >= start && intervals2[i].second <= end)
            {
                continue;
            }
            else if(intervals2[i].first >= start && intervals2[i].first <= end)
            {
                end = intervals2[i].second;
            }
            else
            {
                res.push_back(make_pair(start, end));
                start = intervals2[i].first;
                end = intervals2[i].second;
            }
        }
        res.push_back(make_pair(start, end));
        vector<ll> visited(n + 1);
        for(int i = 0; i < res.size(); i++)
        {
            for(int j = res[i].first; j <= res[i].second; j++)
            {
                if(j >= 0) visited[j] = 1;
            }
        }
        string final_res = "";
        for(int i = 1; i <= n - 1; i++)
        {
            if(visited[i] == 1) final_res.push_back('0');
            else final_res.push_back('1');
        }
        cout << final_res << "\n";

    }
}