using namespace std;
#include <bits/stdc++.h>
#define ll long long
struct Node
{
    ll maximal_sum, prefix, suffix, sum;
    void init()
    {
        maximal_sum = 0;
        prefix = 0;
        suffix = 0;
        sum = 0;
    }
};
struct Segtree
{
    ll size; vector<Node> sums;
    void init(ll n)
    {
        size = 1; while(size < n) {size = size * 2;}
        Node x;
        x.init();
        sums.assign(2 * size, x);
    }
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {   
        if(rx - lx == 1)
        {
            if(lx < (ll)a.size())
            {
                sums[x].maximal_sum = max(a[lx], (ll) 0);
                sums[x].sum = a[lx];
                sums[x].prefix = sums[x].maximal_sum;
                sums[x].suffix = sums[x].maximal_sum;
            }
            return;
        }
        build(a, 2 * x + 1, lx, (lx + rx)/2);
        build(a, 2 * x + 2, (lx + rx)/2, rx);
        sums[x].maximal_sum = max(sums[2 * x + 1].suffix + sums[2 * x + 2].prefix, max(sums[2 * x + 1].maximal_sum, sums[2 * x + 2].maximal_sum));
        sums[x].prefix = max(sums[2 * x + 1].prefix, sums[2 * x + 1].sum + sums[2 * x + 2].prefix);
        sums[x].suffix = max(sums[2 * x + 2].suffix, sums[2 * x + 1].suffix + sums[2 * x + 2].sum);
        sums[x].sum = sums[2 * x + 1].sum + sums[2 * x + 2].sum;
    }
    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
        // for(int i = 0; i < sums.size(); i++)
        // {
        //     cout << sums[i].maximal_sum << " " << sums[i].prefix << " " << sums[i].suffix << " " << sums[i].sum << "\n";
        // }
    }
    void set(ll x, ll lx, ll rx, ll i, ll v)
    {
        if(rx - lx == 1)
        {
            sums[x].maximal_sum = max(v, (ll) 0);
            sums[x].sum = v;
            sums[x].prefix = sums[x].maximal_sum;
            sums[x].suffix = sums[x].maximal_sum;
            return;
        }
        ll m = (lx + rx)/2;
        if(i < m) set(2 * x + 1, lx, m, i, v);
        else set(2 * x + 2, m, rx, i, v);
        sums[x].maximal_sum = max(sums[2 * x + 1].suffix + sums[2 * x + 2].prefix, max(sums[2 * x + 1].maximal_sum, sums[2 * x + 2].maximal_sum));
        sums[x].prefix = max(sums[2 * x + 1].prefix, sums[2 * x + 1].sum + sums[2 * x + 2].prefix);
        sums[x].suffix = max(sums[2 * x + 2].suffix, sums[2 * x + 1].suffix + sums[2 * x + 2].sum);
        sums[x].sum = sums[2 * x + 1].sum + sums[2 * x + 2].sum;
    }
    void set(ll i,ll v) // set element i to v
    {
        set(0, 0, size, i, v);
    }
    ll query() //find operation from l to r - 1
    {
        return sums[0].maximal_sum;
    } 
};
 
int main()
{
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    Segtree st;
    st.init(n);
    st.build(a);
    ll res = max(st.query(), (ll)0);
    cout << res << "\n";
    while(m-->0)
    {
        ll i, v; cin >> i >> v;
        st.set(i - 1, v);
        res = max(st.query(), (ll)0);
        cout << res << "\n";
    }
}