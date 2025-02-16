using namespace std;
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define ff first
#define ss second

ll n;
template<class T, int N> struct Matrix {
    typedef Matrix M;
    array<array<T, N>, N> d{};
    M operator*(const M& m) const {
        M a;
        rep(i,0,N) rep(j,0,N)
        rep(k,0,N) a.d[i][j] += d[i][k]*m.d[k][j];
        return a;
    }
    vector<T> operator*(const vector<T>& vec) const {
        vector<T> ret(N);
        rep(i,0,N) rep(j,0,N) ret[i] += d[i][j] * vec[j];
        return ret;
    }
    M operator^(ll p) const {
        assert(p >= 0);
        M a, b(*this);
        rep(i,0,N) a.d[i][i] = 1;
        while (p) {
            if (p&1) a = a*b;
            b = b*b;
            p >>= 1;
        }
    return a;
    }
};


int matInv(vector<vector<double>>& A) {
    int n = sz(A); vi col(n);
    vector<vector<double>> tmp(n, vector<double>(n));
    rep(i,0,n) tmp[i][i] = 1, col[i] = i;
    rep(i,0,n) {
        int r = i, c = i;
        rep(j,i,n) rep(k,i,n)
        if (fabs(A[j][k]) > fabs(A[r][c]))
            r = j, c = k;
        if (fabs(A[r][c]) < 1e-12) return i;
        A[i].swap(A[r]); tmp[i].swap(tmp[r]);
        rep(j,0,n)
            swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
        swap(col[i], col[c]);
        double v = A[i][i];
        rep(j,i+1,n) {
            double f = A[j][i] / v;
            A[j][i] = 0;
            rep(k,i+1,n) A[j][k] -= f*A[i][k];
            rep(k,0,n) tmp[j][k] -= f*tmp[i][k];
        }
        rep(j,i+1,n) A[i][j] /= v;
        rep(j,0,n) tmp[i][j] /= v;
        A[i][i] = 1;
    }
    for (int i = n-1; i > 0; --i) rep(j,0,i) {
        double v = A[j][i];
        rep(k,0,n) tmp[j][k] -= v*tmp[i][k];
    }
    rep(i,0,n) rep(j,0,n) A[col[i]][col[j]] = tmp[i][j];
    return n;
}
pair<ll, ll> get(ll x)
{
    ll low = 1; ll high = n;
    while(low < high){
        ll mid = (low + high)/2;
        if(x < mid * (mid + 1)/2){
            high = mid;
        }
        else{
            low = mid + 1;
        }
    }
    // row #low
    ll y = x - low * (low - 1)/2 + 1;
    return {low, y};
}
int main()
{
    cin >> n;
    ll x = n * (n + 1)/2;
    vector<ll> a(x + 1);
    for(int i = 0; i < x; i++){
        cin >> a[i];
    }
    vector<vector<ll>> matrix(x, vector<ll> (x));
    for(int i = 0; i < x; i++){
        ld a, b, c, d, e;
        cin >> a >> b >> c >> d >> e;
        pair<ll, ll> curr = get(i);
        ll row = curr.ff; ll col = curr.ss;
        if(a > 0){
            //i - row
        }
        if(b > 0){
            //i - row + 1
        }
        if(c > 0){
            //
        }
        if(d > 0){
            
        }
        if(e > 0){

        }
    }

}