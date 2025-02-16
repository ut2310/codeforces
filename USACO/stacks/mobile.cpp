using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 305
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>

ld figure(ld x1, ld y1, ld x2, ld y2)
{
    ld mx = (x1 + x2)/2;
    ld my = (y1 + y2)/2;
    //my = m * (mx) + b
    ld m = (x1 - x2)/(y2 - y1);
    ld b = my - m * mx;
    //cout << m << " " << b << "\n";
    ld ans = -1 * b/m;
    return ans;
}
ld dist(ld x1, ld y1, ld x2, ld y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main()
{
    cout << fixed << setprecision(15);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, l; cin >> n >> l;
    vector<pii> points(n);
    for(int i = 0; i < n; i++){
        cin >> points[i].first >> points[i].second;
        points[i].second = abs(points[i].second);
    }
    stack<pair<ll, pair<ld, ld>>> s; 
    s.push({0, {0, l}});
    sort(points.begin(), points.end());
    for(int i = 1; i < n; i++){
        if(points[i].first == points[i - 1].first){
            continue;
        }
        while(s.size()){
            ld curr = -1;
            auto before = s.top();
            if(points[i].second == points[before.ff].second){
                curr = (points[i].first + points[before.ff].first)/2;
            }
            else{
                curr = figure(points[before.ff].ff, points[before.ff].second, points[i].ff, points[i].ss);
            }
            if(curr <= before.ss.ff){
                s.pop();
            }
            else{
                if(curr <= l){
                    s.pop();
                    s.push({before.ff, {before.ss.ff, curr}});
                    s.push({i, {curr, l}});
                }
                break;
            }
        }
        if(s.size() == 0){
            s.push({i, {0, l}});
        }
    }
    ld res = 0;
    while(s.size()){
        auto get = s.top();
        s.pop();
        //cout << get.ff << " " << get.ss.ff << " " << get.ss.ss << "\n";
        res = max(res, dist(points[get.ff].first, points[get.ff].second, get.ss.ff,0));
        res = max(res, dist(points[get.ff].first, points[get.ff].second, get.ss.ss,0));
    }
    res = sqrt(res);
    cout << res << "\n";



}