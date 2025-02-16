using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, q; cin >> n >> q;
        for(int i = 0; i < n - 1; i++){
            ll x; cin >> x;
        }
        //checks is for each nonleaf node check if a proper child is after it and check differences
        vector<ll> a(n); vector<ll> pos(n + 1);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            pos[a[i]] = i;
        }
        vector<ll> diff(n + 1);//check differences of 2, 4, 6, ...,
        vector<ll> bad;
        for(int i = 2; i < n; i+=2){
            diff[i] = abs(pos[i] - pos[i + 1]);

        } 
        for(int i = 0; i < q; i++){
            ll n1, n2; cin >> n1 >> n2;
            //swap(a.begin()+n1, a.begin() + n2);
        }
    }
}