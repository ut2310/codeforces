using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 405
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>

int main()
{
    string s; cin >> s;
    string res;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.'){
            res = s.substr(0, i);
        }
    }
    ll ans = stoi(res);
    cout << ans << "\n";
}