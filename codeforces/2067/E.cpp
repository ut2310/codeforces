using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
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
        vector<ll> a(n);
        vector<ll> matter;
        bool flag = false;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] > 0){
                matter.push_back(a[i]);
            }
            else if(!flag){
                matter.push_back(a[i]);
                flag = true;
            }
        }
        if(!flag){
            cout << matter.size() << "\n";
        }
        else{
            ll n1 = matter.size();
            if(n1 == 1){
                cout << n1 << "\n";
                continue;
            }
            vector<ll> minb(n1);
            minb[0] = matter[0];
            for(int i = 1; i < n1; i++){
                minb[i] = min(minb[i - 1], matter[i]);
            }
            vector<ll> sfxmex(n1); ll mex = 0;
            vector<ll> visited(n + 2);
            for(int i = n1 - 1; i >= 0; i--){
                if(matter[i] <= (n + 1)) visited[matter[i]] = 1;
                while(visited[mex] == 1){
                    mex++;
                }
                sfxmex[i] = mex;
            }
            bool flag = true;
            for(int i = 0; i < n1 - 1; i++){
                if(minb[i] < sfxmex[i + 1]){
                    flag = false;
                }
            }
            if(flag){
                cout << n1 << "\n";
            }
            else{
                cout << (n1 - 1) << "\n";
            }
        }
    }
}