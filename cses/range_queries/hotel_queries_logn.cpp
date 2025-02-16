using namespace std;
#include <bits/stdc++.h>
#define ll long long
template <typename T, typename F>
struct Segtree {
    ll size;
    vector<T> tree;
    F merge;
    T identity; // Identity element for the operation

    Segtree(F merge_op, T id) : merge(merge_op), identity(id) {}
    //how does indexing work 0 -> correpoonds to the whole array 0, n/2 & n/2 to n
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

    T query(ll val, ll x, ll lx, ll rx, ll l, ll r) {
        if(rx - lx == 1) return lx;
        if ()
        if (lx >= r || rx <= l) return identity;
        if (lx >= l && rx <= r) return tree[x];
        ll m = (lx + rx) / 2;
        T left = query(2 * x + 1, lx, m, l, r);
        T right = query(2 * x + 2, m, rx, l, r);
        return merge(left, right);
    }

    T query(ll node) {
        query(node, 0, 0, size);
        return query(0, 0, size, l, r);
    }
};

int main()
{
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    Segtree <ll, function<ll(ll, ll)>> st([] (ll a, ll b) -> ll { return max(a, b); }, 0);
    st.init(n);
    st.build(a);
    vector<ll> b(m);
    for(int i = 0; i < m; i++){
        cin >> b[i];
    }
    vector<ll> res(m);
    for(int i = 0; i < m; i++){
        ll low = 1; ll high = n;
        ll get_most = st.query(0, n);
        if(get_most < b[i]){
            res[i] = 0;
            continue;
        }
        while(low < high){
            ll mid = (low + high)/2;
            ll value = st.query(0, mid);
            if(value >= b[i]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        res[i] = low;
        a[low - 1] -= b[i];
        st.set(low - 1, a[low - 1]);
    }
    for(int i = 0; i < m; i++){
        cout << res[i] << " ";
    }
    
}