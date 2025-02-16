using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 51
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
        string s1, s2; cin >> s1 >> s2;
        ll cnt1 = 0; ll cnt2 = 0;
        if(s1[0] != s2[0] || s1[n - 1] != s2[n - 1]){
            cout << "-1\n";
            continue;
        }
        for(int i = 0; i < n - 1; i++){
            if(s1[i] != s1[i + 1]) cnt1++;
            if(s2[i] != s2[i + 1]) cnt2++;
        }
        //cout << cnt1 << " " << cnt2 << "\n";
        if(cnt1 != cnt2){
            cout << "-1\n";
            continue;
        }
        vector<ll> pos1;
        vector<ll> pos2;
        for(int i = 1; i < n; i++){
            if(s1[i] != s1[i - 1]){
                pos1.push_back(i);
            }
            if(s2[i] != s2[i - 1]){
                pos2.push_back(i);
            }
        }
        ll res = 0;
        for(int i = 0; i < pos1.size(); i++){
            res += abs(pos1[i] - pos2[i]);
        }
        cout << res << "\n";
        // }
        // //cout << "HI\n";
        // bool flag = false;
        // for(int i = 1; i < n; i++){
        //     if((s1[i] != s1[i - 1]) && (s2[i] == s2[i - 1])){
        //         flag = true;
        //         break;
        //     }
        //     if((s1[i] == s1[i - 1]) && (s2[i] != s2[i - 1])){
        //         break;
        //     }
        // }
        // if(flag){
        //     swap(s1, s2);
        // }
        // set<ll> zeroes;
        // set<ll> ones;
        // for(int i = 0; i < n - 1; i++){
        //     if(s1[i] != s1[i + 1] && s1[i + 1] == '0'){
        //         zeroes.insert(i + 1);
        //     }
        //     if(s1[i] != s1[i + 1] && s1[i + 1] == '1'){
        //         ones.insert(i + 1);
        //     }
        // }
        // char curr = s1[1];
        // ll res = 0;
        // ll upTo = -1; char track = '0';
        // for(int i = 1; i < n - 1; i++){
        //     if(s2[i] != curr){
        //         if(s2[i] == '1'){
        //             res += (*ones.upper_bound(i)) - i;
        //             upTo = *ones.upper_bound(i);
        //             track = '1';
        //         }
        //         else{
        //             res += (*zeroes.upper_bound(i)) - i;
        //             upTo = *zeroes.upper_bound(i);
        //             track = '0';
        //             //cout << *zeroes.upper_bound(i) << " " << i << "\n";
        //         }
        //         curr = s2[i];
        //     }
        //     else{
        //         if(i < upTo){
        //             curr = track;
        //         }
        //         else{
        //             curr = s1[i + 1];
        //         }
        //     }
        // }
        // cout << res << "\n";

    }
}