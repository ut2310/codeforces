using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 305
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>
ll ceil(ll m, ll n)
{
    return (m + n - 1)/n;
}
int main()
{
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        vector<ll> s(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> s[i];
        }

        priority_queue<pair<pii, pii>, vector<pair<pii, pii>>, greater<pair<pii, pii>>> intervals;
        for(int i = 1; i < n; i++){
            if(i % 2 == 1){
                intervals.push({{ceil(a[i] - a[i - 1], s[i] + s[i - 1]), -1}, {i - 1, i}});
            }
            else{
                intervals.push({{ceil(a[i] - a[i - 1], s[i] + s[i - 1]), 0}, {i - 1, i}});
            }
        }
        vector<ll> res(n);
        vector<ll> prev(n);
        vector<ll> next(n);
        prev[0] = -1;
        for(int i = 1; i < n; i++){
            prev[i] = i - 1;
        }
        for(int i = 0; i < n - 1; i++){
            next[i] = i + 1;
        }
        next[n - 1] = -1;
        while(intervals.size() > 0){
            auto get_top = intervals.top();
            ll n1 = get_top.ss.ff;
            ll n2 = get_top.ss.ss;
            intervals.pop();
            if(res[n1] != 0 || res[n2] != 0){
                continue;
            }
            res[n1] = 2 * get_top.ff.ff + get_top.ff.ss;
            res[n2] = 2 * get_top.ff.ff + get_top.ff.ss;
            if(prev[n1] != -1){
                next[prev[n1]] = next[n2];
            }
            if(next[n2] != -1){
                prev[next[n2]] = prev[n1];
            }
            if(prev[n1] != -1 && next[n2] != -1){
                if(next[n2] % 2 == 1){
                    intervals.push({{ceil(a[next[n2]] - a[prev[n1]], s[next[n2]] + s[prev[n1]]), -1}, {prev[n1], next[n2]}});
                }
                else{
                    intervals.push({{ceil(a[next[n2]] - a[prev[n1]], s[next[n2]] + s[prev[n1]]), 0}, {prev[n1], next[n2]}});
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(i < n - 1){
                cout << res[i] << " ";
            }
            else{
                cout << res[i];
            }
        }
        cout << "\n";
    }       
}