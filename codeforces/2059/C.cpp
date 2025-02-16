using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 305
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll arr[MAXN][MAXN];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> arr[i][j];
            }
        }
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        for(int i = 1; i <= n; i++){
            ll track = 0;
            for(int j = n; j >= 1; j--){
                if(arr[i][j] == 1){
                    track++;
                }
                else{
                    break;
                }
            }
            pq.push(track);
        }   
        ll res = 0;
        while(pq.size() > 0){
            if(pq.top() >= res){
                res++;
            }
            pq.pop();
        }
        cout << res << "\n";
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                arr[i][j] = 0;
            }
        }
    }
}