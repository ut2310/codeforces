using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, k; string s;
        cin >> n >> k >> s;
        vector<ll> track;
        ll cnt = 1;
        for(int i = 1; i < n; i++){
            if(s[i] != s[i - 1]){
                track.push_back(cnt);
                cnt = 1;
            }
            else{
                cnt++;
            }
        }
        track.push_back(cnt);
        if(track.size() == 1){
            if(n == k) cout << "1\n";
            else cout << "-1\n";
            continue;
        }
        ll check = 0; ll get = -1; ll index = -1;
        for(int i = 0; i < track.size() - 1; i++){
            if(track[i] != k){
                check++;
                get = track[i];
                index = i;
            }
        }
        //cout << check << " " << get << " " << cnt << "\n";
        if(check == 0){
            if(cnt == k){
                cout << n << "\n";
            }
            else cout << "-1\n";
            continue;
        }
        if((check >= 2) || ((get + cnt) % k != 0) || (cnt > k)){
            cout << "-1\n";
            continue;
        }
        if(cnt == k){
            if(check == 0){
                cout << n << "\n";
            }
            else if(get == 2 * k && (index - (track.size() - 1)) % 2 != 0){
                ll curr = 0;
                for(int i = 0; i < index; i++){
                    curr += track[i];
                }
                cout << curr + k << "\n";
            }
            else{
                cout << "-1\n";
            }
            continue;
        }
        if((index - (track.size() - 1)) % 2 == 0){
            if(cnt + get == k){
                ll ans = 0;
                for(int i = 0; i <= index; i++){
                    ans += track[i];
                }
                cout << ans << "\n";
            }
            else if(cnt + get == 2 * k){
                ll ans = 0;
                for(int i = 0; i < index; i++){
                    ans += track[i];
                }
                ans += (get - k);
                cout << ans << "\n";
            }
            else{
                cout << "-1\n";
            }
            continue;
        }
        cout << "-1\n";



    }
}