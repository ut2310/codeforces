using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        ll a, b, c;
        cout << 1 << " " << "1" << endl;  cin >> a;
        cout << 1 << " " << "11" << endl; cin >> b;
        cout << 1 << " " << "10" << endl; cin >> c;
        if(c == (a - b)){
            cout << 0 << " " << n << " " << "0" << endl;
            
        } 
        else{
            cout << 0 << " " << n << " " << "1" << endl;
        }
        cin >> n;
    }
}