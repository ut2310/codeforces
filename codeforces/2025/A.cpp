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
        string s1, s2; cin >> s1 >> s2;
        ll cnt = 0;
        for(int i = 0; i < min(s1.size(), s2.size()); i++){
            if(s1[i] == s2[i]){
                cnt++;
            }
            else{
                break;
            }
        }
        ll res = s1.size() + s2.size() - max(0LL, (cnt - 1));
        cout << res << "\n";
        
    }
}