using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 1005   
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t; cin >> t;
    while(t-->0){
        //2x1 + 4y1 = 16
        //x1 + y1 = 5
        //
        ll a, b, c, d, e, f; cin >> a >> d >> b >> e >> c >> f;
        if(a*e - d * b == 0){
            cout << "?\n";
        }
        else{
            ll denom = (b * d - e * a);
            ll first = (c * d - f * a);
            ll second = (f * b - c * e);
            if(first % denom == 0 && second % denom == 0){
                first/=denom;
                second/=denom;
                cout << second << " " << first << "\n";
            }
            else{
                cout << "?\n";
            }
            //ll first = (c * d - f * a)/(b * d - e * a);
            //ll second = (c * e - f * b)/(a * e - d * b);
            
        }
    }
}