#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node
{
    ll arr[41];
    Node(){
        for(int i = 0; i <= 40; i++){
            arr[i] = 0;
        }
    }
};

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
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, m; cin >> n >> m;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    auto mergeFunc = [](const Node &a, const Node &b){
        Node res;
        for(int i = 40; i >= 1; i--){
            res.arr[i] += a.arr[i] + b.arr[i];
        }
        res.arr[0] += a.arr[0] + b.arr[0];
        for(int i = 1; i < 40; i++){
            ll amt = b.arr[i] - b.arr[i + 1];
            res.arr[0] += (amt) * a.arr[i + 1];
        }
        return res;
    };
    Node id;
    Segtree<Node, decltype(mergeFunc)> st(mergeFunc, id);
    st.init(n);
    for(int i = 0; i <= n - 1; i++){
        Node curr;
        for(int j = 1; j <= a[i]; j++){
            curr.arr[j]++;
        }
        st.set(i, curr);
    }
    for(int i = 0; i < m; i++){
        ll type, x, y; cin >> type >> x >> y;
        if(type == 1){
            x--; y--;
            Node res = st.query(x, y + 1);
            cout << res.arr[0] << "\n";
        }
        else{
            x--;
            Node curr; 
            for(int j = 1; j <= y; j++){
                curr.arr[j]++;
            }
            st.set(x, curr);
        }
    }
}