using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 45
ll store[MAXN][MAXN], h, w;
ll dfs(ll i, ll j, ll fi, ll fj, vector<ll> &visited, ll track)
{
    if(visited[store[i][j]] == 1){
        return -1;
    }
    visited[store[i][j]] = 1;
    if(i == fi && j == fj){
        return track;
    }
    ll dest = store[fi][fj];
    ll curr = store[i][j];
    ll curr1 = 1e9;
    ll curr2 = 1e9;
    ll cx = 0; ll cy = 0;
    for(int x = -1; x <= 1; x+=2){
        if(i + x >= 1 && i + x <= h){
            if((abs(dest - store[i + x][j]) < curr1) || (abs(dest - store[i + x][j]) == curr1 && abs(curr - store[i + x][j]) < curr2)){
                cx = i + x; cy = j;
                curr1 = abs(dest - store[i + x][j]);
                curr2 = abs(curr - store[i + x][j]);
            }
        }
    }
    for(int y = -1; y <= 1; y+=2){
        if(j + y >= 1 && j + y <= w){
            if((abs(dest - store[i][j + y]) < curr1) || (abs(dest - store[i][j + y]) == curr1 && abs(curr - store[i][j + y]) < curr2)){
                cx = i; cy = j + y;
                curr1 = abs(dest - store[i][j + y]);
                curr2 = abs(curr - store[i][j + y]);
            }
        }
    }
    return dfs(cx, cy, fi, fj, visited, track + 1);
    
    
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> h >> w;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> store[i][j];
        }
    }
    ll o_res = 1e9;
    ll res1 = -1;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            ll cnt = 0;
            bool flag = true;
            ll res = 0;
            for(int i1 = 1; i1 <= h; i1++){
                for(int j1 = 1; j1 <= w; j1++){
                    vector<ll> visited(h * w + 1);
                    ll get = dfs(i, j, i1, j1, visited, 0);
                    res = max(res, get);
                    if(get == -1){
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
            }
            if(flag){
                if(res < o_res){
                    o_res = res;
                    res1 = store[i][j];
                }
            }
        }
    }
    if(o_res == 1e9){
        cout << "impossible\n";
    }
    else{
        cout << res1 << " " << o_res << "\n";
    }
}