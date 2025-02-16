#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ALPHABETSIZE 26
#define ll long long
pair<ll, ll> check(vector<ll> &a, vector<ll> &b){
    ll first = -1;
    ll second = -1;
    for(int i = 1; i <= 9; i++){
        if(a[i] > b[i]){
            first = i;
        }
        if(a[i] < b[i]){
            second = i;
        }
    }
    return {first, second};
}
int main()
{
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> types(10);
        for(int i = 0; i < n; i++){
            ll x; cin >> x;
            types[x]++;
        }
        cout << "- 0" << endl;
        cout.flush();
        vector<ll> types2(10);
        vector<ll> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i]; types2[a[i]]++;
        }
        auto get = check(types, types2);
        while(get.first == -1 && get.second == -1){
            cout << "- 0" << endl;
            cout.flush();
            for(int i = 1; i <= 9; i++){
                types2[i] = 0;
            }
            for(int i = 0; i < n; i++){
                cin >> a[i]; types2[a[i]]++;
            }
            get = check(types, types2);
        }
        vector<ll> remove; //we know the mimic is now second, so remove everything thats not second
        for(int i = 0; i < n; i++){
            if(a[i] != get.second){
                remove.push_back(i + 1);
            }
        }
        cout << "- " << remove.size() << " ";
        for(int i = 0; i < remove.size(); i++){
            cout << remove[i] << " ";
        }
        cout.flush();
        while(true){
            ll new_size = n - remove.size();
            for(int i = 0; i < new_size; i++){
                cin >> a[i]; 
            }
            ll index = -1; 
            for(int i = 0; i < new_size; i++){
                if(a[i] != get.second){
                    index = i + 1;
                }
            }
            if(index != -1){
                cout << "! " << index;
                cout.flush();
                break;
            }
            else{
                cout << "- 0";
                cout.flush();
            }
        }
        
    }
}