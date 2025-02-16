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
vector<ll> sieve[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    for(int i = 1; i <= 1e5; i++){
        for(int j = i * 2; j <= 1e5; j += i){
            sieve[j].push_back(i);
        }
    }
    while(t-->0){
        ll n, m; cin >> n >> m;
        vector<ll> a(m);
        for(int i = 0; i < m; i++){
            cin >> a[i];
        }
        vector<ll> res(n + 1);
        res[1] = m - 1;
        bool check = true;
        for(int i = 2; i <= n; i++){
            set<ll> visited;
            vector<ll> curr = sieve[i];
            for(auto j: curr){
                visited.insert(res[j]);
            }
            bool flag = false;
            for(int j = m - 1; j >= 0; j--){
                if(visited.count(j) == 0){
                    res[i] = j;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                check = false;
                break;
            }

        }
        if(!check){
            cout << "-1\n";
            continue;
        }
        for(int i = 1; i <= n; i++){
            cout << a[res[i]] << " ";
        }
        cout << "\n";
    }
}