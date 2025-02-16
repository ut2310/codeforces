    using namespace std;
    #include <bits/stdc++.h>
    #define ll long long
    #define MAXN 300005
    
    int main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL); 
        ll t; cin >> t;
        while(t-->0)
        {
            ll n; cin >> n;
            vector<ll> a(n);
            set<ll> visited;
            for(int i = 0; i < n; i++)
            {
                cin >> a[i];
                visited.insert(a[i]);
            }
            sort(a.begin(), a.end());
            bool flag = true;
            for(int i = 0; i < n; i++)
            {
                if(a[n - 1] % a[i] != 0) flag = false;
            }
            ll res = 0;
            if(flag)
            {
                set<ll> divisors;
                for(int i = 1; i * i <= a[n - 1]; i++)
                {
                    if(a[n - 1] % i == 0)
                    {
                        divisors.insert(i);
                        divisors.insert(a[n - 1]/i);
                    }
                }
                for(auto i: divisors)
                {
                    ll cnt = 0;
                    ll lcm = 1;
                    for(int j = 0; j < n; j++)
                    {
                        if(i % a[j] == 0)
                        {
                            cnt++;
                            ll temp = __gcd(lcm, a[j]);
                            lcm *= a[j];
                            lcm/=temp;
                        }
                    }
                    if(visited.count(lcm) == 0) res = max(res, cnt);
                }
            }
            else res = n;
            cout << res << "\n";
        }
    }