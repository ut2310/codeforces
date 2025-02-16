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
        ll n, m; cin >> n >> m;
        vector<ll> a(n); vector<ll> b(m);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < m; i++){
            cin >> b[i];
        }
        ll k = (n + m)/3;
        k = min(k, m);
        k = min(k, n);
        if(k == 0){
            cout << "0\n";
            continue;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        vector<pair<ll, ll>> differences;
        for(int i = 0; i < n; i++){
            if(n - 1 - i > i) differences.push_back({a[n - 1 - i] - a[i], 0});
            else break;
        }
        for(int i = 0; i < m; i++){
            if(m - 1 - i > i) differences.push_back({b[m - 1 - i] - b[i], 1});
            else break;
        }
        sort(differences.begin(), differences.end());
        ll aspace = n; ll bspace = m; 
        priority_queue<ll, vector<ll>, greater<ll>> pq1;
        priority_queue<ll, vector<ll>, greater<ll>> pq2; 
        ll track = 0; ll cnt1 = 0;
        vector<ll> res(k);
        for(int i = differences.size() - 1; i >= 0; i--){
            ll type = differences[i].ss;
            if(type == 0 && bspace > 0 && aspace > 1){
                track += differences[i].ff;
                aspace -= 2; bspace--;
                res[cnt1] = track;
                pq1.push(differences[i].ff);
                cnt1++;
            }
            else if(type == 1 && aspace > 0 && bspace > 1){
                track += differences[i].ff;
                pq2.push(differences[i].ff);
                bspace -= 2; aspace--;
                res[cnt1] = track;
                cnt1++;
            }
            else if(type == 0 && pq2.size() > 0 && aspace > 1){
                bspace += 1; aspace -= 1;
                track -= pq2.top();
                pq2.pop();
                track += differences[i].ff;
                pq1.push(differences[i].ff);
            }
            else if(type == 1 && pq1.size() > 0 && bspace > 1){
                aspace += 1; bspace -= 1;
                track -= pq1.top(); 
                pq1.pop();
                track += differences[i].ff;
                pq2.push(differences[i].ff);
            }
            else{
                continue;
            }
            //cout << differences[i].ff << " " << track << " " << cnt1 << " " << aspace << " " << bspace << "\n";
            if(cnt1 == k) break;
        }
        cout << k << "\n";
        for(int i = 0; i < k; i++){
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}