using namespace std;
#include <bits/stdc++.h>
#define ll unsigned long long
#define MAXN 100005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll dp[MAXN][21];
bool check(string s1)
{
    string comp1 = "18446744073709551615";
    return s1 <= comp1;
}
int main()
{
    string s; ll b; 
    cin >> s >> b;
    ll n = s.size(); ll num_of_digits = to_string(b).size();
    if(b == 0){
        if(s == "0"){
            cout << "0\n";
        }
        else{
            cout << "NO WAY\n";
        }
        return 0;
    }
    else if(s == "0"){
        cout << "0\n";
        return 0;
    }
    dp[n][num_of_digits] = 0;
    for(int i = num_of_digits + 1; i <= 20; i++){
        dp[n][i] = 1e9;
    }
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '0'){
            for(int j = 0; j <= 20; j++){
                dp[i][j] = 1e9;
            }
            continue;
        }
        ll upTo = min((unsigned long long) 20, (n - i));
        for(int j = 1; j <= upTo; j++){
            //we are looking at i to i + j - 1;
            string curr = s.substr(i, j);
            if(j == 20){
                if(!check(curr)){
                    dp[i][j] = 1e9;
                    continue;
                }
            }
            //cout << i << " " << j << " " << curr << "\n";
            ll val = stoull(curr);
            if(i + j - 1 == (n - 1)){
                if(val <= b){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = 1e9;
                }
            }
            else{
                dp[i][j] = 1e9;
                ll lookAt = i + j;
                if(dp[lookAt][j] < 1e9){
                    // if(lookAt == 5 && j == 1){
                    //     cout << val << " " << dp[i][j] << " " << i << " " << j << "\n";
                    // }
                    ll val2 = stoull(s.substr(lookAt, j));
                    if(val <= val2){
                        dp[i][j] = min(dp[i][j], dp[lookAt][j] + (unsigned long long) 1);
                    }
                }
                for(int j1 = j + 1; j1 <= 20; j1++){
                    if(dp[lookAt][j1] < 1e9){
                        dp[i][j] = min(dp[i][j], dp[lookAt][j1] + (unsigned long long) 1);
                    }
                }
            }
            //cout << i << " " << j << " " << dp[i][j] << "\n";
        }
        for(int j = upTo + 1; j <= 20; j++){
            dp[i][j] = 1e9;
        }
    }
    ll res = 1e9;
    for(int i = 1; i <= 20; i++){
        res = min(res, dp[0][i]);
    }
    if(res == 1e9){
        cout << "NO WAY\n";
    }
    else{
        cout << res << "\n";
    }
}