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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll a, b; cin >> a >> b;
        ll curr = 1;
        ll res = 0;
        for(int i = 1; i <= 20; i++){
            if(curr <= a && curr * 2 > a){
                ll stop = min(b, curr * 2 - 1);
                for(ll j = curr; j <= stop; j++){
                    ll num = a ^ j; if(num == 0) continue;
                    if(j % num == 0 || a % num == 0){
                        res++;
                    }
                }
                break;
            }
            else{
                curr *= 2;
            }
        }
        cout << res << "\n";
    }
}