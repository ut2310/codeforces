#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ALPHABETSIZE 26
#define ll long long

int main()
{
    ll t; cin >> t;
    while(t-->0){
        ll n, k; cin >> n >> k;
        ll prod = 1;
        bool flag = true;
        for(int i = 1; i <= n; i++){
            prod *= i;
            if(prod > k){
                flag = false;
                break;
            }
        }
        if(n % 2 == 0 && k % 2 != 0){
            flag = false;
        }   
        if(!flag){
            cout << "NO\n";
            continue;
        }
        
    }
}