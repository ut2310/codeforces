using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 105
ll get_matching(pair<string, ll> s1, pair<string, ll> s2)
{
    string c1 = s1.first;
    string c2 = s2.first;
    ll res = -1;
    for(int i = 0; i < min(c1.size(), c2.size()); i++){
        if(c1[i] == c2[i]){
            res++;
        }
        else{
            break;
        }
    }
    if(res >= s1.second){
        res--;
    }
    if(s1 > s2){
        res++;
    }
    return res;
}
int main()
{
    ll n; cin >> n;
    vector<pair<string, ll>> arr(n);
    for(int i1 = 0; i1 < n; i1++){
        string s1; string s2; cin >> s1 >> s2;
        string ns1; string ns2;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] < 'a'){
                ns1.push_back(s1[i] + 32);
            }
            else{
                ns1.push_back(s1[i]);
            }
        }
        for(int i = 0; i < s2.size(); i++){
            if(s2[i] < 'a'){
                ns2.push_back(s2[i] + 32);
            }
            else{
                ns2.push_back(s2[i]);
            }
        }
        ns2.append(ns1);
        arr[i1] = {ns2, s2.size()};
    }
    ll addOn = 0;
    ll res = 0;
    for(int i = 0; i < n; i++){
        ll curr = 0;
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            curr = max(curr, get_matching(arr[i], arr[j]));
        }
        cout << curr << "\n";
        res += curr;
    }
    cout << res << "\n";
}