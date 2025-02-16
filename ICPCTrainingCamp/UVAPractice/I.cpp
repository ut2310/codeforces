using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 1005   
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>
ll arr[MAXN][MAXN];
set<ll> col[MAXN];
int main()
{
    ll n, k; cin >> n >> k;
    bool flag = true;
    for(int i = 0; i < k; i++){
        vector<ll> visited(n + 1);
        for(int j = 0; j < n; j++){
            ll temp; cin >> temp;
            arr[i + 1][j + 1] = temp;
            visited[temp]++;
            if(col[j + 1].count(temp) > 0){
                flag = false;
            }
            else{
                col[j + 1].insert(temp);
            }
        }
        for(int i = 1; i<= n; i++){
            if(visited[i] == 0){
                flag = false;
            }

        }
    }
    if(!flag){
        cout << "no\n";
        return 0;
    }
    for(int i = 1; i <= n; i++){
        vector<ll> store;
        for(int j = 1; j <= n; j++){
            if(col[i].count(j) == 0){
                store.push_back(j);
            }
        }
        ll p1 = 0;
        for(int j = k + 1; j <= n; j++){
            arr[j][i] = store[p1];
            p1++;
        }
    }
    cout << "yes\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}