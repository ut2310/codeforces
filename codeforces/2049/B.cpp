using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        string s1; cin >> s1;
        ll lastp = -1; //firstp
        ll lasts = -1;
        for(int i = 0; i < n; i++){
            if(s1[i] == 'p'){
                lastp = i;
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--){
            if(s1[i] == 's'){
                lasts = i;
                break;
            }
        }
        if(lastp == -1 || lasts == -1){
            cout << "YES\n";
        }
        else if(lastp < lasts){
            cout << "NO\n";
        }
        else{
            //can't have a number bigger than lastp + 1
            vector<ll> strack;
            vector<ll> ptrack;
            for(int i = 0; i < n; i++){
                if(s1[i] == 's'){
                    strack.push_back(i);
                }
                else if(s1[i] == 'p'){
                    ptrack.push_back(i);
                }
            }
            ll perm1 = n - strack[strack.size() - 1];
            ll perm2 = ptrack[0] + 1;
            ll share = min(perm1, perm2);
            if(share > ptrack[0] - strack[strack.size() - 1] + 1){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
            
        }
    }
}