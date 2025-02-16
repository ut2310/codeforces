using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<pair<ll, ll>> a;
        map<ll, ll> track;
        vector<ll> track2;
        set<ll> hi;
        for(int i = 0; i < n; i++){
            ll l, r; cin >> l >> r;
            a.push_back({l, r});
            if(r - l + 1 == 1) track[l]++;
            if(r - l + 1 == 1 && hi.count(l) == 0){
                hi.insert(l);
                track2.push_back(l);
            } 
        }
        sort(track2.begin(), track2.end());
        string res;
        //cerr << "HI\n";
        for(int i = 0; i < n; i++){
            if(a[i].ss - a[i].ff == 0){
                if(track[a[i].ff] > 1) res.push_back('0');
                else res.push_back('1');
            }
            else{
                bool flag = true;
                auto i1 = lower_bound(track2.begin(), track2.end(), a[i].ff);
                auto i2 = lower_bound(track2.begin(), track2.end(), a[i].ss);
                if(i2 != track2.end()){
                    if(*i1 == a[i].ff && *i2 == a[i].ss){
                        ll index1 = i1 - track2.begin();
                        ll index2 = i2 - track2.begin();
                        if(index2 - index1 + 1 == a[i].ss - a[i].ff + 1){
                            flag = false;
                        }
                        //cerr << index1 << " " << index2 << " " << *i1 << " " << *i2 << "\n";
                    }
                    //cerr << *i1 << " " << *i2 << "\n";
                }
                //cerr << "hi\n";
                if(flag) res.push_back('1');
                else res.push_back('0');
            }
        }
        cout << res << "\n";
    }
}