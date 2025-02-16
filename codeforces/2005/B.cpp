using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, m, q; cin >> n >> m >> q;
        vector<ll> teachers(m);
        vector<ll> queries(q);
        for(int i = 0; i < m; i++){
            cin >> teachers[i];
        }
        for(int i = 0; i < q; i++){
            cin >> queries[i];
        }
        sort(teachers.begin(), teachers.end());

        for(int i = 0; i < q; i++){
            ll index = lower_bound(teachers.begin(), teachers.end(), queries[i]) - teachers.begin();
            //cout << index << "\n";
            if(index == m){
                cout << n - teachers[index - 1] << "\n"; 
            }
            else if(index == 0){
                cout << teachers[index] - 1  << "\n";
            }
            else{
                //cout << index << " " << queries[i] << "\n";
                ll dist1 = teachers[index] - queries[i];
                ll dist2 = queries[i] - teachers[index - 1];
                ll res = (dist1 + dist2)/2;
                //cout << dist1 << " " << dist2 << "\n";
                cout << res << "\n";
            }

        }
    }
}