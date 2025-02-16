using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26

int main()
{
    ll r, m; cin >> r >> m;
    vector<ll> e;
    e.push_back(r);
    ll cmex = 1;
    vector<bool> curr(3e8);
    curr[r] = true;
    if(r == 1){
        cmex = 2;
    }
    ll i = 1;
    while(curr[m] == 0){
        ll last = e[e.size() - 1];
        last += cmex;
        e.push_back(last);
        i++;
        for(int j = 0; j < i - 1; j++){
            if(e[i - 1] - e[j] <= 3e8){
                curr[e[i - 1] - e[j]] = 1;
            }
        }
        curr[e[e.size() - 1]] = 1;
        for(int j = cmex + 1; j < 1e9; j++){
            if(curr[j] == 0){
                cmex = j;
                break;
            }
        }

        // for(int j = 0; j < e.size(); j++){
        //     cout << e[j] << " ";
        // }
        // cout << "\n";
        // for(auto j: curr){
        //     cout << j << " ";
        // }
        // cout << "\n";
    }
    cout << i << "\n";
}