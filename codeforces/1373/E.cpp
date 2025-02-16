using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
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
    ll t; cin >> t;
    while(t-->0){
        ll n, k; cin >> n >> k;
        //consider mod (k + 1) * x + delta = n
        vector<string> best;
        for(int i = 0; i <= k; i++){
            ll delta = 0; ll track = 0;
            for(int j = 1; j <= k; j++){
                if(j == i){
                    track -= 8;
                }
                else{
                    track += 1;
                }
                delta += track;
            }
            //cout << n << " " << delta << "\n";
            //consider delta mod k + 1 mus be equal to n mod k + 1
            if((delta - n) % (k + 1) == 0){
                //what do we do here, we know we must go to a 0 on the ith one
                ll goal_digit_sum = (n - delta)/(k + 1);
                ll last_digit = -1;
                if(i > 0){
                    last_digit = 10 - i;
                } 
                else{
                    last_digit = 9 - k;
                    if(last_digit > goal_digit_sum && goal_digit_sum >= 0){
                        last_digit = goal_digit_sum;
                        best.push_back(to_string(goal_digit_sum));
                        continue;
                    }
                }
                
                if(last_digit > goal_digit_sum){
                    continue;
                }
                //cout << goal_digit_sum << "\n";
                string res = "";
                goal_digit_sum -= last_digit;
                res.append(to_string(last_digit));
                if(goal_digit_sum >= 9 && k + last_digit >= 10){
                    goal_digit_sum -= 8;
                    res.append("8");
                }
                while(goal_digit_sum > 9){
                    res.append("9");
                    goal_digit_sum -= 9;
                }
                if(goal_digit_sum > 0) res.append(to_string(goal_digit_sum));
                //res.append(to_string(goal_digit_sum));
                reverse(res.begin(), res.end());
                best.push_back(res);
                //cout << i << " " << last_digit << " " << goal_digit_sum << " " << res << "\n";
            }
        }
        if(best.size() == 0){
            cout << "-1\n";
        }
        else{
            ll best_length = 1e5;
            for(auto j: best){
                ll x = j.size();
                // if(j[0]=='0'){
                //     x--;
                // }
                best_length = min(best_length, x);
            }
            vector<string> best2;
            for(auto j: best){
                ll get = j.size();
                // if(j[0] == '0') get--;
                if(best_length == get){
                    best2.push_back(j);
                }
            }
            //cout << "\n";
            sort(best2.begin(), best2.end());
            // if(best[0][0] == '0') cout << best[0].substr(1) << "\n";
            // else
            cout << best2[0] << "\n";
        }       
    }
}