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
bool primes[MAXN];
bool visited[MAXN];
ll track[MAXN];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    for(int i = 2; i <= 200001; i++){
        if(!visited[i]){
            visited[i] = true;
            for(int j = 2; j <= 200001/i; j++){
                visited[j * i] = true;
            }
            primes[i] = true;
        }
    }
    // for(int i = 1; i <= 20; i++){
    //     cout << primes[i] << " ";
    // }
    //cout << "\n";
    while(t-->0){
        ll n; cin >> n;
        for(int i = 0; i < n; i++){
            ll temp; cin >> temp;
            track[temp]++;
        }        
        ll res = 0;
        vector<ll> loop;
        for(int i = 2; i <= n; i++){
            if(primes[i])
            {
                loop.push_back(i);
            }
        }
        for(int i1 = 0; i1 < loop.size(); i1++){
            for(int j1 = i1; j1 < loop.size(); j1++){
                ll i = loop[i1]; ll j = loop[j1];
                if(i == j){
                    if(i * j <= n){
                        res += track[i * j] * (track[i]);
                        res += track[i * j] * (track[i * j] + 1)/2;
                    }
                    
                }
                else{
                    res += track[i] * track[j];
                    if(i * j <= n){
                        res += track[i] * track[i * j];
                        res += track[j] * track[i * j];
                        res += track[i * j] * (track[i * j] + 1)/2;
                    }
                    
                }
                //cout << i << " " << j << " " << res << "\n";
            }
        }
        cout << res << "\n";
        for(int i = 1; i<= n; i++){
            track[i] = 0;
        }
    }
}