using namespace std;
#include <bits/stdc++.h>
#define ll long long
using Point = pair<ll, ll>;
ll dp[11][30][30], n, d;
vector<pair<ll, ll>> get_points(ll x, ll y)
{
    vector<pair<ll, ll>> points;
    for(int x1 = max(-5LL, x - 5); x1 <= min(n + 5, x + 5); x1++){
        for(int y1 = max(-5LL, y - 5); y1 <= min(n + 5, y + 5); y1++){
            if(((x1 - x) * (x1 - x) + (y1 - y) * (y1 - y)) <= d * d){
                points.push_back(make_pair(x1, y1));
            }
        }
    }
    return points;
    
}
bool isCollinear(Point p, Point q, Point r) {
    return (q.second - p.second) * (r.first - q.first) == (q.first - p.first) * (r.second - q.second);
}
bool isOnSegment(Point p, Point q, Point r) {
    if (isCollinear(p, q, r)) {
        // Check if q lies within the bounding box of the segment
        return (q.first <= max(p.first, r.first) && q.first >= min(p.first, r.first)) &&
               (q.second <= max(p.second, r.second) && q.second >= min(p.second, r.second));
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(true){
        ll m; cin >> n >> d >> m;
        if(n == d && d == m && n == 0){
            break;
        }
        vector<vector<pair<ll, ll>>> moles(11);
        for(int i = 0; i < m; i++){
            ll a, b, c; cin >> a >> b >> c;
            moles[c].push_back(make_pair(a, b));
            
        }

        for(int i = 1; i <= 10; i++){
            vector<pair<ll, ll>> curr = moles[i];
            for(int x = -5; x < n + 5; x++){
                for(int y = -5; y < n + 5; y++){
                    vector<pair<ll, ll>> neighbors = get_points(x, y);
                    for(auto j: neighbors){
                        //j.first, j.second to x and y
                        ll cnt = 0;
                        for(auto j1: curr){
                            //check if j1 is on segment (j.first, j.second) to (x, y)
                            bool flag = isOnSegment(j, j1, make_pair(x, y));
                            if(flag){
                                cnt++;
                            }
                        }
                        dp[i][x + 5][y + 5] = max(dp[i][x + 5][y + 5], dp[i - 1][j.first + 5][j.second + 5] + cnt);
                    }
                    //cout << i << " " << x << " " << y << " " << dp[i][x][y] << "\n";
                }
            }
        }
        ll res = 0;
        for(int i = 0; i <= 10; i++){
            for(int x = 0; x < n + 10; x++){
                for(int y = 0; y < n + 10; y++){
                    res = max(res, dp[i][x][y]);
                    dp[i][x][y] = 0;
                }
            }
        }
        cout << res << "\n";
    }

}