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
        ll a, b; cin >> a >> b ;
        ll numBits = 0;
        ll temp = a;
        ll res = 0;
        while(temp > 0){
            numBits++;
            temp >>= 1;
        }
        ll start = b; ll track = 1;
        for(ll i = 0; i < numBits; i++){
            if(b & (1 << i)){
                start -= track;
            }
            track *= 2;
        }
        if(start >= 1) res += (start - 1)/a - 1;
        //cout << numBits << " " <<  start << " " << res << "\n";
        if(start <= a){
            start = a + 1;
        }
        for(ll i = start; i <= b; i++){
            if((i ^ a) % a == 0){
                res++;
            }
        }
        ll upTo = min(a - 1, b);
        for(ll i = 1; i <= upTo; i++){
            if((i ^ a) % i == 0){
                res++;
            }
        }
        if(b >= a) res++;
        cout << res << "\n";
        // we know we can get everything from 1 to start
        
    }
}