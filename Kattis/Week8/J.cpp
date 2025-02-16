using namespace std;
#include <bits/stdc++.h>
#define ll long long
ll r;
pair<double, pair<double, double>> get(ll x1, ll y1, ll x2, ll y2, ll a, ll b)
{
    ll a1 = a*a + b * b;
    ll b1 = 2 * (a * (x1 - x2) + b * (y1 - y2));
    ll c1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) - 4 * r * r;
    //cout << a1 << " " << b1 << " " << c1 << "\n";
    if(b1 * b1 - 4 * a1 * c1 < 0){
        return {-1, {0, 0}};
    }
    if(a1 == 0){
        double res = 1e9;
        double res1 = (double) (-1 * c1) / (double) b1;
        if(res1 <= 0) return {-1, {0, 0}};
        res = res1;
        return {res, {x2 - (x1 + a * res), y2 - (y1 + b * res)}};
    }
    double res1 = (-b1 - sqrt((double) (b1 * b1 - 4 * a1 * c1))) / ((double) (2 * a1));
    double res2 = (-b1 + sqrt((double) (b1 * b1 - 4 * a1 * c1))) / ((double) (2 * a1));
    //cout << res1 << " " << res2 << "\n";
    double res = 1e9; 
    if(res1 <= 0 && res2 <= 0) return {-1, {0, 0}};
    if(res1 > 0) res = min(res, res1);
    if(res2 > 0) res = min(res, res2);
    return {res, {x2 - (x1 + a * res), y2 - (y1 + b * res)}};

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll x1, y1; ll x2, y2; ll x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    ll v1, v2; cin >> v1 >> v2 >> r;
    auto curr = get(x1, y1, x2, y2, v1, v2);
    auto curr2 = get(x1, y1, x3, y3, v1, v2);
    if((curr.first >= 0) && (curr2.first < 0 || curr.first < curr2.first)){
        auto ncurr = get(x2, y2, x3, y3, curr.second.first, curr.second.second);
        if(ncurr.first >= 0){
            cout << "1\n";
        }
        else{
            cout << "3\n";
        }
    }
    else if((curr2.first >= 0) && ((curr.first < 0) || (curr2.first < curr.first))){
        auto ncurr = get(x3, y3, x2, y2, curr2.second.first, curr2.second.second);
        if(ncurr.first >= 0){
            cout << "2\n";
        }
        else{
            cout << "4\n";
        }
    }
    else{
        cout << "5\n";
    }

}