using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
void query(ll l, ll r){
    cout << "? " << l << " " << r << endl;
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        ll o1, o2, o3; 
        query(1, n/4);
        cin >> o1;
        query(n/4 + 1, n/2);
        cin >> o2;
        query(1, n/2);
        cin >> o3;
        if(o1 == o2){
            if(o3 == 0){
                ll low = n/2 + 1;
                ll high = n;
                while(low < high){
                    ll mid = (low + high)/2;
                    ll o; query(n - mid + 1, n);
                    cin >> o;
                    if(o == 1){
                        low = mid + 1;
                    }
                    else{
                        high = mid;
                    }
                }
                cout << "! " << low << endl;
            }
            else{
                ll low = 1;
                ll high = n/2;
                while(low < high){
                    ll mid = (low + high)/2;
                    ll o; query(1, mid);
                    cin >> o;
                    if(o == 1){
                        high = mid;
                    }
                    else{
                        low = mid + 1;
                    }
                }
                cout << "! " << low << endl;
            }
        }
        else{
            if(o3 == 0){
                // k <= n/2
                ll low = 1;
                ll high = n/2;
                while(low < high){
                    ll mid = (low + high)/2;
                    ll o; query(n/2 + 1, n/2 + mid);
                    cin >> o;
                    if(o == 1){
                        high = mid;
                    }
                    else{
                        low = mid + 1;
                    }
                }
                cout << "! " << low << endl;
            }
            else{
                ll low = n/2 + 1;
                ll high = n;
                while(low < high){
                    ll mid = (low + high)/2;
                    ll o; query(1, mid);
                    cin >> o;
                    if(o == 1){
                        low = mid + 1;
                    }
                    else{
                        high = mid;
                    }
                }
                cout << "! " << low << endl;
            }
        }
    }
}