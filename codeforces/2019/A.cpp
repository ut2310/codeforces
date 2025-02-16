    using namespace std;
    #include <bits/stdc++.h>
    #define ll long long
    #define MAXN 200005
    #define ALPHABETSIZE 26

    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ll t; cin >> t;
        while(t-->0){
            ll n; cin >> n;
            vector<ll> a(n);
            for(int i = 0; i < n; i++){
                cin >> a[i];
            }
            ll res = 0;
            for(int i = 0; i < n; i++){
                ll cnt = i/2;
                cnt += (n - 1 - i)/2;
                res = max(res, a[i] + cnt);
            }
            cout << res + 1 << "\n";
        }
    }