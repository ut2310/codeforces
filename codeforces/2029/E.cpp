using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 400005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
bool prime[MAXN];
void SieveOfEratosthenes(int n)
{
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}
int main()
{
    SieveOfEratosthenes(400004);
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0){
        ll n; cin >> n;
        vector<ll> a(n); ll cnt = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(prime[a[i]]){
                cnt++;
            }
        }
        sort(a.begin(), a.end());
        if(cnt >= 2){
            cout << "-1\n";
        }
        else if(cnt == 0 ||(cnt == 1 && a[0] == 2)){
            cout << "2\n";
        }
        else{
            
            if(prime[a[0]]){
                bool flag = true;
                for(int i = 1; i < n; i++){
                    if(a[i] % a[0] == 0 || (a[i] % 2 == 0 && ((a[i] - 2) >= 2 * a[0]))){
                        continue;
                    }
                    for(int j = 3; j * j <= a[i]; j+=2){
                        if(a[i] % j == 0){
                            a[i] -= j;
                            break;
                        }
                        if(a[i] - j < 2 * a[0]){
                            flag = false;
                            break;
                        }
                    }
                    if(a[i] < 2 * a[0]){
                        flag = false;
                    }
                }
                if(flag){
                    cout << a[0] << "\n";
                }
                else{
                    cout << "-1\n";
                }
            }
            else{
                cout << "-1\n";
            }
        }
        sort(a.begin(), a.end());
        
    }
}