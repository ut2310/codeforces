using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 105
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
pair<ll, ll> dp[150000][MAXN]; //dp keeps track of all subsets that 
int main()
{
    ll n; cin >> n;
    vector<ll> b(n - 1);
    vector<vector<ll>> factors(n - 1);
    for(int i = 0; i < n - 1; i++){
        cin >> b[i];
    }
    for(int i = 0; i < n - 1; i++){
        for(int j = 1; j <= 100; j++){
            if(b[i] % j == 0 && b[i]/j <= 100){
                factors[i].push_back(j);
            }
        }
    }
    for(int i = 1; i <= 100; i++){
        dp[0][i] = {1, -1};
    }
    for(int i = 1; i < (1 << (n - 1)); i++){
        for(int j = 0; j < n - 1; j++){
            if((1 << j) & i){
                //go through all factors of j less than a 100
                for(auto curr: factors[j]){
                    if(dp[i - (1 << j)][b[j]/curr].ff == 1){
                        dp[i][curr] = {1, j};
                        //cout << curr << " " << i << " " << j << " " << b[j] << " " << dp[i][curr].ff << " " << dp[i][curr].ss << "\n";
                    }
                }
            }
        }
    }
    bool flag = false;
    vector<ll> res;
    for(int i = 1; i <= 100; i++){
        if(dp[(1 << (n - 1)) - 1][i].ff == 1){
            ll track = (1 << (n - 1)) - 1; ll temp = i;
            while(track > 0){
                res.push_back(temp);
                ll idx = dp[track][temp].ss;
                //cout << track << " " << temp << " " << idx << "\n";
                track -= (1 << idx);
                temp = b[idx]/temp;
            }
            res.push_back(temp);
            flag = true;
            break;
        }
    }
    if(flag){
        cout << "Yes\n";
        for(int i = 0; i < res.size(); i++){
            cout << res[i] << " ";
        }
        cout << "\n";
    }
    else{
        cout << "No\n";
    }

    
    
}