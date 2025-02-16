using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m; cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(m);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
        ll start = a[0];
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<ll> breaks;
        for(int i = 0; i < m; i++){
            auto itr = lower_bound(a.begin(), a.end(), b[i]);
            ll get = itr - a.begin();
            if(b[i] > start){
                if(itr == a.end()){
                    breaks.push_back(0);
                }
                else{
                    breaks.push_back(n - get);
                }
            }
            else{
                breaks.push_back(0);
            }
        }
        // map<ll, ll> freq;
        // for(auto i: breaks){
        //     freq[i]++;
        // }
        // //0: 1, 1: 1, 2: 1*********
        // vector<ll> sfreq;
        // for(auto j: freq){
        //     cout << j.first << " " << j.second << "\n";
        // }
        vector<ll> res(m + 1);
        for(int i = 1; i <= m; i++){
            res[i] += m/i;
        }
        sort(breaks.begin(), breaks.end());
        for(int i = 1; i <= m; i++){
            for(int j = i; j <= m; j+=i){
                res[i] += breaks[j - 1];
            }
            //look at breaks[i - 1]
            //go through divisors of i and breaks[i - 1] to each of the res
        }
        for(int i = 1; i <= m; i++){
            cout << res[i] << " ";
        }
        cout << "\n";



    }
}