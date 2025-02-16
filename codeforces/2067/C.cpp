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
        ll x; cin >> x;
        ll res = 7;
        for(int i = 0; i < 7; i++){
            ll temp = x - i;
            if(temp % 10 == 7 || temp % 10 == -3){
                res = i;
                break;
            }
            if(temp < 0){
                continue;
            }
            string s = to_string(temp);
            bool flag = false;
            for(int j = 0; j < s.size() - 1; j++){
                ll curr = s[j] - '0';
                //cout << curr << " " << i << "\n";
                if(curr <= 7){
                    if(7 - curr <= i){
                        flag = true;
                    }
                }
                else{
                    if(17 - curr <= i){
                        flag = true;;
                    }
                }
            }
            if(flag){
                res = i;
                break;
            }
        }
        cout << res << "\n";
    }
}