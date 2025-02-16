using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 5005
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
    ll a, b, c; cin >> a >>b >> c;
    if(a * b == c || b * c == a || a * c == b){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
}