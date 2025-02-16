#include <string>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdio>
#include <iterator>
#include <cmath>
#include <queue>
#include <climits>
#include <set>
#include <numeric>
#include <map> 
 
using namespace std;
 
#define ll long long
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    ll t; 
    cin >> t;
    while(t-->0) {
        ll n, c; cin >> n >> c;
        vector<ll> a(n+1);
        vector<ll> pref(n+2);
        pref[0] = 0;
        pref[1] = c;
        a[0] = c;
        ll sum = c;
        for(int i = 0; i < n; i++) {
            cin >> a[i+1];
            sum += a[i+1]; 
            pref[i+2] = pref[i+1]+a[i+1];
        }
        /*for(int i = 0; i < n+2; i++) {
            cout << pref[i] << " ";
        }
        cout << "\n";*/
        ll m = a[n];
        vector<ll> suf(n+2);
        suf[n+1] = 0;
        for(int i = n; i > -1; i--) {
            m = max(m, a[i]);
            suf[i] = m;
        }
        m = 0;
        for(int i = 1; i <= n; i++) {
            if(i == 1 && ((a[1] + c) >= suf[i+1])) {
                cout << "0 ";
            } else if((a[i] > m) && (a[i] >= suf[i+1])) {
                cout << "0 ";
            } else {
                if((a[i] + pref[i]) >= suf[i+1]) {
                    cout << (i-1) << " ";
                } else {
                    cout << (i) << " ";
                }
            }
            m = max(m, a[i]+c);
        }
        cout << "\n";
    }
}