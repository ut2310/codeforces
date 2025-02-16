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
        ll n; cin >> n;
        ll curr = 1;
        for(int i = 1; i <= n; i++){
            while(curr % i != (i - 1)){
                curr++;
            }
            cout << curr << " ";
            curr++;
        }
        cout << "\n";
    }
}