using namespace std;
#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
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
    ll t; cin >>t;
    while(t-->0){
        ll n; cin >> n;
        string s; cin >> s;
        bool flag = false; ll cnt = 0;
        for(int i = 0; i < s.size(); i++){
            cnt += s[i] - '0';
        }
        if(cnt % 2 == 1){
            cout << "-1\n";
            continue;
        }
        //i + 1, i + 2
        vector<ll> indices;
        ll cnt2 = 0;
        for(int i = 0; i < s.size(); i+=2){
            if(s[i] != s[i + 1]){
                if(cnt2 % 2 == 0){
                    if(s[i] == '0'){
                        indices.push_back(i + 1);
                    }
                    else{
                        indices.push_back(i + 2);
                    }
                    cnt2++;
                }
                else{
                    if(s[i] == '1'){
                        indices.push_back(i + 1);
                    }
                    else{
                        indices.push_back(i + 2);
                    }
                    cnt2++;
                }
            }
        }
        cout << indices.size() << " ";
        for(auto j: indices){
            cout << j << " ";
        }
        cout << "\n";
        for(int i = 1; i <= 2 * n; i+=2){
            cout << i << " ";
        }
        cout << "\n";
    }
}