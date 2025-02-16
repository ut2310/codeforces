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
void print(vector<ll> &ans){
    for(int i = 0; i < ans.size(); i++){
        if(i < ans.size() - 1) cout << ans[i] << " ";
        else cout << ans[i];
    }
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n, x, y; cin >> n >> x >> y; // x is the time, y is the index
    ll maxdist = max(n - y + 1, y); //y + x - 1 > n --> y + x - 1 
    //1 2 3 4 5 6 7 8 9 10
    if(x > maxdist){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
        if(n - y > y - 1){
            vector<ll> res;
            for(int i = y + (x - 1); i >= y; i--){
                res.push_back(i);
            }
            for(int i = y + x; i <= n; i++){
                res.push_back(i);
            }
            for(int i = y - 1; i >= 1; i--){
                res.push_back(i);
            }
            print(res);
        }
        else{
            vector<ll> res;
            for(int i = y - x + 1; i <= y; i++){
                res.push_back(i);
            }
            for(int i = y + 1; i <= n; i++){
                res.push_back(i);
            }
            for(int i = y - x; i >= 1; i--){
                res.push_back(i);
            }
            print(res);
        }
    }
}