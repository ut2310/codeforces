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
        string res = "";
        vector<char> s = {'a', 'e', 'i', 'o', 'u'};
        ll rem = (n + 5)%5;
        vector<ll> track;
        for(int i = 0; i < 5; i++){
            ll curr = n/5;
            if(rem > 0){
                rem--;
                curr++;
            }
            track.push_back(curr);
        }
        
        for(int i = 0; i < 5; i++){
            for(int j = 0; j < track[i]; j++){
                res.push_back(s[i]);
            }
        }
        cout << res << "\n";
    }
}