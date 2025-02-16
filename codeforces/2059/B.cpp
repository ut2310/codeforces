using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 5005
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
        ll n, k; cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        if(k == n){
            ll track = 1;
            ll res = -1; 
            for(int i = 1; i < n; i+=2){
                if(a[i] == track){
                    track++;
                }
                else{
                    res = track;
                }
            }
            if(res == -1) res = track;
            cout << res << "\n";
        }
        else{
            ll stop = -1;
            if(a[1] == 1){
                ll stop = -1;
                for(int i = 1; i < n; i++){
                    if(a[i] != 1){
                        stop = i;
                        break;
                    } 
                }
                if(stop == -1){
                    cout << "2\n";
                }
                else{
                    //cout << stop << " " << (n - k) << "\n";
                    if((stop - 1) <= (n - k)){
                        cout << "1\n";
                    }
                    else{
                        cout << "2\n";
                    }
                }
            }
            else{
                cout << 1 << "\n";
            }
        }
    }
}