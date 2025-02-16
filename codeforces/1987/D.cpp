#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ALPHABETSIZE 26
#define ll long long

int main()
{
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n);
        map<ll, ll> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
        }
        vector<ll> track;
        for(auto j: mp){
            track.push_back(j.first);
        }
        ll usedDays = 0;
        for(int i = 0; i < track.size(); i++){
            for(int j = i; j < track.size(); j++){
                if(mp[track[j]] <= j - usedDays){
                    track.erase(track.begin() + j);
                    usedDays += mp[track[j]];
                    i = j;
                    break;
                }
            }
            cout << usedDays << " ";
            for(auto j: track){
                cout << j << " ";
            }
            cout << "\n";
        }
        cout << track.size() << "\n";
    }
}   