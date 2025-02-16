#include <bits/stdc++.h>
using namespace std;
#define ll long long

template <typename T, typename F>
struct Segtree {
    ll size;
    vector<T> tree;
    F merge;
    T identity; // Identity element for the operation

    Segtree(F merge_op, T id) : merge(merge_op), identity(id) {}

    void init(ll n) {
        size = 1;
        while (size < n) size *= 2;
        tree.assign(2 * size, identity);
    }

    void build(vector<T> &a, ll x, ll lx, ll rx) {
        if (rx - lx == 1) {
            if (lx < (ll)a.size()) tree[x] = a[lx];
            return;
        }
        ll m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void build(vector<T> &a) {
        build(a, 0, 0, size);
    }

    void set(ll x, ll lx, ll rx, ll i, T v) {
        if (rx - lx == 1) {
            tree[x] = v;
            return;
        }
        ll m = (lx + rx) / 2;
        if (i < m)
            set(2 * x + 1, lx, m, i, v);
        else
            set(2 * x + 2, m, rx, i, v);
        tree[x] = merge(tree[2 * x + 1], tree[2 * x + 2]);
    }

    void set(ll i, T v) {
        set(0, 0, size, i, v);
    }

    T query(ll x, ll lx, ll rx, ll l, ll r) {
        if (lx >= r || rx <= l) return identity;
        if (lx >= l && rx <= r) return tree[x];
        ll m = (lx + rx) / 2;
        T left = query(2 * x + 1, lx, m, l, r);
        T right = query(2 * x + 2, m, rx, l, r);
        return merge(left, right);
    }

    T query(ll l, ll r) {
        return query(0, 0, size, l, r);
    }
};

int main()
{
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Segtree<ll, function<ll(ll, ll)>> st([](ll a, ll b) { return a + b; }, 0);
    st.init(n);
    for(int i = 0; i < n; i++){
        a[i]--;
        ll ans = st.query(a[i] + 1, n);
        st.set(a[i], 1);
        cout << ans << " ";
    }
}