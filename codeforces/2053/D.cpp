using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>
ll M;
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
ll modInverse(ll A)
{
    return power(A, M - 2);
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(nullptr);
    M = 998244353;
    ll t; cin >> t;
    while(t-->0){
        ll n, q; cin >> n >> q;
        vector<pair<ll, ll>> a(n);
        vector<pair<ll, ll>> b(n);
        for(int i = 1; i <= n; i++){
            ll temp; cin >> temp;
            a[i - 1] = {temp, i};
        }
        for(int i = 1; i <= n; i++){
            ll temp; cin >> temp;
            b[i - 1] = {temp, i};
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<ll> res(q + 1);
        vector<ll> prev(n);
        ll res1 = 1;
        for(int i = 1; i <= n; i++){
            res1 *= min(a[i - 1].first, b[i - 1].first);
            prev[i - 1] = min(a[i - 1].first, b[i - 1].first);
            res1 %= M;
        }
        res[0] = res1;
        map<ll, ll> mp1; map<ll, ll> mp2;
        for(int i = 0; i < n; i++){
            mp1[a[i].second] = i;
        }
        for(int i = 0; i < n; i++){
            mp2[b[i].second] = i;
        }
        
        for(int i = 0; i < q; i++){
            //cout << mp1[5] << "\n";
            ll o, x; cin >> o >> x;
            if(o == 1){
                ll i1 = mp1[x];
                auto itr = lower_bound(a.begin(), a.end(), make_pair(a[i1].first + 1, 0));
                a[i1].first++;
                bool flag = false;
                if(i1 < n - 1){
                    //cout << i1 << " " << a[i1].first << " " << a[i1 + 1].first << "chicken\n";
                    if(a[i1].first > a[i1 + 1].first){
                        iter_swap(a.begin() + i1, itr - 1);
                        mp2[a[i1].second] = i1;
                        mp2[a[itr - 1 - a.begin()].second] = itr - a.begin();
                        i1 = itr - 1 - a.begin();
                    }
                    for(auto j: mp1){
                        cout << j.first << " " << j.second << "hi\n";
                    }
                    // while(i1 < n - 1 && a[i1].first > a[i1 + 1].first){
                    //     iter_swap(a.begin() + i1, a.begin() + i1 + 1);
                    //     mp1[a[i1].second] = i1;
                    //     mp1[a[i1 + 1].second] = i1 + 1;
                    //     i1++;
                    //     flag = true;
                    // }
                }
                //cerr << i1 << " " << a[i1].first << "\n";
                res1 *= modInverse(prev[i1]);
                res1 %= M;
                res1 *= min(a[i1].first, b[i1].first);
                res1 %= M;
                prev[i1] = min(a[i1].first, b[i1].first);
                // if(flag){
                //     //cout << i1 << " " << prev[i1] << "typ2\n";
                //     res1 *= modInverse(prev[i1]);
                //     res1 %= M;
                //     res1 *= modInverse(prev[i1 + 1]);
                //     res1 %= M;
                //     res1 *= min(a[i1].first, b[i1].first);
                //     res1 %= M;
                //     res1 *= min(a[i1 + 1].first, b[i1 + 1].first);
                //     res1 %= M;
                //     prev[i1] = min(a[i1].first, b[i1].first);
                //     prev[i1 + 1] = min(a[i1 + 1].first, b[i1 + 1].first);
                // }
                // else{
                //     //cout << i1 << " " << prev[i1] << "typ1\n";
                //     res1 *= modInverse(prev[i1]);
                //     res1 %= M;
                //     res1 *= min(a[i1].first, b[i1].first);
                //     res1 %= M;
                //     prev[i1] = min(a[i1].first, b[i1].first);
                // }
            }
            else{
                ll i1 = mp2[x];
                b[i1].first++;
                bool flag = false;
                if(i1 < n - 1){
                    if(b[i1].first > b[i1 + 1].first){
                        auto itr = lower_bound(b.begin(), b.end(), b[i1]);
                        iter_swap(b.begin() + i1, itr);
                        mp2[b[i1].second] = i1;
                        mp2[b[itr - b.begin()].second] = itr - b.begin();
                        i1 = itr - b.begin();
                    }
                    
                    
                    // while(i1 < n - 1 && b[i1].first > b[i1 + 1].first){
                    //     iter_swap(b.begin() + i1, b.begin() + i1 + 1);
                    //     mp2[b[i1].second] = i1;
                    //     mp2[b[i1 + 1].second] = i1 + 1;
                    //     i1++;
                    //     flag = true;
                    // }
                }
                res1 *= modInverse(prev[i1]);
                res1 %= M;
                res1 *= min(a[i1].first, b[i1].first);
                res1 %= M;
                prev[i1] = min(a[i1].first, b[i1].first);
                // if(flag){
                //     //cout << i1 << " " << prev[i1] << "typ2\n";
                //     res1 *= modInverse(prev[i1]);
                //     res1 %= M;
                //     res1 *= modInverse(prev[i1 + 1]);
                //     res1 %= M;
                //     res1 *= min(a[i1].first, b[i1].first);
                //     res1 %= M;
                //     res1 *= min(a[i1 + 1].first, b[i1 + 1].first);
                //     res1 %= M;
                //     prev[i1] = min(a[i1].first, b[i1].first);
                //     prev[i1 + 1] = min(a[i1 + 1].first, b[i1 + 1].first);
                // }
                // else{
                //     //cout << i1 << " " << prev[i1] << "typ1\n";
                //     res1 *= modInverse(prev[i1]);
                //     res1 %= M;
                //     res1 *= min(a[i1].first, b[i1].first);
                //     res1 %= M;
                //     prev[i1] = min(a[i1].first, b[i1].first);
                // }
            }
            res[i + 1] = res1 % M;
        }
        for(int i = 0; i <= q; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
    }

}