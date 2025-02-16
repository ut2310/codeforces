using namespace std;
#include <bits/stdc++.h>
#define ll long long

vector<vector<ll>> prefixSum2D(vector<vector<ll>> a, ll n, ll m) 
{ 
    vector<vector<ll>> psa(n + 1, vector<ll> (m + 1));
    psa[1][1] = a[0][0]; 
  
    // Filling first row and first column 
    for (int i = 2; i <= m; i++) 
        psa[1][i] = psa[1][i - 1] + a[0][i - 1]; 
    for (int i = 2; i <= n; i++) 
        psa[i][1] = psa[i - 1][1] + a[i - 1][0]; 
  
    // updating the values in the cells 
    // as per the general formula 
    for (int i = 2; i <= n; i++) { 
        for (int j = 2; j <= m; j++) 
  
            // values in the cells of new 
            // array are updated 
            psa[i][j] = psa[i - 1][j] + psa[i][j - 1] 
                        - psa[i - 1][j - 1] + a[i - 1][j - 1]; 
    } 
    // for(int i = 0; i <= n; i++) 
    // { 
    //     for(int j = 0; j <= m; j++) 
    //     { 
    //         cout << psa[i][j] << " "; 
    //     } 
    //     cout << endl; 
    // } 
    return psa;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, m, k; cin >> n >> m >> k;
        vector<vector<ll>> input(n, vector<ll> (m));
        vector<vector<ll>> type(n, vector<ll> (m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> input[i][j];
            }
        }

        for(int i = 0; i < n; i++)
        {
            string s; cin >> s;
            for(int j = 0; j < m; j++)
            {
                ll curr = s[j] - '0';
                type[i][j] = curr;
            }
        }
        ll type0 = 0;
        ll type1 = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(type[i][j] == 0) type0 += input[i][j];
                if(type[i][j] == 1) type1 += input[i][j];
            }
        }
        vector<vector<ll>> ps = prefixSum2D(type,n,m);
        vector<ll> pos;
        for(int i = 0; i <= n - k; i++)
        {
            for(int j = 0; j <= m - k; j++)
            {
                ll num = ps[i + k][j + k] - ps[i][j + k] - ps[i + k][j] + ps[i][j];
                ll diff = abs((k * k - num) - num);
                if(diff!=0) pos.push_back(diff);
                //cerr << num << " " <<  diff << "\n";
            }
        }
        
        ll goal = abs(type0 - type1);
        if(pos.size() >= 1)
        {
            //cout << goal << "\n";
            ll curr = pos[0];
            for(int i = 1; i < pos.size(); i++)
            {
                curr = __gcd(pos[i], curr);
            }
            if(goal % curr == 0)
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
        else
        {
            if(goal == 0) cout << "YES\n";
            else cout << "NO\n";
        }
        


    }
}