using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 105

int main()
{
    string s; cin >> s;
    bool flag = false;
    for(int i = 1; i < s.size(); i++){
        if(s[i] == 's' && s[i - 1] == 's'){
            flag = true;
        }
    }
    if(flag){
        cout << "hiss\n";
    }
    else{
        cout << "no hiss\n";
    }
}