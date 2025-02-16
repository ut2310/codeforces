using namespace std;
#include <bits/stdc++.h>
#define ll long long

int main()
{
    string s; cin >> s;
    double perc; cin >> perc;
    ll n; cin >> n;
    ll cnt = 0;
    for(int i = 0; i < n; i++){
        string s1; cin >> s1;
        if(s1 == "plast"){
            cnt++;
        }
        else{
            string s2; cin >> s2;
        }
    }
    perc = 1 - perc;
    double atleast = (double)cnt/(double) n;
    if(atleast >= perc){
        cout << "Jebb\n";
    }
    else{
        cout << "Neibb\n";
    }
}