using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 2000005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll edges[20][20];
ll dp[MAXN];
void debug(vector<ll> a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout << "\n";
}
int main()
{
    string s; cin >> s;
    vector<char> used;
    set<char> track;
    for(int i = 0; i < s.size(); i++){
        if(track.count(s[i]) == 0){
            used.push_back(s[i]);
            track.insert(s[i]);
        }
    }
    sort(used.begin(), used.end());
    map<char, ll> mp;
    for(int i = 0; i < used.size(); i++){
        mp[used[i]] = i;
        //cout << used[i] << " " << i << "\n";
    }
    for(int i = 1; i < s.size(); i++){
        edges[mp[s[i - 1]]][mp[s[i]]]++;
    }
    // for(int i = 0; i <= 5; i++){
    //     for(int j = 0; j <= 5; j++){
    //         cout << edges[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    dp[0] = 1;
    ll n = used.size();
    for(int i = 1; i < (1 << n); i++){
        dp[i] = 1e9;
        vector<ll> lookAt;
        for(int j = 0; j < n; j++){
            if((1 << j) & i){
                lookAt.push_back(j);
            }
        }
        //cout << i << "\n";
        //debug(lookAt);
        for(auto j1: lookAt){
            ll curr = 0;
            for(auto j2: lookAt){
                curr += edges[j1][j2];
            }
            // if(i == 1){
            //     cout << j1 << " " << curr << "hi\n";
            // }
            dp[i] = min(dp[i], dp[i - (1 << j1)] + curr);
        }
        //cout << i << " " << dp[i] << "\n";
    }
    cout << dp[(1 << n) - 1] << "\n";



}