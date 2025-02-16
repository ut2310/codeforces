using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#include <cstdio>
int main()
{
    freopen("subsonic_subway_input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t; cin >> t;
    for(int j = 1; j <= t; j++)
    {
        ll n; cin >> n;
        vector<pair<double, double>> a(n + 1);
        for(int i = 1; i <= n; i++){
            ll a1, a2; cin >> a1 >> a2;
            a[i] = make_pair(a1, a2);
        }
        double max_speed = 1e12; //go at max this speed
        double res = 0;
        for(int i = 1; i <= n; i++){
            res = max(res, i/a[i].second);
            if(a[i].first > 0){
                max_speed = min(max_speed, i/a[i].first);
            }
        }
        if(res > max_speed){
            res = -1;
        }
        cout << "Case #" << j << ": " << res << "\n";
    }
}