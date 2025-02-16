using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 

int main()
{
    ll s; cin >> s;
    set<ll> store;
    ll curr = 0;
    for(int i = 1; i <= 9; i++){
        curr *= 10;
        curr += i;
        store.insert(curr);
    }
    if(store.count(s) > 0){
        cout << to_string(s).size() << "\n";
    }
    else{
        cout << "-1\n";
    }

}