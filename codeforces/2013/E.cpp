using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ll t; cin >> t;
    while(t-->0){
        ll n; cin  >> n;
        vector<ll> a(n);
        map<ll, ll> freq;
        for(int i = 0; i < n; i++){
            cin >>a[i];
        }
        ll curr_gcd = a[0];
        for(int i = 1; i < n; i++){
            curr_gcd = __gcd(a[i], curr_gcd);
        }
        for(int i = 0; i < n; i++){
            a[i] /= curr_gcd;
            freq[a[i]]++;
        }
        sort(a.begin(), a.end());
        vector<ll> res(n);
        res[0] = a[0];
        vector<ll> visited(n);
        for(int i = 1; i < n; i++){
            if(res[i - 1] == 1){
                for(int j = i; j < n; j++){
                    res[j] = 1;
                }
                break;
            }
            else{
                ll min_curr = res[i - 1];
                for(auto j: freq){
                    if(j.second != 0){
                        min_curr = min(__gcd(j.first, res[i - 1]), min_curr);
                    }
                }
                res[i] = min_curr;
            }
        }
        ll final_res = 0;
        for(int i = 0; i < n; i++){
            final_res += res[i];
        }
        final_res *= curr_gcd;
        cout << final_res << "\n";


    }

}