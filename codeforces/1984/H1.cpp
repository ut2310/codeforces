using namespace std;
#include <bits/stdc++.h>
#define ll long long
ll n, m;
bool check(ll cx, ll cy)
{
    if(cx >=0 && cx < n && cy >= 0 && cy < m)
    {
        return true;
        
    }
    return false;
}
void dfs(ll cx, ll cy, ll comp, vector<vector<ll>> &a, vector<vector<ll>> &find)
{
    if(cx >=0 && cx < n && cy >= 0 && cy < m && a[cx][cy] == '#' && find[cx][cy] == 0)
    {
        find[cx][cy] = comp;
        dfs(cx + 1, cy, comp, a, find);
        dfs(cx - 1, cy, comp, a, find);
        dfs(cx, cy + 1, comp, a, find);
        dfs(cx, cy - 1, comp, a, find);
    }
    return;
}
int main()
{
    ll t; cin >> t;
    while(t-->0)
    {
        cin >> n >> m;
        vector<vector<ll>> store(n, vector<ll> (m));
        for(int i = 0; i < n; i++)
        {
            string s; cin >> s;
            for(int j = 0; j < m; j++)
            {
                store[i][j] = s[j];
            }
        }
        ll comp = 1;
        vector<vector<ll>> find(n, vector<ll> (m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(store[i][j] == '#' && find[i][j] == 0)
                {
                    dfs(i, j, comp, store, find);
                    comp++;
                }
            }
        }
        map<ll, ll> size;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                //cout << find[i][j] << " ";
                if(find[i][j]!=0) size[find[i][j]]++; 
            }
            //cout << "\n";
        }

        ll res = max(n, m);
        ll curr = 0;
        if(size.size() > 0) curr = (*size.rbegin()).second;
        res = max(res, curr);
        for(int i = 0; i < n; i++)
        {
            ll addOn = 0;
            set<ll> track;
            for(int j = 0; j < m; j++)
            {
                if(store[i][j] != '#')
                {
                    addOn++;
                }
                if(check(i - 1, j)) track.insert(find[i - 1][j]);
                if(check(i + 1, j)) track.insert(find[i + 1][j]);
                if(check(i, j - 1)) track.insert(find[i][j - 1]);
                if(check(i, j + 1)) track.insert(find[i][j + 1]);
            }   
            for(auto j: track)
            {
                if(j!=0)addOn += size[j];
            }

            res = max(res, addOn);
        }
        for(int j = 0; j < m; j++)
        {
            ll addOn = 0;
            set<ll> track;
            for(int i = 0; i < n; i++)
            {
                if(store[i][j] != '#')
                {
                    addOn++;
                }
                if(check(i - 1, j)) track.insert(find[i - 1][j]);
                if(check(i + 1, j)) track.insert(find[i + 1][j]);
                if(check(i, j - 1)) track.insert(find[i][j - 1]);
                if(check(i, j + 1)) track.insert(find[i][j + 1]);
            }   
            for(auto j: track)
            {
                if(j!=0)addOn += size[j];
            }
            res = max(res, addOn);
        }
        cout << res << "\n";
    }
}