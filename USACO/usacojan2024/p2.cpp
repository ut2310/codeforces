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
ll dp[101][10001], M;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    M = 1e9 + 7;
    ll n, q, c; cin >> n >> q >> c;
    vector<pair<ll, ll>> curr;
    set<ll> track;
    for(int i = 0; i < q; i++){
        ll l, r; cin >> l >> r;
        if(track.count(r) == 0){
            curr.push_back({r - 1, r});
            track.insert(r);
        }
    }
    sort(curr.begin(), curr.end());
    for(int i = 0; i < curr.size(); i++){
        for(int j = 1; j <= c; j++){
            if(i == 0){
                
            }
        }
    }
}