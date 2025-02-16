using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 72
ll n, k;
bool check(vector<ll> &a, ll mid){
    vector<ll> a2(n + 1);
    for(int i = 1; i<= n; i++){
        if(a[i] < mid){
            a2[i] = -1;
        }
        else{
            a2[i] = 1;
        }
    }
    vector<ll> ps(n + 1);
    for(int i = 1; i <= n; i++){
        ps[i] = a2[i] + ps[i - 1];
    }
    vector<ll> psmin(n + 1);
    for(int i = 1; i <= n; i++){
        psmin[i] = min(ps[i], psmin[i - 1]);
    }
    bool flag = false;
    for(int i = k; i <= n; i++){
        if(ps[i] - psmin[i - k] > 0){
            flag = true;
            break;
        }
    }
    return flag;
}
int main()
{
    cin >> n >> k;
    vector<ll> a(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    ll low = 1;
    ll high = n;
    while(low < high){
        ll mid = (low + high + 1)/2;
        if(check(a, mid)){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    cout << low << "\n";
}