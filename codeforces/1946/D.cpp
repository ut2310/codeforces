using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
ll get_bit(ll x){
    return log2(x);
}
ll get_value(vector<ll> &a)
{
    ll res = 0;
    ll curr = 0;
    for(int i = 0; i < a.size(); i++){
        curr ^= a[i];
        if(curr == 0){
            res++;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, x; cin >> n >> x;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        ll get = 0;
        for(int i = 0; i < n; i++){
            get ^= a[i];
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 30; j++){
                if((1 << j) & get){
                    if((1 << j) & a[i]){
                        a[i] -= (1 << j);
                    }
                }
            }
        }
        x -= get;
        if(x < 0){
            cout << "-1\n";
            continue;
        }
        ll best = 1;
        vector<ll> remove_bits(30);
        while(x >= 0){
            ll highest_bit = -1;
            if(x > 0){
                highest_bit = get_bit(x);
            }
            vector<ll> temp(n);
            for(int i = 0; i < n; i++){
                temp[i] = a[i];
            }
            for(int i = 0; i < n; i++){
                for(int j = 0; j < 30; j++){
                    if(j < highest_bit || remove_bits[j] == 1){
                        if(temp[i] & (1 << j)){
                            temp[i] -= (1 << j);
                        }
                    }
                }
            }
            best = max(best, get_value(temp));
            if(x == 0) break;
            remove_bits[highest_bit] = 1;
            x -= (1 << highest_bit);
        }
        
        best = max(best, get_value(a));
        cout << best << "\n";
        
    }
}