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
    cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, k, l; cin >> n >> k >> l;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        double curr = k;
        double res = 0; res += a[0]; // keeps track of double the amount of time passed
        for(int i = 1; i < n; i++){
            double time_passed = res;
            if(curr >= (double) l) break;
            if(a[i] - time_passed <= curr){
                if(a[i] + time_passed <= curr){
                    curr = (a[i] + time_passed + k);
                }
                else{
                    curr += k;
                }
            }
            else{
                //we are at curr and we are at a[i] - time_passed
                res += min((a[i] - time_passed - curr)/(double)2, l - curr);
                double get = (curr + a[i] - time_passed)/(double)2;
                curr = get + k;
            }
        }
        if(curr < (double) l) res += l - curr;
        res *= 2;
        ll x = round(res);
        cout << x << "\n";
    }
}