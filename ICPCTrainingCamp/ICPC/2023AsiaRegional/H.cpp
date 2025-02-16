using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 405
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

int main()
{
    ll n, k; cin >> n >> k;
    ll max_depth = 0;
    ll track = 1;
    while(track <= n){
        track *= 2;
        max_depth++;
    }
    cout << max_depth << "\n";
    ll most = min(k, max_depth);
    
    for(int i = 1; i <= most; i++){
        //number of nodes is (1 << (i - 1))


    }
}