using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        string s1, s2; cin >> s1 >> s2;
        ll res = 0;
        ll track = 0;
        s1 = "BB" + s1;
        s2 = "BB" + s2;
        ll last = -1;
        for(int i = 2; i < n + 2; i++){
            if(s1[i] == 'A' && s2[i] == 'A'){
                if(i % 3 == 0){
                    if(s1[i - 1] != 'A' && s2[i - 1] != 'A' && s1[i - 2] != 'A' && s2[i - 2] != 'A'){
                        res += track/2;
                        track = 1;
                    }
                }
                track += 2;
            }
            else if(s1[i] == 'A'){
                if(s1[i - 1] != 'A' && s2[i - 1] != 'A' && s1[i - 2] != 'A'){
                    res += track/2;
                    track = 1;
                }
                else{
                    track++;
                }
            }
            else if(s2[i] == 'A'){
                if(s2[i - 1] != 'A' && s2[i - 2] != 'A' && s1[i - 1] != 'A'){
                    res += track/2;
                    track = 1;
                }
                else{
                    track++;
                }
            }
            
        }
        res += track/2;
        cout << res << "\n";
    }
}