#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ALPHABETSIZE 26
#define ll long long

int main()
{
    ll t; cin >> t;
    while(t-->0){
        string s; cin >> s;
        if(s[0] == 1){
            bool flag = true;
            for(int i = 1; i < s.size(); i++){
                if(s[i] != 0) flag = false;
            }
            if(flag){
                string res;
                for(int i = 0; i < s.size() - 2; i++){
                    res.push_back('9');
                }
                cout << res << "\n";
                continue;
            }
        }
        vector<ll> track(10);
        for(int i = 0; i < s.size(); i++){
            track[s[i] - '0']++;
        }
        bool flag = true;
        for(int i = 0; i <= 9; i++){
            if(track[i] % 2 == 1){
                flag = false;
            }
        }
        if(flag){
            cout << s << "\n";
            continue;
        }
        for(int i = s.size() - 1; i >= 0; i--){
            ll off = 0;
            track[s[i] - '0']--;
            for(int j = s[i] - '0'; j )
            for(int j = i; j <= s.size() - 1; j++){

            }
            for(int j = 0; j <= 9; j++){
                if(track[j] % 2 != 0){
                    off++;
                }
            }
            if(off <= ){
                
            }

        }
    }
}