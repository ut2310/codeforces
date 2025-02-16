using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        string s; cin >> s;
        ll index = -1;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                index = i; break;
            }
        }
        if(index == -1){
            cout << 1 << " " << s.size() << " " << 1 << " " << 1 << "\n";
        }
        else{
            //string is index - s.size() - 1;
            ll besti = -1;
            ll best = -1;
            vector<pair<string, ll>> numbers;
            for(int i = 0; i < index; i++){
                ll p1 = index;
                string s1 = "";
                for(int j = i; j <= i + s.size() - index - 1; j++){
                    if(s[p1] != s[j]){
                        s1.push_back('1');
                    }
                    else{
                        s1.push_back('0');
                    }
                    p1++;
                }
                numbers.push_back({s1, i});
                // if(i == index - 1){
                //     cout << i << " " << track << " " << value << "\n";
                // }
            }
            sort(numbers.begin(), numbers.end());
            // for(auto x: numbers){
            //     cout << x.first << " " << x.second << "\n";
            // }
            // cout << "\n";
            besti = numbers[numbers.size() - 1].second;
            cout << 1 << " " << s.size() << " " << besti + 1 << " " << besti + s.size() - index << "\n";
        }
    }
}