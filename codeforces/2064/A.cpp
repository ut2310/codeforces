using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 10005
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
        string s; cin >> s;
        string s1 = "0" + s;
        ll res = 0;
        //cout << s1 << "\n";
        for(int i = 1; i <= n; i++){
            if(s1[i] != s1[i - 1]) res++;
        }
        cout << res << "\n";
    }
}