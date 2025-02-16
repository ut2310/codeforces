// using namespace std;
// #include <bits/stdc++.h>
// #define ll long long
// #define MAXN 5005
// #define ALPHABETSIZE 26
// #define ff first
// #define ss second
// #define pii pair<long long,long long>
// #define vi vector<long long>
// #define vii vector<pair<long long,long long>>

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);
//     ll t; cin >> t;
//     while(t-->0){
//         ll n, m, k; cin >> n  >> m >> k;
//         map<ll, ll> mp;
//         vector<pair<ll, ll>> a(n);
//         ll track = 0;
//         for(int i = 0; i < n; i++){
//             ll temp1, temp2; cin >> temp1 >> temp2;
//             track += temp2;
//             mp[temp1] = track;
//         }
//         deque<pair<ll, ll>> sim;
//         ll track_day  = 0; ll get = 0;
//         for(auto j: mp){
//             ll day_num = j.ff; ll amt = j.ss;
//             while(sim.size() > 0 && track_day < day_num){
//                 ll d = sim.front().ff;
//                 ll x = sim.front().ss;
//                 if(d + k - 1 < track_day) continue;
//                 else if(d > track_day){
//                     track_day = d;
//                     get = 0;
//                 }
//                 if(n - get > )
//                 if(k + sim.front())
//             }
//             if(p1 < n && a[p1].ss == i){
//                 sim.push_back({a[p1].ff, a[p1].ss});
//                 p1++;
//             }
//             ll curr = 0;
//             while(sim.size() > 0){
//                 if(sim[sim.size() - 1].ff + k <= i){
//                     sim.clear();
//                 }
//                 else if(curr > m){
//                     break;
//                 }
//                 else{
//                     while(sim.size() > 0 && m - curr > sim[sim.size() - 1].ss && sim[sim.size() - 1].ff + k > i){
//                         curr += sim[sim.size() - 1].ss;
//                         sim.pop_back();
//                     }
//                     if(sim.size() == 0){
//                         continue;
//                     } 
//                     if(sim[sim.size() - 1].ff + k <= i){
//                         sim.clear();
//                     }
//                     else if(m - curr <= sim[sim.size() - 1].ss){
//                         ll get1 = sim[sim.size() - 1].ff;
//                         ll get2 = sim[sim.size() - 1].ss - (m - curr);
//                         curr = m;
//                         sim.pop_back();
//                         sim.push_back({get1, get2});
//                         res++;
//                     }
//                 }
//             }
//         }
//         cout << res << "\n";        
//     }
// }