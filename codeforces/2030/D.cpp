using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n, q; cin >> n >> q;
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
        }
        //2 3 1 5 4
        set<ll> pos;
        ll min_removed = a[n - 1];
        for(int i = n - 2; i >= 1; i--){
            //cout << min_removed << " " << i - 1 << "\n";
            if(min_removed > i){
                pos.insert(i);
            }
            min_removed = min(a[i], min_removed);   
        }
        string s; cin >> s;
        set<ll> cp;
        ll count = 0;
        for(int i = 1; i < n - 1; i++){ 
            if(s[i] == 'L' && s[i + 1] == 'R'){
                //nothing exists from i to i + 1
                //i is an endpoint
                cp.insert(i);
                if(pos.count(i) == 0){
                    count++;
                }
            }
        }


        //endpoints of comp stored in s
        // for(auto j: pos){
        //     cout << j << " ";
        // }
        // cout << "\n\n";
        for(int i = 0; i < q; i++){
            ll index; cin >> index;
            index--;
            
            if(s[index] == 'L'){
                s[index] = 'R';
                if(cp.count(index) > 0){
                    cp.erase(index);
                    if(pos.count(index) == 0){
                        count--;
                    }
                }
                //before covering index and index - 1, make sure index - 1 is a right or else nothing between index - 1 & index
                if(s[index - 1] != 'R'){
                    cp.insert(index - 1);
                    if(pos.count(index - 1) == 0){
                        count++;
                    }
                }
            }
            else{
                s[index] = 'L';
                if(cp.count(index - 1) > 0){
                    cp.erase(index - 1);
                    if(pos.count(index - 1) == 0){
                        count--;
                    }
                }
                //before covering index and index + 1
                if(s[index + 1] != 'L'){
                    cp.insert(index);
                    if(pos.count(index) == 0){
                        count++;
                    }
                }
            } 
            // for(auto j: cp){
            //     cout << j << " ";
            // }
            // cout << "\n";
            if(count == 0){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }
}