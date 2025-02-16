#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define ALPHABETSIZE 26
#define ll long long

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n; cin >> n;
        vector<ll> a(n);
        ll total = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            total += a[i];
        }
        sort(a.begin(), a.end());
        if(n <= 2){
            cout << "-1\n";
        }
        else{
            ll low = 0;
            ll high = 1e18;
            //n/2 + 1
            while(low < high){
                ll mid = (low + high)/2;
                bool flag = false;
                ll avg = (total + mid)/(2 * n);
                if((total + mid) % (2*n) == 0) avg--;
                //cout << mid << " " << avg << "\n";
                a[n - 1] += mid;
                for(int i = 0; i < n; i++){
                    if(a[i] > avg){
                        if(i > n/2){
                            flag = true;   
                        }
                        break;
                    }
                }
                a[n - 1] -= mid;
                if(flag){
                    high = mid;
                }
                else{
                    low = mid + 1;
                }
            }
            cout << high << "\n";
        }
    }
}