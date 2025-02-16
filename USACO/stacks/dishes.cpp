using namespace std;
#include <bits/stdc++.h>
#define ld double
#define ll long long
#define MAXN 305
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long double,long double>
#define vi vector<long double>
#define vii vector<pair<long double,long double>>

bool check(ll num, vector<ll> &a)
{
    vector<ll> b;
    for(int i = 0; i < num; i++){
        b.push_back(a[i]);
    }
    vector<ll> c;
    for(int i = 0; i < num; i++){
        c.push_back(a[i]);
    }
    sort(c.begin(), c.end()); ll p1 = 0;
    ll max = 0;
    deque<vector<ll>> stacks;
    deque<ll> bottom;
    bool flag = true;
    for(int i = 0; i < num; i++){
        //check if this is the smallest one 
        if(b[i] == c[p1]){
            p1++;
            while(stacks.size() > 0){
                while(stacks[0].size() > 0 && stacks[0][stacks[0].size() - 1] == c[p1]){
                    p1++;
                    stacks[0].pop_back();
                }
                if(stacks[0].size() > 0){
                    break;
                }
                else{
                    stacks.pop_front();
                    bottom.pop_front();
                }
            }
            continue;
        }
        auto itr = lower_bound(bottom.begin(), bottom.end(), b[i]);
        if(itr == bottom.end()){
            stacks.push_back({b[i]});
            bottom.push_back(b[i]);
        }
        else{
            ll index = itr - bottom.begin();
            if(b[i] < stacks[index][stacks[index].size() - 1]){
                stacks[index].push_back(b[i]);
            }
            else{
                flag = false;
                break;
            }
        }
        // if(num == 7){
        //     for(auto j: stacks){
        //         for(auto j1: j){
        //             cout << j1 << " ";
        //         }
        //         cout << "\n";
        //     }
        //     cout << "\n\n";
        // }
        
    }
    while(stacks.size() > 0){
        while(stacks[0].size() > 0 && stacks[0][stacks[0].size() - 1] == c[p1]){
            p1++;
            stacks[0].pop_back();
        }
        if(stacks[0].size() > 0){
            break;
        }
        else{
            stacks.pop_front();
            bottom.pop_front();
        }
    }
    // if(num == 7){
    //     for(auto j: stacks){
    //         for(auto j1: j){
    //             cout << j1 << " ";
    //         }
    //         cout << "\n";
    //     }
    //     cout << "\n\n";
    // }
    if(p1 != num) return false;
    return flag;
}
int main()
{
    // freopen("dishes.in","r",stdin);    
    // freopen("dishes.out", "w", stdout);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    ll low = 1;
    ll high = n;
    while(low < high){
        ll mid = (low + high + 1)/2;
        if(check(mid, a)){
            low = mid;
        }
        else{
            high = mid - 1;
        }
    }
    cout << low << "\n";
}