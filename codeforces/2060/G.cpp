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
            vector<ll> a(n); vector<ll> b(n);
            for(int i = 0; i < n; i++){
                cin >> a[i];
            }   
            for(int i = 0; i < n; i++){
                cin >> b[i];
            }
            vector<pair<ll, ll>> track;
            for(int i = 0; i < n; i++){
                track.push_back({a[i], b[i]});
            }
            sort(track.begin(), track.end(), [] (const pair<ll, ll> &a1, const pair<ll, ll> &a2){
                return (a1.ff + a1.ss) < (a2.ff + a2.ss);
            });
            for(auto j: track){
                //cout << j.ff << " " << j.ss << "\n";
            }
            bool flag = true; bool flag2 = false;
            if(max(track[0].ff, track[0].ss) < min(track[1].ff, track[1].ss)){
                flag2 = true;
            }
            for(int i = 1; i < n; i++){
                //cout << min(track[i].ff, track[i].ss) << " " << max(track[i - 1].ff, track[i - 1].ss) << "\n";
                if(min(track[i].ff, track[i].ss) > max(track[i - 1].ff, track[i - 1].ss)){
                    if(i < n - 1){
                        if(max(track[i].ff, track[i].ss) < min(track[i + 1].ff, track[i + 1].ss)){
                            flag2 = true;
                        }
                    }
                    else{
                        flag2 = true;
                    }
                }
                if(min(track[i].ff, track[i].ss) < min(track[i - 1].ff, track[i - 1].ss)){
                    flag = false;
                }
                if(max(track[i].ff, track[i].ss) < max(track[i - 1].ff, track[i - 1].ss)){
                    flag = false;
                }
            }
            if(!flag){
                cout << "NO\n";
                continue;
            }
            else if(flag2){
                cout << "YES\n";
            }
            else{
                ll cnt = 0; 
                if(track[0].ff != min(track[0].ff, track[0].ss)) cnt++;
                ll total = 1; bool flag3 = false;
                for(int i = 1; i < n; i++){
                    if(min(track[i].ff, track[i].ss) > max(track[i - 1].ff, track[i - 1].ss)){
                        if(total % 2 != 0){
                            flag3 = true;
                        }
                        total = 1;
                    }
                    else{
                        total++;
                    }
                    if(track[i].ff != min(track[i].ff, track[i].ss)){
                        cnt++;
                    }
                }
                if(total % 2 == 1) flag3 = true;
                if(cnt % 2 == 0 || flag3) cout << "YES\n";
                else cout << "NO\n";
            }
        }
    }