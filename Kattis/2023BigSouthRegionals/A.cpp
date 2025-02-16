using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005
#define ALPHABETSIZE 

int main()
{
    string s; cin >> s;
    map<char, ll> needs;
    map<char, ll> track;
    needs['A'] = 1; needs['B'] = 1; needs['C'] = 1;
    track['A'] = 0; track['B'] = 0; track['C'] = 0;
    ll res = 1; needs[s[0]]--; track[s[0]]++; 
    for(int i = 1; i < s.size(); i++){
        if(needs[s[i]] > 0){
            needs[s[i]]--; track[s[i]]++; 
            ll curr = track[s[i]];
            bool flag = true;
            for(auto j: track){
                //cout << s[i] << " " << j.first << " " << j.second << "\n";
                if(s[i] != j.first){
                    if(curr > j.second){
                        flag = false;
                    }
                }
            }
            //if(i == 1){ cout << flag << " " << track['C'] << " " << curr << "\n";}
            if(flag){
                needs['A']++; needs['B']++; needs['C']++;
            }

        }
        else{
            res++;
            needs['A']++; needs['B']++; needs['C']++;
            needs[s[i]]--; track[s[i]]++;
        }
    }
    cout << res << "\n";
}