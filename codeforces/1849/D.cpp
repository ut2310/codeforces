#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ALPHABETSIZE 26
#define ll long long

int main()
{
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    ll res = 0;
    vector<ll> track;
    bool flag2 = false;
    for(int i = 0; i < n; i++){
        if(a[i] > 0){
            if(i == 0 || a[i - 1] == 0){
                res++;
                if(a[i] == 2){
                    flag2 = true;
                }
            }
        }
        else{
            bool check = false;
            if(i == 0){
                if(a[i + 1] == 0){
                    res++;
                }
            }
            else if(i == n - 1){
                if(a[i - 1] == 0){
                    res++;
                }
                else if(!flag2){
                    res++;
                }
            }
            else{
                if(a[i - 1] == 0 && a[i + 1] == 0){
                    res++;
                }
                else if(a[i + 1] == 0 && !flag2){
                    res++;
                }
                else if(a[i + 1] != 0 && flag2){
                    check = true;
                }
            }
            flag2 = check;
        }
    }
    cout << res << "\n";
}