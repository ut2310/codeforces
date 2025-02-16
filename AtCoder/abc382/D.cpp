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

ll n, m; 
vector<vector<ll>> res;
void recur(vector<ll> &track, ll curr)
{
    if(track.size() == n){
        res.push_back(track);
        return;
    }
    ll i = 10;
    while(true){
        if(curr + i + 10 * (n - track.size() - 1) > m){
            break;
        }
        track.push_back(curr + i);
        recur(track, curr + i);
        i++;
        track.pop_back();
    }
}
int main()
{
    cin >> n >> m;
    vector<ll> track;
    for(int i = 1; i <= 10; i++){
        track.push_back(i);
        recur(track, i);
        track.pop_back();
    }
    cout << res.size() << "\n";
    for(auto i: res){
        for(auto j: i){
            cout << j << " ";
        }
        cout << "\n";
    }
}