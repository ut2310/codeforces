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
    ll res = 0;
    for(int i = 0; i < s.size() - 3; i++){
        string s1 = s.substr(i, 4);
        //cout << s1 << "\n";
        if(s1 == "kick"){
            res++;
        }
    }
    cout << res << "\n";
}