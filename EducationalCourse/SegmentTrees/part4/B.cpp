#include <bits/stdc++.h>
using namespace std;

#define ll int

ll mod;

struct Matrix {
    ll n, m;
    ll cell[2][2];
    
    // Default constructor: builds a 2x2 zero matrix.
    Matrix() : n(2), m(2) {
        cell[0][0] = cell[0][1] = cell[1][0] = cell[1][1] = 0;
    }
    
    // Parameterized constructor.
    Matrix(ll x, ll y) : n(x), m(y) {
        cell[0][0] = cell[0][1] = cell[1][0] = cell[1][1] = 0;
    }
    
    // Unrolled 2x2 multiplication.
    Matrix operator*(const Matrix &other) const {
        Matrix res(2, 2);
        res.cell[0][0] = ( cell[0][0] * other.cell[0][0] + cell[0][1] * other.cell[1][0] ) % mod;
        res.cell[0][1] = ( cell[0][0] * other.cell[0][1] + cell[0][1] * other.cell[1][1] ) % mod;
        res.cell[1][0] = ( cell[1][0] * other.cell[0][0] + cell[1][1] * other.cell[1][0] ) % mod;
        res.cell[1][1] = ( cell[1][0] * other.cell[0][1] + cell[1][1] * other.cell[1][1] ) % mod;
        return res;
    }
    
    void update(ll i, ll j, ll num) {
        if(i < n && j < m)
            cell[i][j] = num;
        else
            cout << "check indexing!\n";
    }
    
    void identity() {
        if(n != m) {
            cout << "check indexing!\n";
            return;
        }
        cell[0][0] = 1;
        cell[0][1] = 0;
        cell[1][0] = 0;
        cell[1][1] = 1;
    }
    
    void debug(){
        cout << cell[0][0] << " " << cell[0][1] << "\n"
             << cell[1][0] << " " << cell[1][1] << "\n";
    }
};

// An iterative-type segment tree that stores its data in a dynamic array.
template <typename T, typename F>
struct Segtree {
    ll size;
    T* tree;  // Using a dynamically allocated array instead of vector.
    F merge;
    T identity; // Identity element for the operation.
    
    Segtree(F merge_op, T id) : merge(merge_op), identity(id) {
        tree = nullptr;
    }
    
    void init(ll n) {
        size = 1;
        while(size < n) size *= 2;
        if(tree != nullptr) delete[] tree;
        tree = new T[2 * size];
        for(ll i = 0; i < 2 * size; i++){
            tree[i] = identity;
        }
    }
    
    // Build the tree from an array a[] of size a_size.
    void build(T a[], ll a_size) {
        for(ll i = 0; i < size; i++){
            if(i < a_size)
                tree[size + i] = a[i];
            else
                tree[size + i] = identity;
        }
        for(ll i = size - 1; i > 0; i--){
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
    }
    
    void set(ll i, T v) {
        i += size;
        tree[i] = v;
        for(i /= 2; i >= 1; i /= 2){
            tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
        }
    }
    
    // Query in the interval [l, r) (0-indexed).
    T query(ll l, ll r) { 
        T left = identity, right = identity;
        l += size;
        r += size;
        while(l < r){
            if(l & 1){
                left = merge(left, tree[l]);
                l++;
            }
            if(r & 1){
                r--;
                right = merge(tree[r], right);
            }
            l /= 2;
            r /= 2;
        }
        return merge(left, right);
    }
    
    ~Segtree() {
        if(tree) delete[] tree;
    }
};

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    
    ll n, q;
    cin >> mod >> n >> q;
    
    // Allocate an array of Matrix objects.
    Matrix* arr = new Matrix[n];
    for (int i = 0; i < n; i++){
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        arr[i] = Matrix(2, 2);
        arr[i].update(0, 0, a);
        arr[i].update(0, 1, b);
        arr[i].update(1, 0, c);
        arr[i].update(1, 1, d);
    }
    
    Matrix id(2, 2);
    id.identity();
    
    // Define the merge as our matrix multiplication.
    auto mergeFunc = [](const Matrix &A, const Matrix &B) -> Matrix {
        return A * B;
    };
    
    Segtree<Matrix, decltype(mergeFunc)> st(mergeFunc, id);
    st.init(n);
    st.build(arr, n);
    
    for (int i = 0; i < q; i++){
        ll l, r;
        cin >> l >> r;
        l--; r--;  // Converting to 0-indexed.
        Matrix ans = st.query(l, r + 1);  // query expects [l, r+1)
        cout << ans.cell[0][0] << " " << ans.cell[0][1] << "\n";
        cout << ans.cell[1][0] << " " << ans.cell[1][1] << "\n\n";
    }
    
    return 0;
}
