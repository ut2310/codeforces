using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 1000005
#define ALPHABETSIZE 26
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n; cin >> n;
    SieveOfEratosthenes(1000004);
    ll res = 1;
    ll n1 = n;
    for(ll i = 2; i * i <= n1; i++){
        //cout << prime[i] << " " << n << " " << i << "\n";
        if(prime[i] && (n % i == 0)){
            //cout << i << "\n";
            ll curr = i - 1;
            n /= i;
            while(n % i == 0){
                curr *= i;
                n/=i;
            }
            res *= curr;
        }
        if(n == 1){
            break;
        }
    }
    if(n > 1){
        res *= (n - 1);
    }
    cout << res << "\n";

}