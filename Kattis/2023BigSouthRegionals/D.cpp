using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 

int main()
{
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<ll> res;
    for(int d = 2; d <= n; d++){
        if(n % d == 0){
            ll prev_max = -1;
            bool flag = true;
            for(int i = 0; i < n; i+=n/d){
                ll curr_min = 1e9;
                ll curr_max = 0;
                for(int j = i; j < i + n/d; j++){
                    curr_min = min(a[j], curr_min);
                    curr_max = max(a[j], curr_max);
                }
                if(curr_min <= prev_max){
                    flag = false;
                }
                prev_max = curr_max;
            }
            if(flag) res.push_back(d);
        }
    }
    if(res.size() == 0){
        cout << "-1\n";
    }
    else{
        for(auto i: res){
            cout << i << "\n";
        }
    }
}