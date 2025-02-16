using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 105
ll n;
pair<ll, ll> rotate(pair<ll, ll> x)
{
    return make_pair(x.second, n + 1 - x.first);
}
int main()
{
    cin >> n;
    set<pair<ll, ll>> track;
    vector<pair<ll, ll>> curr;
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        for(int j = 1; j <= n; j++){
            if(s[j - 1] == '.'){
                track.insert({i, j});
                curr.push_back({i, j});
            }
        }
    }
    string input; cin >> input;
    string res = "";
    for(int i =1 ; i <= n * n; i++){
        res.push_back('0');
    }
    ll curr_index = 0;
    for(int i = 1; i <= 4; i++){
        sort(curr.begin(), curr.end());
        for(int j = 0; j < curr.size(); j++){
            ll index = (curr[j].first - 1) * n + curr[j].second - 1;
            res[index] = input[curr_index];
            curr_index++;
        }
        for(int j = 0; j < curr.size(); j++){
            curr[j] = rotate(curr[j]);
            track.insert(curr[j]);
        }
    }
    if(track.size() != n * n || curr.size() * 4 > n * n){
        cout << "invalid grille\n";
    }
    else{
        cout << res << "\n";
    }

}
