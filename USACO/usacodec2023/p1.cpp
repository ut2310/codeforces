using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 755
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll arr[MAXN][MAXN];
ll visited[MAXN][MAXN];
int main()
{
    ll n; cin >> n;
    for(int i = 1; i < n; i++){
        string s; cin >> s;
        for(int j = i + 1; j <= n; j++){
            arr[i][j] = s[j - i - 1] - '0';
        }
    }
    for(int i = 1; i < n; i++){
        visited[i][i + 1] = arr[i][i + 1];
    }
    for(int i = 2; i <= n - 1; i++){
        for(int l = 1; l + i <= n; l++){
            //l to l + i
            ll parity = 0;
            for(int j = l + 1; j < l + i; j++){
                parity += visited[l][j] * arr[j][l + i];
                parity %= 2;
            }
            if((parity - arr[l][l + i]) % 2 != 0){
                visited[l][l + i] = 1;
            }
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(visited[i][j] == 1){
                //cout << i << " " << j << "\n";
                res++;
            } 
        }
    }
    cout << res << "\n";
}