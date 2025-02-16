using namespace std;
#include <bits/stdc++.h>
#define ll long long
struct Segtree
{
    ll size; vector<ll> sums;
    void init(ll n)
    {
        size = 1; while(size < n) {size = size * 2;}
        sums.assign(2 * size, 0);
    }
    void build(vector<ll> &a, ll x, ll lx, ll rx)
    {   
        if(rx - lx == 1)
        {
            if(lx < a.size()) sums[x] = a[lx];
            return;
        }
        build(a, 2 * x + 1, lx, (lx + rx)/2);
        build(a, 2 * x + 2, (lx + rx)/2, rx);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }
    void build(vector<ll> &a)
    {
        build(a, 0, 0, size);
    }
    void set(ll x, ll lx, ll rx, ll i, ll v)
    {
        if(rx - lx == 1)
        {
            sums[x] = v;
            return;
        }
        ll m = (lx + rx)/2;
        if(i < m) set(2 * x + 1, lx, m, i, v);
        else set(2 * x + 2, m, rx, i, v);
        sums[x] = sums[2 * x + 1] + sums[2 * x + 2];
    }
    void set(ll i,ll v) // set element i to v
    {
        set(0, 0, size, i, v);
    }
    ll query(ll x, ll lx, ll rx, ll l, ll r)
    {
        if(rx <= l || lx >= r)
        {
            return 0;
        }
        if(lx >= l && rx <= r)
        {
            return sums[x];
        }
        ll m = (lx + rx)/2;
        return query(2 * x + 1, lx, m, l, r) + query(2 * x + 2, m, rx, l, r);
    }
    ll query(ll l, ll r) //find operation from l to r - 1
    {
        return query(0, 0, size, l, r);
    } 
};