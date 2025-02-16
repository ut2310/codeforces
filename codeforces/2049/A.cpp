using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        vector<ll> zeroes;
        bool flag1 = true;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] != 0) flag1 = false;
            if(a[i] == 0) zeroes.push_back(i);
        }
        bool flag = true;
        ll cnt = 0;
        for(int i = 1; i < zeroes.size(); i++){
            if(zeroes[i] - zeroes[i - 1] > 1){
                cnt++;
            }
        }
        if(cnt > 1) flag = false;
        if(zeroes.size() > 0){
            if(zeroes[0] != 0 && zeroes[zeroes.size() - 1] != n - 1){
                flag = false;
            }
            else if(cnt == 1 && (zeroes[0] != 0 || zeroes[zeroes.size() - 1] != n - 1)){
                flag = false;
            }
        }
        
        if(flag1){
            cout << "0\n";
        }
        else if(flag){
            cout << 1 << "\n";
        }
        else{
            cout << 2 << "\n";
        }
        
    }
}