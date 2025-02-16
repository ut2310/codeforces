using namespace std;
#include <bits/stdc++.h>
#define ll int
#define MAXN 200005
const ll b = 1800;
bool visited[b + 5][MAXN];
ll pref[MAXN/b + 5][MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll n, q; cin >> n >> q;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= b; i++){
        ll cnt = 0; ll level = 1;
        for(int j = 0; j < n; j++){
            if(a[j] >= level){
                cnt++;
                if(cnt % i == 0) level++;
                visited[i][j] = true;
            }
        }
    }
    for(int i = 1; i <= n/b + 4; i++){
        for(int j = 0; j < n; j++){
            if(a[j] >= i){
                pref[i][j + 1] = pref[i][j] + 1; 
            }
            else{
                pref[i][j + 1] = pref[i][j];
            }
        }
    }
    while(q-->0){
        ll i, x; cin >> i >> x; i--;
        if(x <= b){
            if(visited[x][i])
            {
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
            continue;
        }
        else{
            ll cntlevel = 1;
            ll start = 0; //index 0
            bool flag = false;
            while(!flag){
                ll prev = pref[cntlevel][start];
                ll low = start + 1;
                ll high = n;
                while(low < high){
                    ll mid = (low + high)/2;
                    if(pref[cntlevel][mid] - prev >= x){
                        high = mid;
                    }
                    else{
                        low = mid + 1;
                    }
                }
                ll lookAt = pref[cntlevel][low];
                //interval is from start to low - 1
                if(i >= start && i <= low - 1){
                    if(a[i] >= cntlevel){
                        flag = true;
                    }
                    break;
                }
                if(lookAt - prev < x || low >= n){
                    break;
                }
                if(lookAt - prev == x){
                    start = low;
                    cntlevel++;
                }
            }
            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }

    }
}