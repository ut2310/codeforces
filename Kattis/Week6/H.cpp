using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, k; cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(a[i] <= k){
            cout << "It hadn't snowed this early in " << i << " years!";
            flag = true;
            break;
        }
    }
    if(!flag){
        cout << "It had never snowed this early!";
    }
}