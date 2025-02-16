using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

vector<pair<ll, ll>> adj[MAXN];
enum QueryType { ADD, SET, NONE };

struct Tag {
    QueryType type = NONE;
    ll val = 0;
    void apply(const Tag &t) {
        if (t.type == ADD) {
            val += t.val;
            if (type != SET) type = ADD;
        } else if (t.type == SET) {
            type = SET;
            val = t.val;
        }
    }
};

struct Info {
    ll sum = 0; ll min_e = INT32_MAX; ll cnt = 0;
    void apply(const Tag &t, int l, int r) {
        if (t.type == SET) {
            sum = t.val * (r - l + 1);
            min_e = t.val; cnt = r - l + 1;
        } else if (t.type == ADD) {
            sum += t.val * (r - l + 1);
            min_e += t.val; 
        }
    }
    friend Info operator+(const Info &a, const Info &b) {
        Info res;
        res.sum = a.sum + b.sum;

        // Determine the minimum value and count of elements equal to it
        if (a.min_e < b.min_e) {
            res.min_e = a.min_e;
            res.cnt = a.cnt;
        } else if (a.min_e > b.min_e) {
            res.min_e = b.min_e;
            res.cnt = b.cnt;
        } else {
            res.min_e = a.min_e; // or b.min_e (they are equal)
            res.cnt = a.cnt + b.cnt;
        }

        return res;
    }
};

template<class Info, class Tag>
struct lazySegTree {
    int n;
    vector<Info> tree;
    vector<Tag> lazy;

    void build(int v, int l, int r, const vector<Info> &a) {
        if (l == r) {
            tree[v] = a[l];
        } else {
            int m = (l + r) / 2;
            build(2 * v, l, m, a);
            build(2 * v + 1, m + 1, r, a);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
        //cout << l << " " << r << " " << tree[v].min_e << " " << tree[v].cnt << "\n";
    }

    void apply(int v, int l, int r, const Tag &t) {
        tree[v].apply(t, l, r);
        lazy[v].apply(t);
    }

    void push_down(int v, int l, int r) {
        int m = (l + r) / 2;
        apply(2 * v, l, m, lazy[v]);
        apply(2 * v + 1, m + 1, r, lazy[v]);
        lazy[v] = Tag();
    }

    void range_update(int v, int l, int r, int ql, int qr, const Tag &t) {
        if (qr < l || ql > r) return;
        if (ql <= l && r <= qr) {
            apply(v, l, r, t);
        } else {
            push_down(v, l, r);
            int m = (l + r) / 2;
            range_update(2 * v, l, m, ql, qr, t);
            range_update(2 * v + 1, m + 1, r, ql, qr, t);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    Info range_query(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return Info();
        if (ql <= l && r <= qr) return tree[v];
        push_down(v, l, r);
        int m = (l + r) / 2;
        return range_query(2 * v, l, m, ql, qr) + range_query(2 * v + 1, m + 1, r, ql, qr);
    }

    lazySegTree(int n) {
        this->n = n;
        tree.assign(4 << __lg(n), Info());
        lazy.assign(4 << __lg(n), Tag());
    }

    lazySegTree(const vector<Info> &a) {
        n = a.size();
        tree.assign(4 << __lg(n), Info());
        lazy.assign(4 << __lg(n), Tag());
        build(1, 0, n - 1, a);
    }

    void range_update(int ql, int qr, const Tag &t) {
        range_update(1, 0, n - 1, ql, qr, t);
    }

    Info range_query(int ql, int qr) {
        return range_query(1, 0, n - 1, ql, qr);
    }
};
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m; cin >> n >> m;
        //numbers are from 0 to n - 1
        vector<Info> init(n);
        for(int i = 0; i < n; i++){
            init[i].cnt = 1; init[i].min_e = 0;
        }
        lazySegTree<Info, Tag> segTree(init);
        //cout << segTree.range_query(0, n - 1).cnt << " " << segTree.range_query(0, n - 1).min_e << "\n";
        
        for(int i = 0; i < m; i++){
            ll a, b; cin >> a >> b;
            a--; b--;
            adj[a].push_back({a, b});
            adj[b].push_back({a, b});
            Tag temp; temp.type = ADD; temp.val = 1;
            segTree.range_update(a, b - 1, temp);
        }
        ll res = segTree.range_query(0, n - 1).cnt;
        //cout << segTree.range_query(0, n - 1).cnt << " " << segTree.range_query(0, n - 1).min_e << "\n";
        for(int i = 0; i < n; i++){
            for(auto j: adj[i]){
                Tag temp; temp.type = ADD;
                if(j.ff == i){
                    //need to subtract inverted range, and add the normal range
                    temp.val = -1;
                    segTree.range_update(j.ff, j.ss - 1, temp);
                    temp.val = 1;
                    segTree.range_update(j.ss, n - 1, temp);
                    if(j.ff > 0){
                        segTree.range_update(0, j.ff - 1, temp);
                    }
                }
                else{
                    temp.val = 1;
                    segTree.range_update(j.ff, j.ss - 1, temp);
                    temp.val = -1;
                    segTree.range_update(j.ss, n - 1, temp);
                    if(j.ff > 0){
                        segTree.range_update(0, j.ff - 1, temp);
                    }
                }
            }
            ll ans = segTree.range_query(0, n - 1).cnt;
            //cout << segTree.range_query(0, n - 1).cnt << " " << segTree.range_query(0, n - 1).min_e << "\n";
            res = max(res, ans);
        }
        cout << n - res << "\n";
        for(int i = 0; i < n; i++){
            adj[i].clear();
        }
    }
    

}