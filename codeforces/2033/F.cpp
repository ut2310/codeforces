using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
bool prime[MAXN];
ll M;
ll lcm(ll a, ll b) {
    return (std::abs(a * b) / gcd(a, b)) % M;
}

ll lcm_of_vector(vector<ll>& vec) {
    if (vec.empty()) return 0; // Handle empty vector case
    int result = vec[0];
    for (size_t i = 1; i < vec.size(); ++i) {
        result = lcm(result, vec[i]);
        result %= M;
    }
    return result;
}
void SieveOfEratosthenes(int n, vector<ll> &primes)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
    {
        if (prime[p])
            primes.push_back(p);
    }
}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<ll> primes;
    SieveOfEratosthenes(100004, primes);
    vector<ll> fib(1e6 + 5);
    vector<ll> dp(1e5 + 5);
    M = 1e9 + 7;
    fib[1] = 1; fib[2] = 1;
    // // for(int i = 0; i < 10; i++){
    // //     cerr << primes[i] << " ";
    // // }
    // // cerr << "\n";
    // M = 1e9 + 7;
    // fib[1] = 1; fib[2] = 1;
    // for(int i = 2; i <= 1e5; i++){
    //     map<int, int> fact;
    //     ll temp = i;
    //     for(int j = 0; j < primes.size(); j++){
    //         ll cnt = 0;
    //         while(temp % primes[j] == 0){
    //             temp /= primes[j];
    //             cnt++;
    //         }
    //         if(cnt > 0){
    //             fact[primes[j]] = cnt;
    //         }
    //         if(temp == 1){
    //             break;
    //         }
    //     }
    //     // cerr << "HELLO\n";
    //     // for(auto j: fact){
    //     //     cerr << j.first << " " << j.second << "\n";
    //     // }
    //     if(fact.size() == 1){
            
    //         ll j = 3;
    //         fib[j] = 2; fib[j] %= i;
    //         //cerr << "chicken " << (fib[j] % i) << "\n"; ;
    //         while(fib[j] != 0){
    //             j++;
    //             fib[j] = fib[j - 1] + fib[j - 2];
    //             fib[j] %= i;
    //         }
    //         dp[i] = j;
    //         //cerr << "chicken\n";
    //         //cerr << dp[i] << " " << j << "\n";
    //     }
    //     else{
    //         vector<ll> e;
    //         for(auto itr: fact){
    //             //itr.first is the prime, itr.second is count;
    //             e.push_back(dp[pow(itr.first, itr.second)]);
    //         }
    //         dp[i] = lcm_of_vector(e);
    //     }
    //     // if(i <= 10){
    //     //     cerr << dp[i] << " ";
    //     // }
    // }
    ll t; cin >> t;
    while(t-->0){
        ll n, k; cin >> n >> k;
        if(k == 1){
            n %= M;
            if(n < 0){
                n += M;
            }
            cout << n << "\n";
        }
        else{
            map<int, int> fact;
            ll temp = k;
            for(int j = 0; j < primes.size(); j++){
                ll cnt = 0;
                while(temp % primes[j] == 0){
                    temp /= primes[j];
                    cnt++;
                }
                if(cnt > 0){
                    fact[primes[j]] = cnt;
                }
                if(temp == 1){
                    break;
                }
            }
            // cerr << "HELLO\n";
            // for(auto j: fact){
            //     cerr << j.first << " " << j.second << "\n";
            // }
            vector<ll> e;
            for(auto itr: fact){
                //itr.first is the prime, itr.second is count;
                ll num = pow(itr.first, itr.second);
                ll j = 3;
                fib[j] = 2; fib[j] %= num;
                //cerr << "chicken " << (fib[j] % i) << "\n"; ;
                while(fib[j] != 0){
                    j++;
                    fib[j] = fib[j - 1] + fib[j - 2];
                    fib[j] %= num;
                }
                dp[num] = j;
                e.push_back(dp[pow(itr.first, itr.second)]);
            }
            dp[k] = lcm_of_vector(e);
            n%=M;
            ll res = dp[k] * n;
            res %= M;
            if(res < 0){
                res += M;
            }
            cout << res << "\n";

        }
    }
}