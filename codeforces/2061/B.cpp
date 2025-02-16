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
        sort(a.begin(), a.end());
        ll pick = -1; ll used = -1;
        for(int i = n - 1; i >= 1; i--){
            if(a[i] == a[i - 1]){
                pick = a[i];
                used = i;
                a.erase(a.begin() + i); a.erase(a.begin() + i - 1);
                break;
            }
        }
        if(pick == -1){
            cout << "-1\n";
            continue;
        }
        ll min_delta = 1e18; ll track1 = 0; ll track2 = 0;
        for(int i = 0; i < a.size() - 1; i++){
            if(abs(a[i + 1] - a[i]) < min_delta){
                track1 = a[i + 1];
                track2 = a[i];
                min_delta = abs(a[i + 1] - a[i]);
            }
        }
        if(min_delta < 2 * pick){
            cout << pick << " " << pick << " " << track1 << " " << track2 << "\n";
        }
        else{
            cout << "-1\n";
        }
    }
}