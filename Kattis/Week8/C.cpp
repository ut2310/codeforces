using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 105

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n; string s; cin >> s;
        string s1 = s;
        string s2 = "";
        if(s1 == "Alice"){
            s2 = "Bob";
        }
        else{
            s2 = "Alice";
        }
        vector<ll> track; 
        for(ll i = 2; i * i <= n; i++){
            ll cnt = 0;
            while(n % i == 0){
               cnt++;
               n/=i;
            }
            if(cnt) track.push_back(cnt);
            if(n == 1) break;
        }
        // for(auto j: pf){
        //     cout << j.first << " " << j.second << "\n";
        // }
        if(n != 1){
            track.push_back(1);
        }
        if(track.size() >= 3){
            cout << "tie\n";
        }
        else if(track.size() == 2){
            if(track[0] == track[1]){
                cout << s2 << "\n";
            }
            else if(abs(track[0] - track[1]) == 1){
                cout << s1 << "\n";
            }
            else{
                cout << "Tie\n";
            }
        }
        else{
            if(track[0] % 2 != 0){
                cout << s1 << "\n";
            }
            else{
                cout << s2 << "\n";
            }
        }
    }
}