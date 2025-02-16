#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

enum QueryType { ADD, SET, NONE };

struct Tag {
    QueryType type = NONE;
    ll val = 0;
    // Combine the t argument into the current tag.
    void apply(const Tag &t) {
        if (t.type == ADD) {
            val += t.val;
            if (type != SET) 
                type = ADD;
        } else if (t.type == SET) {
            type = SET;
            val = t.val;
        }
    }
};

struct Info {
    ll sum = 0;
    ll max_val = LLONG_MIN;
    // Apply a tag update to this segment covering range [l, r]
    void apply(const Tag &t, int l, int r) {
        if(t.type == SET) {
            sum = t.val * (r - l + 1);
            max_val = t.val;
        } else if(t.type == ADD) {
            sum += t.val * (r - l + 1);
            max_val += t.val;
        }
    }
    // Merge two child segments
    friend Info operator+(const Info &a, const Info &b) {
        Info res;
        res.sum = a.sum + b.sum;
        res.max_val = max(a.max_val, b.max_val);
        return res;
    }
};

template<class Info, class Tag>
struct lazySegTree {
    int n;
    vector<Info> tree;
    vector<Tag> lazy;
    
    // Build the tree from initial array a (with indices from l to r)
    void build(int v, int l, int r, vector<Info> &a) {
        if (l == r) {
            tree[v] = a[l];
        } else {
            int m = (l + r) / 2;
            build(2 * v, l, m, a);
            build(2 * v + 1, m + 1, r, a);
            tree[v] = tree[2 * v] + tree[2 * v + 1];
        }
    }

    // Apply tag t to tree[v] which represents range [l, r] and record lazy info.
    void apply(int v, int l, int r, const Tag &t) {
        tree[v].apply(t, l, r);
        lazy[v].apply(t);
    }

    // Push the pending update stored in lazy[v] to its children
    void push_down(int v, int l, int r) {
        int m = (l + r) / 2;
        apply(2 * v, l, m, lazy[v]);
        apply(2 * v + 1, m + 1, r, lazy[v]);
        lazy[v] = Tag();
    }

    // Recursively update the range [ql, qr] with tag t
    void range_update(int v, int l, int r, int ql, int qr, const Tag &t) {
        if (qr < l || ql > r)
            return;  // No overlap.
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

    // Recursively query the range [ql, qr]
    Info range_query(int v, int l, int r, int ql, int qr) {
        if (qr < l || ql > r)
            return Info();  // Return a neutral element.
        if (ql <= l && r <= qr)
            return tree[v];
        push_down(v, l, r);
        int m = (l + r) / 2;
        return range_query(2 * v, l, m, ql, qr) + 
               range_query(2 * v + 1, m + 1, r, ql, qr);
    }

    // Constructors.
    lazySegTree(int n) {
        this->n = n;
        tree.assign(4 * n, Info());
        lazy.assign(4 * n, Tag());
    }

    lazySegTree(const vector<Info> &a) {
        n = a.size();
        tree.assign(4 * n, Info());
        lazy.assign(4 * n, Tag());
        // Build the tree with the initial array, starting at vertex 1.
        build(1, 0, n - 1, const_cast<vector<Info>&>(a));
    }

    // External interface for range update.
    void range_update(int ql, int qr, const Tag &t) {
        range_update(1, 0, n - 1, ql, qr, t);
    }

    // External interface for range query.
    Info range_query(int ql, int qr) {
        return range_query(1, 0, n - 1, ql, qr);
    }
};

int main() {
    // Create an initial array: [1, 2, 3, 4]
    int n = 4;
    vector<Info> init(n);
    for (int i = 0; i < n; i++) {
        init[i].sum = i + 1;
        init[i].max_val = i + 1;
    }
    
    // Build the lazy segment tree
    lazySegTree<Info, Tag> segTree(init);
    
    // Query the full range [0, 3]
    Info result = segTree.range_query(0, n - 1);
    cout << "Initial range query [0,3]: sum = " << result.sum 
         << ", max = " << result.max_val << "\n";
    
    // Update: Add 5 to range [1,2]
    // New array becomes: [1, (2+5), (3+5), 4] => [1,7,8,4]
    Tag addTag;
    addTag.type = ADD;
    addTag.val = 5;
    segTree.range_update(1, 2, addTag);
    
    // Query after addition update
    result = segTree.range_query(0, n - 1);
    cout << "After adding 5 to range [1,2]: sum = " << result.sum 
         << ", max = " << result.max_val << "\n";
    
    // Update: Set range [0,1] to 10
    // New array becomes: [10,10,8,4]
    Tag setTag;
    setTag.type = SET;
    setTag.val = 10;
    segTree.range_update(0, 1, setTag);
    
    // Query after set update
    result = segTree.range_query(0, n - 1);
    cout << "After setting range [0,1] to 10: sum = " << result.sum 
         << ", max = " << result.max_val << "\n";
    
    return 0;
}
