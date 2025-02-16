using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
bool check(vector<set<ll>> &fo, ll a1, ll a2)
{
    if(fo[a2].size() > 0 && fo[a1].size() > 0){
        return (*fo[a2].begin() > *fo[a1].begin());
    }
    else{
        if(fo[a1].size() == 0 && fo[a2].size() > 0){
            return false;
        }
        return true;
    }
}
void incr(bool ogflag, bool flag, ll &cnt){
    if(!ogflag && flag){
        cnt++;
    }
    if(ogflag && !flag){
        cnt--;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m, q; cin >> n >> m >> q;
        vector<ll> a(n);
        map<ll, ll> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]] = i;
        }
        vector<ll> b(m);
        vector<set<ll>> fo(n + 1);
        for(int i = 0; i < m; i++){
            cin >> b[i];
            fo[b[i]].insert(i);
        }
        vector<bool> track(n - 1);
        ll cnt = 0;
        for(int i = 1; i < n; i++){
            track[i - 1] = check(fo, a[i - 1], a[i]);
            if(track[i - 1]) cnt++;
        }
        if(cnt == n - 1){
            cout << "ya\n";
        }
        else{
            cout << "tidak\n";
        }
        for(int i = 0; i < q; i++){
            ll s, t; cin >> s >> t;
            ll og = b[s - 1];
            fo[og].erase(s - 1);
            b[s - 1] = t;
            fo[t].insert(s - 1);
            //look at og and t
            if(mp[og] <= n - 2){
                bool ognext = track[mp[og]];
                track[mp[og]] = check(fo, og, a[mp[og] + 1]);
                incr(ognext, track[mp[og]], cnt);
            }
            if(mp[og] >= 1){
                bool ogprev = track[mp[og] - 1];
                track[mp[og] - 1] = check(fo, a[mp[og] - 1], og);
                incr(ogprev, track[mp[og] - 1], cnt);
            }
            if(mp[t] <= n - 2){
                bool newnext = track[mp[t]];
                track[mp[t]] = check(fo, t, a[mp[t] + 1]);
                incr(newnext, track[mp[t]], cnt);
            }
            if(mp[t] >= 1){
                bool newprev = track[mp[t] - 1];
                track[mp[t] - 1] = check(fo, a[mp[t] - 1], t);
                incr(newprev, track[mp[t] - 1], cnt);
            }
            if(cnt == n - 1){
                cout << "ya\n";
            }
            else{
                cout << "tidak\n";
            }
        }
    }
}