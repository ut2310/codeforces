using namespace std;
#include <bits/stdc++.h>
#define ll long long
vector<ll> get_lps(vector<ll> &a) //this gets the longest prefix suffix  for each range 0 - i and returns the vector
{
    ll n = a.size();
    vector<ll> get_lps(n + 1);
    ll len = 0;
    for(int i = 1; i < n; i++){
        if(a[len] == a[i]){using namespace std;
#include <bits/stdc++.h>
#include "ext/pb_ds/assoc_container.hpp"
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
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
    return get_lps;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    return 0;
}