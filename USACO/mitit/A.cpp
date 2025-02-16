using namespace std;
#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
bool memo[63][40][28][23];
int main()
{
    ll n; cin >> n;
    ll cnt1 = 0;
    for(ll i = 1; i <= n; i*=2){
        ll cnt2 = 0;
        for(ll j = 1; j <= n/i; j*=3){
            ll cnt3 = 0;
            for(ll k = 1; k <= n/(i * j); k *= 5){
                ll cnt4 = 0;
                for(ll k1 = 1; k1 <= n/(i * j * k); k1*=7){
                    string s = to_string(i * j * k * k1);
                    for(int i = 0; i < s.size(); i++){
                        ll get = s[i] - '0';
                        if(get > 1 && (i *j *k *k1) % get == 0){
                        }
                    }
                    cnt4++;
                }
                cnt3++;
            }
            cnt2++;
        }
        cnt1++;
    }
}