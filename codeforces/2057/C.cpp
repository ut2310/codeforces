using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll l, r; cin >> l >> r;
        // need 0, 0 , 1 or 1, 1, 0
        ll track = 1;
        ll shift = 0;
        ll res1 = 0;
        ll res2 = 0;
        for(ll i = 29; i >= 0; i--){
            //need to check if there is a thing which contains (1 << 29) and (1 << 29) - 1
            ll num = (1 << i);
            ll first_after = ((l + num - 1)/num) * num;
            if((first_after/num) % 2 == 0) first_after += num;
            ll next = first_after - 1;
            if(first_after - 1 < l){
                next += num;
            }
            if(first_after <= r && next <= r){
                res1 = first_after;
                res2 = next;
                //cout << res1 << " " << res2 << "\n";
                break;
            }
        }
        ll res3 = -1;
        for(ll i = l; i <= r; i++){
            if(i != res1 && i != res2){
                res3 = i; break;
            }
        }
        cout << res1 << " " << res2 << " " << res3 << "\n";
        
    }
}