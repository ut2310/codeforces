using namespace std;
#include <bits/stdc++.h>
#define ll long long


int main()
{
    ll w, s; cin >> w >> s;
    ll res = (w - (s) * (s + 1)/2 * 29260)/110;
    cout << res << "\n";
}