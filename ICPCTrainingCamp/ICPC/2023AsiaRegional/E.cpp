using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 405
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll a, b, m;
map<ll, ll> visited;
ll power(ll y)
{
    if (y == 0){
        return 1;
    }
    else if(y == 1){
        return a % m;
    }
    else if(visited.count(y) > 0){
        return visited[y];
    }
    else if(y % 2 == 0){
        ll p = power(y/2) % m;
        visited[y] = ((p * p) - 2) % m;
        return visited[y];
    }
    else{
        ll p1 = power(y/2) % m;
        ll p2 = power(y/2 + 1) % m;
        visited[y] = ((p1 * p2) - a) % m;
        return visited[y];
    }
}
int main()
{
    cin >> a >> b >> m;
    ll res = power(b);
    if(res < 0) res += m;
    cout << res << "\n";
}