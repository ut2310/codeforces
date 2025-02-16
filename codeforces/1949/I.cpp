#include <bits/stdc++.h>
#define ll long long
using namespace std;
#define MAXN 200005
ll visited[MAXN];
struct circle
{
    ll x, y, r;
};
vector<ll> adj[MAXN];
bool checkcycle(ll v, ll parent)
{
    visited[v] = 1;
    bool flag = false;

    for(ll c: adj[v])
    {
        if(visited[c] == 0)
        {
            bool check = checkcycle(c, v);
            if(check) flag = true;
        }
        else
        {
            if(c != parent)
            {
                //cout << c << " " << v << "\n";
                return true;
            } 
        }
    }
    return flag;
}
int main()
{
    ll n; cin >> n;
    vector<circle> input(n);
    for(int i =0; i < n; i++)
    {
        ll xi, yi, ri; cin >> xi >> yi >> ri;
        input[i].x = xi;
        input[i].y = yi;
        input[i].r = ri;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            ll cmp1 = (input[i].r + input[j].r) * (input[i].r + input[j].r);
            ll cmp2 = (input[i].x - input[j].x) * (input[i].x - input[j].x) + (input[i].y - input[j].y) * (input[i].y - input[j].y);
            if(cmp1 == cmp2)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
                //cout << i << " " << j << "\n";
            }
        }

    }
    bool flag = true;
    for(int i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            if(!checkcycle(i, i))
            {
                flag = false;
                break;
            }
        }
    }
    if(flag) cout << "NO\n";
    else cout << "YES\n";
}