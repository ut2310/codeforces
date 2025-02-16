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
vector<ll> res[MAXN];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, k, x; cin >> n >> k >> x;
        ll y = 0;
        for(int i = 1; i <= n; i++){
            y ^= i;
        }
        if(k % 2 == 0 && y != 0){
            cout << "NO\n";
            continue;
        }
        else if(k % 2 == 1 && y != x){
            cout << "NO\n";
            continue;
        }
        // our goal is to have xor x
        vector<ll> visited(n + 1);
        vector<ll> track(n + 1);
        ll cnt = 1;
        for(int i = 1; i <= n; i++){
            if(visited[i] > 0){
                continue;
            }
            //cout << i << " " << x << "\n";
            if(i == x){
                visited[i] = cnt;
                cnt++;
                continue;
            }
            visited[i] = cnt;
            ll target = x ^ i;
            if(target <= n && visited[target] == 0){
                visited[target] = cnt;
                cnt++;
                continue;
            }
            bool flag = false;
            for(int j = i + 1; j <= n; j++){
                if(visited[j] == 0 && (j ^ target) <= n && visited[j ^ target] == 0){
                    visited[j] = cnt;
                    visited[j ^ target] = cnt;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                for(int j = i + 1; j <= n; j++){
                    if(visited[j] == 0) visited[j] = cnt;
                }
            }
            cnt++;
        }
        cnt--;
        if(k > cnt){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for(int i = 1; i <= n; i++){
            res[visited[i]].push_back(i);
            //cout << visited[i] << " " << i << "\n";
        }
        for(int i = 1; i <= k - 1; i++){
            cout << res[i].size() << " ";
            for(auto j: res[i]){
                cout << j << " ";
            }
            cout << "\n";
        }
        ll total = 0;
        for(int i = k; i <= n; i++){
            total += res[i].size();
        }   
        cout << total << " ";
        for(int i = k; i <= n; i++){
            for(auto j: res[i]){
                cout << j << " ";
            }
        }
        cout << "\n";
        for(int i = 1; i <= n; i++){
            res[i].clear();
        }
    }
}