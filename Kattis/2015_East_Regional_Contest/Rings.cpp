using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 10000005
#define ALPHABETSIZE 26

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m; cin >> n >> m;
    vector<vector<char>> input(n + 2, vector<char> (m + 2));
    vector<vector<ll>> track(n + 2, vector<ll> (m + 2));
    for(int i = 1; i <= n; i++){
        string s; cin >> s;
        for(int j = 0; j < s.size(); j++){
            input[i][j + 1] = s[j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(input[i][j] == '.'){
                track[i][j] = 0;
            }
            else{
                track[i][j] = 1e9;
            }
        }
    }
    ll iter = 1;
    ll cnt = 0;
    while(iter < 105){
        bool flag = true;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(track[i][j] == 1e9){
                    //check if neighbors arent all -1
                    if(track[i][j - 1] >= iter && track[i][j + 1] >= iter && track[i - 1][j] >= iter && track[i + 1][j] >= iter){
                        flag = false;
                    }
                    else{
                        track[i][j] = iter;
                    }
                }
            }
        }
        if(flag){
            break;
        }
        iter++;
    }
    if(iter >= 10){
        for(int i = 1; i <= n; i++){
            string s = "";
            for(int j = 1; j <= m; j++){
                if(track[i][j] == 0){
                    s = s + "...";
                }
                else if(track[i][j] < 10){
                    s = s + ".." + to_string(track[i][j]);
                }
                else{
                    s = s + "." + to_string(track[i][j]);
                }
            }
            cout << s << "\n";
        }
    }
    else{
        for(int i = 1; i <= n; i++){
            string s = "";
            for(int j = 1; j <= m; j++){
                if(track[i][j] == 0){
                    s = s + "..";
                }
                else if(track[i][j] < 10){
                    s = s + "." + to_string(track[i][j]);
                }
            }
            cout << s << "\n";
        }
    }

}