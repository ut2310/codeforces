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
ll row[MAXN][MAXN];
ll col[MAXN][MAXN];
ll arr[MAXN][MAXN];
int main()
{
    ll n, k; cin >> n >> k;
    bool flag = true;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            row[i][j] = 1;
        }
        for(int j = 1; j <= n; j++){
            col[i][j] = 1;
        }
    }
    for(int i = 0; i < k; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i + 1][j + 1];
            ll temp = arr[i + 1][j + 1];
            row[temp][i + 1]--;
            col[temp][j + 1]--;
            if(row[temp][i + 1] < 0 || col[temp][j + 1] < 0){
                flag = false;
            }
        }
    }
    if(!flag){
        cout << "no\n";
        return 0;
    }
    for(int i = 1; i <= n; i++){
        for(int r1 = 1; r1 <= n; r1++){
            for(int c1 = 1; c1 <= n; c1++){
                if(row[i][r1] == 1 && col[i][c1] == 1 && arr[r1][c1] == 0){
                    arr[r1][c1] = i;
                    row[i][r1]--;
                    col[i][c1]--;
                }
            }
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