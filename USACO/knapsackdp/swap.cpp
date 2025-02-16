using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 505
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll MOD, n, fact[MAXN], invfact[MAXN];
ll dp[MAXN][31][31][31], n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s;
    ll k; cin >> k;
    n = s.size();
    if(k > (n * (n + 1)/2)) k = n * (n + 1)/2;
    dp[0][0][0][0] = 1;
    ll fk, fe, fy;
    for(int i = 0; i < n; i++){
        if(s[i] == 'K') fk++;
        if(s[i] == 'E') fe++;
        if(s[i] == 'Y') fy++;
    }
    for(int ops = 1; ops <= k; ops++){
        for(int k = 0; k <= fk; k++){
            for(int e = 0; e <= fe; e++){
                for(int y = 0; y <= fy; y++){
                    if(k != 0){
                        dp[]
                    }
                }
            }
        }
    }
    
}