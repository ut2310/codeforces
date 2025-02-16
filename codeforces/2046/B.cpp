#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ALPHABETSIZE 26
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        string s; cin >> s;
        map<char, ll> mp;
        for(int i = 0; i < s.size(); i++){
            mp[s[i]]++;
        }
        char lookAt = 'a';
        ll worst = 1e9;
        char mostChar = 'a';
        ll best = 0;
        for(auto j: mp){
            if(j.second < worst){
                lookAt = j.first;
                worst = j.second;
            }
            if(j.second > best){
                mostChar = j.first;
                best = j.second;
            }
        }
        if(lookAt == mostChar){
            for(int i = 0; i < n; i++){
                if(mostChar != s[i]){
                    lookAt = s[i];
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i] == lookAt){
                s[i] = mostChar;
                break;
            }
        }
        cout << s << "\n";
    }
}