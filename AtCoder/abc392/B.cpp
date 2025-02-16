using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 5005
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
    ll n, m; cin >> n >> m;
    set<ll> track;
    for(int i = 0; i < m; i++){
        ll temp; cin >> temp;
        track.insert(temp);
    }
    vector<ll> res;
    for(int i = 1; i <= n; i++){
        if(track.count(i) == 0){
            res.push_back(i);
        }
    }
    cout << res.size() << "\n";
    for(auto j: res){
        cout << j << " ";
    }
    cout << "\n";
}