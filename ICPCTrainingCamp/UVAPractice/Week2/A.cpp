using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 105   
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>

ll arr[505][5];
ll visited[3001];
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n; cin >> n ;

    for(int i = 0; i < 5 * n; i++){
        for(int j = 0; j < 5; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < 5 * n; i++){
        for(int j = ((i/5) + 1) * 5; j < 5 * n; j++){
            vector<ll> overall;
            for (int k = 0; k < 5; k++){
                visited[arr[i][k]] = 1;
                overall.push_back(arr[i][k]);
            }
            bool flag = false;
            vector<ll> pos;
            for(int k = 0; k < 5; k++){
                if(visited[arr[j][k]] == 1){
                    flag = true;
                    pos.push_back(arr[j][k]);
                }
                else{
                    visited[arr[j][k]] = 1;
                    overall.push_back(arr[j][k]);
                }
            }
            
        }
    }
}