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
        ll n; cin >> n;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        ll total = n * (n + 1)/2;
        ll cnt = 0;
        for(int i = 1; i <= 10; i++){
            vector<ll> b(n);
            vector<ll> ps(n + 1);
            for(int j = 0; j < n; j++){
                b[j] = (a[j] > i ? 1:-1);
                ps[j + 1] = ps[j] + b[j];
            }   
            map<ll, vector<ll>> freq;
            freq[0].push_back(0);
            ll last_seen = -1;
            for(int j = 0; j < n; j++){
                ll curr = ps[j + 1];
                if(a[j] == i) last_seen = j;
                if(freq[curr].size() > 0){
                    auto itr = upper_bound(freq[curr].begin(), freq[curr].end(), last_seen);
                    ll val = itr - freq[curr].begin();
                    if(itr == freq[curr].end()){
                        cnt+=freq[curr].size();
                    }
                    else{
                        cnt += val;
                    }
                }
                freq[ps[j + 1]].push_back(j + 1);
                //cout << curr << " " << i << " " << j << " " << cnt << "\n";
            }
        }
        cout << total - cnt << "\n";
    }
}