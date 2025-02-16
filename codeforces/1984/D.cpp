using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000005
ll cnt(ll a, ll b, ll c)
{
    //first index where c - y = b where y goes from 0 to a so y = c - b
    ll cnt = max(0LL, c - b + 1);
    ll res = 0; res += cnt * (b + 1);
    ll start = max(c - b + 1, 0LL);
    ll end = min(a, c);
    if(end >= start){
        res += (end - start + 1) * (c - end + 1 + c - start + 1)/2;
    }
    return res;
    //b ... c - a + 1
}   
int main()
{
    ll t; cin >> t;
    while(t-->0){
        string s; cin >> s;
        ll n = s.size();
        vector<ll> get(26);
        for(int i = 0; i < s.size(); i++){
            get[s[i] - 'a']++;
        }
        ll track = 0; ll curr_gcd = 1;
        for(int i = 1; i < 26; i++){
            track += get[i];
            curr_gcd = __gcd(get[i], curr_gcd);
        }
        if(track == 0){
            cout << (s.size() - 1) << "\n";
        }
        else{
            vector<ll> preva(n);
            vector<ll> futa(n);
            for(int i = 1; i < n; i++){
                if(s[i - 1] == 'a'){
                    preva[i] = preva[i - 1] + 1;
                }
                else{
                    preva[i] = 0;
                }
            }
            for(int i = n - 1; i >= 0; i--){
                if(s[i + 1] == 'a'){
                    futa[i] = futa[i + 1] + 1;
                }
                else{
                    futa[i] = 0;
                }
            }
            vector<ll> track(26);
            for(int i = 1; i * i <= curr_gcd; i++){
                if(curr_gcd % i == 0){
                    ll start = 0;
                    // for(int j = 0; j < n; j++){
                    //     if(s[j])
                    // }
                }
            }

        }
    }
}