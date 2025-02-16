using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
set<ll> adj[MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        string s; cin >> s;
        //we start from 1->2->n
        ll deg = 0;
        for(int i = 1; i <= n; i++){
            deg += (s[i - 1] - '0');
        }
        cout << deg << "\n";
        if(deg % 2 != 0){
            cout << "NO\n";
            continue;
        }
        
        vector<ll> track;
        track.push_back(1); track.push_back(2);
        ll curr1 = n; ll curr2 = 3;
        for(int i = 3; i <= n; i++){
            if(i % 2 == 1){
                track.push_back(curr1);
                curr1--;
            }
            else{
                track.push_back(curr2);
                curr2++;
            }
        }
        for(int i = 1; i < n; i++){
            adj[track[i]].insert(track[i - 1]);
            adj[track[i - 1]].insert(track[i]);
        }
        for(int i = 0; i < n - 1; i++){
            ll node = track[i];
            if((adj[node].size() % 2) != s[node - 1] - '0'){
                if(i < n - 2){
                    adj[track[i]].insert(track[i + 2]);
                    adj[track[i + 2]].insert(track[i]);
                    adj[track[i + 1]].erase(track[i + 2]);
                    adj[track[i + 2]].erase(track[i + 1]);
                }
                else if(i == n - 2){
                    ll node = *adj[track[i]].begin();
                    adj[track[i]].erase(node);
                    adj[node].erase(track[i]);
                    adj[node].insert(track[i + 1]);
                    adj[track[i + 1]].insert(node);
                }
            }
        }
        bool flag = false;
        ll cnt = 0;
        for(int i = 1; i <= n; i++){
            cnt += adj[i].size();
            if(adj[i].size() == 0){
                flag = true;
            }
        }
        // if(cnt != 2 * (n - 1) || flag){
        //     cout << "NO\n";
        //     for(int i = 1; i <= n; i++){
        //         adj[i].clear();
        //     }
        //     continue;
        // }
        cout << "YES\n";
        for(int i = 1; i <= n; i++){
            for(auto j: adj[i]){
                if(i < j){
                    cout << i << " " << j << "\n";
                }
            }
        }
        for(int i = 1; i <= n; i++){
            adj[i].clear();
        }
    }
}