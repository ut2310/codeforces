using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
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
        vector<pair<ll, ll>> deg(n);
        set<pair<ll, ll>> edges;
        for(int i = 0; i < n; i++){
            deg[i].ss = i;
        }
        for(int i = 0; i < n - 1; i++){
            ll a, b; cin >> a >> b;
            edges.insert({min(a - 1, b - 1), max(a - 1, b - 1)});
            deg[a - 1].ff++; deg[b - 1].ff++;
        }
        if(n == 2){
            cout << "0\n";
            continue;
        }
        sort(deg.begin(), deg.end());
        for(int i = 0; i < n; i++){
            //cout << deg[i].ff << " " << deg[i].ss << "hi\n";
        }
        vector<ll> candid1; vector<ll> candid2;
        for(int i = 0; i < n; i++){
            if(deg[i].ff == deg[n - 1].ff){
                candid1.push_back(deg[i].ss);
            }
            //cout << deg[i].ff << " " << deg[n - 2].ff << "\n";
            if(deg[i].ff == deg[n - 2].ff){
                candid2.push_back(deg[i].ss);
            }
        }
        //cout << candid1.size() << " " << candid2.size() << "\n";
        ll cres = deg[n - 1].ff + deg[n - 2].ff - 1;
        bool flag = false;
        for(auto j1: candid1){
            for(auto j2: candid2){
                //cout << j1 << " " << j2 << "hi2\n";
                if(j1 != j2 && edges.count({min(j1, j2), max(j1, j2)}) == 0){
                    flag = true;
                    break;
                }
            }
            if(flag) break;
        }
        if(!flag) cres--;
        cout << cres << "\n";
        
    }
}