using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll diff[MAXN][11];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m, k; cin >> n >> m  >> k;
        vector<ll> a(n); vector<ll> b(m);
        ll res = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i]; res += a[i];
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
        vector<ll> hod(1 << m);
        vector<ll> set_bits(1 << m);
        for(int i = 1; i < (1 << m); i++){
            hod[i] = __bit_width(i) - 1;
            set_bits[i] = __builtin_popcount(i);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= m; j++){
                diff[i][j] = 1e18;
            }
        }
        vector<ll> ans(1 << m);
        for(int i = 0; i < n; i++){
            fill(ans.begin(), ans.end(), 0LL);
            ans[0] = a[i];
            diff[i][0] = a[i];
            for(int j = 1; j < (1 << m); j++){
                ans[j] = ans[j - (1 << hod[j])] & b[hod[j]];
                diff[i][set_bits[j]] = min(diff[i][set_bits[j]], ans[j]);
            }
        }
        priority_queue<ll> pq;
        for(int i = 0; i < n; i++){
            for(int j = 1; j <= m; j++){
                //cout << diff[i][j - 1] - diff[i][j ] << "\n";
                pq.push(diff[i][j - 1] - diff[i][j]);
            }
        }
        for(int i = 0; i < k; i++){
            ll get = pq.top(); pq.pop();
            res -= get;
        }
        cout << res << "\n";
    }
}