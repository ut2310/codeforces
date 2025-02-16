using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 105
ll n, m, t, op;
vector<pair<ll, ll>> track;
ll recursum(ll index, ll curr, ll target, vector<vector<ll>> &vic, vector<vector<ll>> &vir){
    if(index == track.size() - 1){
        if(target - curr >= 1 && target - curr <= n){
            if(vic[track[index].second][target - curr] == 0 && vir[track[index].first][target - curr] == 0){
                return 1;
            }
        }
        return 0;
    }
    ll res = 0;
    for(int i = 1; i <= n; i++){
        if(vic[track[index].second][i] == 0 && vir[track[index].first][i] == 0){
            vic[track[index].second][i] = 1;
            vir[track[index].first][i] = 1;
            res += recursum(index + 1, curr + i, target, vic, vir);
            vic[track[index].second][i] = 0;
            vir[track[index].first][i] = 0;
            //cout << index << " " <<  i << " " << res << "\n";
        }
    }
    return res;
}
ll recurmult(ll index, ll curr, ll target, vector<vector<ll>> &vic, vector<vector<ll>> &vir){
    if(index == track.size() - 1){
        if(target >= curr && target <= n * curr){
            if(vic[track[index].second][target/curr] == 0 && vir[track[index].first][target/curr] == 0){
                return 1;
            }
        }
        return 0;
    }
    ll res = 0;
    for(int i = 1; i <= n; i++){
        if(vic[track[index].second][i] == 0 && vir[track[index].first][i] == 0 && (target % (i * curr) == 0)){
            vic[track[index].second][i] = 1;
            vir[track[index].first][i] = 1;
            res += recurmult(index + 1, curr * i, target, vic, vir);
            vic[track[index].second][i] = 0;
            vir[track[index].first][i] = 0;
        }
    }
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char op;
    vector<ll> input;
    cin >> n >> m >> t >> op;
    for(int i = 0; i < 2 * m; i++){
        ll temp; cin >> temp;
        input.push_back(temp);
    }
    for(int i = 1; i < 2 * m; i+=2){
        track.push_back({input[i - 1], input[i]});
    }
    if(op == '-'){
        ll res = 0;
        for(int i =1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(abs(i - j) == t && i!=j){
                    res++;
                }
            }
        }
        cout << res << "\n";
    }
    if(op == '/'){
        ll res = 0;
        for(int i =1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(i % j == 0 && i == j * t){
                    res++;
                }
                else if(j % i == 0 && j == i * t ){
                    res++;
                }
            }
        }
        if(t == 1){
            res = 0;
        }
        cout << res << "\n";
    }
    if(op == '+'){
        vector<vector<ll>> vic(n + 1, vector<ll> (10));
        vector<vector<ll>> vir(n + 1, vector<ll> (10));
        ll res = 0;
        res += recursum(0, 0, t, vic, vir);
        cout << res << "\n";
    }
    if(op == '*'){
        vector<vector<ll>> vic(n + 1, vector<ll> (10));
        vector<vector<ll>> vir(n + 1, vector<ll> (10));
        ll res = 0;
        res += recurmult(0, 1, t, vic, vir);
        cout << res << "\n";
    }
}