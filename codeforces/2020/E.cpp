using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 
ll n, M;
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
ll modInverse(ll A)
{
    return power(A, M - 2);
}
ll mod(ll a)
{
    if(a % M < 0)
    {
        return M + a % M;
    }
    return a % M;
}
ll expected_value(ll bit, vector<ll> &a, vector<ll> &p)
{
    ll inv = modInverse(10000);
    ll mul1 = 1;
    for(int i = 0; i < n; i++){
        if(a[i] & (1 << bit)){
            //if(bit == 0) cout << i << "hi\n";
            mul1 *= (10000 - 2*p[i]);
            mul1 = mod(mul1);
            mul1 *= inv;
            mul1 = mod(mul1); 
        }
    }
    ll res = (1 - mul1) * modInverse(2);
    res = mod(res);
    return res;
}
ll expected_value_1(ll bit1, ll bit2, vector<ll> &a, vector<ll> &p)
{
    ll inv = modInverse(10000);
    ll mul1 = 1;
    for(int i = 0; i < n; i++){
        if((a[i] & (1 << bit1)) && (a[i] & (1 << bit2))){
            //if(bit == 0) cout << i << "hi\n";
            mul1 *= (10000 - 2*p[i]);
            mul1 = mod(mul1);
            mul1 *= inv;
            mul1 = mod(mul1); 
        }
    }
    ll res = (1 - mul1) * modInverse(2);
    res = mod(res);
    return res;
}
ll expected_value_2(ll bit1, ll bit2, vector<ll> &a, vector<ll> &p)
{
    ll inv = modInverse(10000);
    ll mul1 = 1;
    for(int i = 0; i < n; i++){
        if((a[i] & (1 << bit1)) && !(a[i] & (1 << bit2))){
            //if(bit == 0) cout << i << "hi\n";
            mul1 *= (10000 - 2*p[i]);
            mul1 = mod(mul1);
            mul1 *= inv;
            mul1 = mod(mul1); 
        }
    }
    ll res = (1 - mul1) * modInverse(2);
    res = mod(res);
    return res;
}
ll ev2(ll bit1, ll bit2, vector<ll> &a, vector<ll> &p)
{
    ll f1 = expected_value_1(bit1, bit2, a, p); //bit1 & bit2
    ll f2 = expected_value_2(bit1, bit2, a, p); //only bit1
    ll f3 = expected_value_2(bit2, bit1, a, p); //only bit2
    ll res = f2 * f3;
    res = mod(res);
    res *= (1 - f1);
    res = mod(res);
    ll res2 = (1 - f2) * (1 - f3);
    res2 = mod(res2);
    res2 *= f1;
    res2 = mod(res2);
    ll final_res = res + res2;
    final_res = mod(final_res);
    return final_res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    M = 1000000007;
    ll t; cin >> t;
    vector<ll> pow2(30);
    pow2[0] = 1;
    for(int i = 1; i < 25; i++){
        pow2[i] = pow2[i - 1] * 2;
        pow2[i] = mod(pow2[i]);
    }
    while(t-->0){
        cin >> n;
        vector<ll> a(n);// the numbers 0 - 1023
        vector<ll> p(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> p[i];
        }
        ll res = 0;
        //S is the xor of all the values 
        vector<ll> ev(10);
        for(int i = 0; i <= 9; i++){
            ev[i] = expected_value(i, a, p);
        }
        for(int i = 0; i <= 9; i++){
            for(int j = 0; j <= i; j++){
                if(i == j){
                    ll curr = ev[i];
                    curr = mod(curr);
                    curr *= pow2[2 * i];
                    curr = mod(curr);
                    res += curr;
                    res = mod(res);
                    //cout << i << " " << curr << "\n";
                }
                else{
                    ll curr = ev2(i, j, a, p);
                    curr = mod(curr);
                    curr *= pow2[i + j + 1];
                    curr = mod(curr);
                    res += curr;
                    res = mod(res);
                }
            }
        }
        cout << res << "\n";    
        
    }
}