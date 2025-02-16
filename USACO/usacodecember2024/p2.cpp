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

int main()
{
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> dp(n + 1);
    vector<ll> last_seen(n);
    vector<ll> first_after(n);
    if(s[0] != 'R') last_seen[0] = -1;
    if(s[n - 1] != 'B') first_after[n - 1] = n;
    else first_after[n - 1] = n - 1;
    for(int i = 1; i < n; i++){
        if(s[i] == 'R'){
            last_seen[i] = i;
        }
        else{
            last_seen[i] = last_seen[i - 1];
        }
    }
    for(int i = n - 2; i >= 0; i--){
        if(s[i] == 'B'){
            first_after[i] = i;
        }
        else{
            first_after[i] = first_after[i + 1];
        }
    }
    dp[0] = 1;
    if(s[0] == 'B' || s[0] == 'R'){
        dp[1] = 0;
    }
    else{
        dp[1] = 1;
    }
    for(int i = 2; i <= n; i++){
        if(s[i - 1] == 'X'){
            dp[i] += dp[i - 1];
        }
        else if(s[i - 1] == 'R'){
            dp[i] = 0;
            continue;
        }
        for(int j = 2; j <= i; j+=2){
            //compare strings A*j/2 + B * j/2 with s[i - j, i - 1]
            //check if the last seen A[i - 1] < i - j/2 and we happy
            //check the first B after B[i - j] >= i - j/2 
            if(last_seen[i - 1] < i - j/2 && first_after[i - j] >= i - j/2){
                dp[i] += dp[i - j];
            }
        }
    }
    // for(int i = 0; i < n; i++){
    //     firs
    // }
    for(int i = 0; i <= n; i++){
        cout << dp[i] << " ";
    }
    cout << "\n";
    cout << dp[n] << "\n";
}