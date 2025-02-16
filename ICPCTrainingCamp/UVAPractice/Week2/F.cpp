using namespace std;
#include <bits/stdc++.h>
#define ld long double
#define ll long long
#define MAXN 105   
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>

int main()
{
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> a(n - 1);
    ll curr = 0;
    for(int i = n - 2; i >= 0; i--){
        if(s[i] == 'L'){
            curr++;
            a[i] = curr;
        }
        else{
            curr = 0;
            a[i] = curr;
        }
        //cout << i << " " << a[i] << "\n";
    }
    vector<ll> res(n);
    curr = 1;
    for(int i = 0; i < n - 1; i++){
        res[i] = curr + a[i];
        if(s[i] == 'R'){
            curr = i + 2;
        }
        //cout << i << " " << res[i] << " " << curr << " hi\n";
        
    }
    if(s[n - 2] == 'L'){
        res[n - 1] = res[n - 2] - 1; 
    }
    else{
        res[n - 1] = n;
    }
    for(int i = 0; i < n; i++){
        cout << res[i] << "\n";
    }
    cout << "\n";
}