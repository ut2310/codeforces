using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ll N; cin >> N;
    vector<ll> a(N);
    for(int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll res = -1;
    for(int i = 0; i <= N - 7; i++)
    {
        ll comp1 = a[i] + a[i + 1] + a[i + 2] + a[i + 3] - a[i + 4];
        if(comp1 > 0){
            ll i1 = lower_bound(a.begin(), a.end(), comp1) - a.begin() - 1;
            
            if(i1 > i + 4 && i1 <= N - 2 && a[i1] < comp1){
                ll i2 = lower_bound(a.begin(), a.end(), a[i1] + a[i + 4]) - a.begin() - 1;
                if(i2 >= 0 && i2 <= N - 1 && a[i2] < a[i1] + a[i + 4])
                {
                    res = max(res, a[i] + a[i + 1] + a[i + 2] + a[i + 3] + a[i + 4] + a[i1] + a[i2]);
                }
            }
        }

    }
    cout << res << "\n";
    
}