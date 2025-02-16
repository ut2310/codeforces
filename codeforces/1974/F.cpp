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
        ll a, b, n, m; cin >> a >> b >> n >> m;
        map<ll, set<ll>> xy;
        map<ll, set<ll>> yx;
        vector<pair<ll, ll>> ax;
        vector<pair<ll, ll>> ay;
        map<pair<ll, ll>, ll> mp;
        vector<ll> visited(n);
        for(int i = 0; i < n; i++)
        {
            ll x, y; cin >> x >> y;
            ax.push_back(make_pair(x, y));
            ay.push_back(make_pair(y, x));
            mp[make_pair(x, y)] = i;
        }
        sort(ax.begin(), ax.end());
        sort(ay.begin(), ay.end());
        ll px1 = 0;
        ll px2 = n - 1;
        ll py1 = 0;
        ll py2 = n - 1;
        ll bx1 = 1;
        ll bx2 = a;
        ll by1 = 1;
        ll by2 = b;
        ll res1 = 0;
        ll res2 = 0;
        for(int i = 0; i < m; i++)
        {
            ll cut; char c;
            cin >> c >> cut;
            if(c == 'U')
            {
                while(px1 >= 0 && px1 < n && ax[px1].first < bx1 + cut)
                {
                    if(visited[mp[ax[px1]]] == 0)
                    {
                        visited[mp[ax[px1]]] = 1;
                        if(i % 2 == 0) res1++;
                        if(i % 2 == 1) res2++;
                    }
                    px1++;
                }    
                bx1 += cut;            
            }
            if(c == 'D')
            {
                while(px2 >= 0 && px2 < n && ax[px2].first > bx2 - cut)
                {
                    if(visited[mp[ax[px2]]] == 0)
                    {
                        visited[mp[ax[px2]]] = 1;
                        if(i % 2 == 0) res1++;
                        if(i % 2 == 1) res2++;
                    }
                    px2--;
                }    
                bx2 -= cut; 
            }
            if(c == 'L')
            {
                
                while(py1 >= 0 && py1 < n && ay[py1].first < by1 + cut)
                {
                    if(visited[mp[make_pair(ay[py1].second, ay[py1].first)]] == 0)
                    {
                        visited[mp[make_pair(ay[py1].second, ay[py1].first)]] = 1;
                        if(i % 2 == 0) res1++;
                        if(i % 2 == 1) res2++;
                    }
                    py1++;
                }    
                
                by1 += cut;
                
            }
            if(c == 'R')
            {
                while(py2 >= 0 && py2 < n && ay[py2].first > by2 - cut)
                {
                    if(visited[mp[make_pair(ay[py2].second, ay[py2].first)]] == 0)
                    {
                        visited[mp[make_pair(ay[py2].second, ay[py2].first)]] = 1;
                        if(i % 2 == 0) res1++;
                        if(i % 2 == 1) res2++;
                    }
                    py2--;
                }    
                by2 -= cut; 
            }
        }


        cout << res1 << " " << res2 << "\n";
    }
}