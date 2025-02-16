using namespace std;
#include <bits/stdc++.h>
#define ll long long
ll get_lps(vector<ll> &a)
{
    ll n = a.size();
    vector<ll> get_lps(n + 1);
    ll len = 0;
    for(int i = 1; i < n; i++){
        if(a[len] == a[i]){
            get_lps[i + 1] = len + 1;
            len++;
        }
        else{
            while(len > 0){
                len = get_lps[len];
                if(a[len] == a[i]){
                    get_lps[i + 1] = len + 1;
                    len++;
                    break;
                }
            }
        }
        //cout << i + 1 << " " << len << " " << get_lps[i + 1] << "\n";
    }
    return get_lps[n];
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    vector<ll> c1; vector<ll> c2;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        c1.push_back(a[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        c2.push_back(b[i]);
    }
    for(int i = 0; i < n; i++){
        c1.push_back(b[i]);
        c2.push_back(a[i]);
    }
    ll res1 = get_lps(c1);
    ll res2 = get_lps(c2);
    if(res1 + res2 >= n){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
    
    

}