using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout << fixed << setprecision(15);
    ll C; cin >> C;
    for(int i = 1; i <= C; i++){
        ll N; cin >> N;
        vector<pair<ll, ll>> a(N);
        for(int i = 0; i < N; i++){
            ll p, t; cin >> p >> t;
            a[i] = {t, p};
        }
        sort(a.begin(), a.end());
        double low = 0;
        double high = 1e9/2;

        for(int j = 1; j <= 100; j++)
        {
            double mid = (low + high)/2;
            double l = a[0].second - mid;
            double r = a[0].second + mid;
            bool flag = true;
            ll temp = -1;
            for(int i1 = 1; i1 < N; i1++){
                ll delta = a[i1].first - a[i1 - 1].first;
                l -= delta;
                r += delta;
                if(a[i1].second + mid < l || a[i1].second - mid > r){
                    flag = false;
                    temp = i1;
                    break;
                }
                else{
                    l = max(l, a[i1].second - mid);
                    r = min(r, a[i1].second + mid);
                }
                
            }
            
            if(flag){
                high = mid;
            }
            else{
                low = mid;
            }
        }
        // setprecision(19);
        cout << "Case #" << i << ": "  << low << "\n";
    }
}