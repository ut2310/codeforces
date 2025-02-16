using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 10005
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
        ll n; cin >> n;
        vector<ll> a(n);
        map<ll, ll> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        ll res = 0;
        ll curr_l = -1; ll curr_r = -2; ll track = 0;
        ll final_l = -1; ll final_r = -1;
        for(int i = 0; i < n; i++){
            if(mp[a[i]] == 1 && curr_l == -1){
                curr_l = i; curr_r = i;
            }
            else if(mp[a[i]] == 1){
                curr_r++;
            }
            else{
                if(curr_l != -1){
                    if(curr_r - curr_l + 1 > res){
                        final_l = curr_l;
                        final_r = curr_r;
                        res = curr_r - curr_l + 1;
                    }
                }
                curr_l = -1; curr_r = -2;
            }
        }
        if(curr_r - curr_l + 1 > res){
            final_l = curr_l;
            final_r = curr_r;
            res = curr_r - curr_l + 1;
        }
        //cout << res << "\n";
        if(res == 0){
            cout << res << "\n";
        }
        else{
            cout << (final_l + 1) << " " << (final_r + 1) << "\n";
        }
    }
}