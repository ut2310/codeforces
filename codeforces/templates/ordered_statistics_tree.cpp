#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> p(n + 1);
    vector<ll> res(n + 1);
    ordered_set os;
    for(int i = 1; i <= n; i++){
        cin >> p[i];
        os.insert(i);
    }
    for(int i = n; i >= 1; i--){
        ll it = *os.find_by_order(p[i] - 1);
        os.erase(it);
        res[it] = i;
    }
    for(int i = 1; i<= n; i++){
        cout << res[i] << " ";
    }
    cout << "\n";
}