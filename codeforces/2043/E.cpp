#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>
 
using namespace __gnu_pbds;
using namespace std;
 
using ll = long long;
using ld = long double;
 
typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
 
#define mp make_pair
mt19937 rnd(time(0));
 
// 1. Overload the << operator for std::pair
template<typename T1, typename T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
    os << p.first << ' ' << p.second << "|";
    return os;
}
 
// 2. Simple trait to detect if a type is a container
template<typename T, typename = void>
struct is_container : false_type {};
 
// Specialization: If T has begin() and end(), it's a container
template<typename T>
struct is_container<T, void_t<
        decltype(std::declval<T>().begin()),
        decltype(std::declval<T>().end())
>> : true_type {};
 
// 3. Generic print function
template<typename T>
void print(const T& element) {
    if constexpr (is_container<T>::value) {
        for(const auto& e : element) {
            print(e); // Recursive call for nested containers
        }
        cout << endl; // Newline after printing a container
    }
    else {
        cout << element << ' '; // Print non-container elements
    }
}
 
 
//const int MOD = 1'000'000'007;
const int MOD = 998'244'353;
 
int mul(int a, int b) {
    return (1LL * a * b) % MOD;
}
 
int add(int a, int b) {
    int s = (a+b);
    if (s>=MOD) s-=MOD;
    return s;
}
 
int sub(int a, int b) {
    int s = (a+MOD-b);
    if (s>=MOD) s-=MOD;
    return s;
}
 
int po(int a, ll deg)
{
    if (deg==0) return 1;
    if (deg%2==1) return mul(a, po(a, deg-1));
    int t = po(a, deg/2);
    return mul(t, t);
}
 
int inv(int n)
{
    return po(n, MOD-2);
}
 
 
 
 
const int K = 50;
 
vector<vector<int>> gen_C(int n, int k)
{
    vector<vector<int>> ans;
    if (k == 0)
    {
        ans.resize(1);
        return ans;
    }
 
    auto res = gen_C(n-1, k-1);
    for (auto vec: res)
    {
        int lst = -1;
        if (!vec.empty()) lst = vec.back();
        for (int i = lst+1; i<=n; i++)
        {
            vector<int> tmp(vec.begin(), vec.end());
            tmp.push_back(i);
            ans.push_back(tmp);
        }
    }
    return ans;
}
 
void solve()
{
    int n, q; cin>>n>>q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin>>a[i];
 
    vector<vector<int>> pref(K+1, vector<int>(n+1));
    for (int i = 0; i<n; i++)
    {
        for (int j = 0; j<=K; j++) pref[j][i+1] = pref[j][i] + (a[i] == j);
    }
 
    auto get_sum = [&](int l, int r, int val)
    {
        return pref[val][r+1] - pref[val][l];
    };
 
 
    vector<ll> cnts(K+1);
    while (q--)
    {
        int l, r; cin>>l>>r; l--; r--;
        for (int i = 0; i<=K; i++) cnts[i] = get_sum(l, r, i);
 
        int len = r-l+1;
 
        //cout<<"Processing "<<l<<' '<<r<<endl;
 
        //cout<<len<<": "; print(cnts);
 
        if (cnts[0])
        {
            cout<<len-1<<' '<<cnts[0]<<endl;
            continue;
        }
 
        bool can2 = false;
        for (auto it: cnts) if (it>=2) can2 = true;
 
        if (can2)
        {
            ll ans = 0;
            for (auto it: cnts) ans += it*(it-1)/2;
            cout<<len-2<<' '<<ans%MOD<<endl;
            continue;
        }
 
        vector<int> vals;
        for (int i = 0; i<=K; i++) if (cnts[i]) vals.push_back(i);
        int sz = vals.size();
 
        vector<bool> checks(7);
        vector<int> xors(7);
        vector<int> multiplicity(7);
 
        multiplicity[3] = 3;
        multiplicity[4] = 6;
        multiplicity[5] = 10;
        multiplicity[6] = 20;
 
        vector<bool> have2(K+1);
        vector<int> xors2(K+1);
        for (int i = 0; i<sz; i++)
            for (int j = i+1; j<sz; j++)
            {
                int val = vals[i]^vals[j];
 
                if (cnts[val])
                {
                    checks[3] = true;
                    xors[3] = add(xors[3], 1);
                }
 
                if (have2[val])
                {
                    checks[4] = true;
                    xors[4] = add(xors[4], xors2[val]);
                }
 
                xors2[val] = add(xors2[val], 1);
                have2[val] = true;
            }
 
        vector<bool> have3(K+1);
        vector<int> xors3(K+1);
        for (int i = 0; i<sz; i++)
            for (int j = i+1; j<sz; j++)
                for (int k = j+1; k<sz; k++)
                {
                    int val = vals[i]^vals[j]^vals[k];
 
                    if (have2[val])
                    {
                        checks[5] = true;
                        xors[5] = add(xors[5], xors2[val]);
                    }
 
                    if (have3[val])
                    {
                        checks[6] = true;
                        xors[6] = add(xors[6], xors3[val]);
                    }
 
                    xors3[val] = add(xors3[val], 1);
                    have3[val] = true;
                }
 
        bool found = false;
        for (int ans = 3; ans<=6; ans++) if (checks[ans])
        {
            cout<<len-ans<<' '<<mul(xors[ans], inv(multiplicity[ans]))<<endl;
            found = true;
            break;
        }
 
        if (!found) cout<<-1<<endl;
    }
}
 
/*
9 1
0 1 2 1 3 4 5 6 0
3 5
 */
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
 
    int t = 1;  //cin>>t;
    while (t--) solve();
}
