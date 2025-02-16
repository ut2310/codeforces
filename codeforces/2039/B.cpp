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
        string s; cin >> s;
        bool flag = false;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == s[i - 1]){
                cout << s.substr(i - 1, 2) << "\n";
                flag = true;
                break;
            }
        }
        if(flag){
            continue;
        }
        for(int i = 2; i < s.size(); i++){
            if(s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]){
                cout << s.substr(i - 2, 3) << "\n";
                flag = true;
                break;
            }
        }
        if(flag) continue;
        cout << "-1\n";

    }
}