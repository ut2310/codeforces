using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, m; cin >> n >> m;
        string s; cin >> s;
        vector<vector<ll>> a(n, vector<ll> (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> a[i][j];
            }
        }
        ll cr = 0; ll cc = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'D'){ //look at row
                ll get = 0;
                for(int i1 = 0; i1 < m; i1++){
                    get += a[cr][i1];
                }
                a[cr][cc] = -1 * get;
                cr++;
            } 
            else{
                ll get = 0;
                for(int i1 = 0; i1 < n; i1++){
                    get += a[i1][cc];
                }
                a[cr][cc] = -1 * get;
                cc++;
            }
        }
        ll get = 0;
        for(int i1 = 0; i1 < n; i1++){
            get += a[i1][m - 1];
        }
        a[n - 1][m - 1] = -1 * get;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}