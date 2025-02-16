#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, m; cin >> n >> m;
        vector<vector<char>> arr(n, vector<char> (m));
        for(int i = 0; i < n; i++)
        {
            string s; cin >> s;
            for(int j = 0; j < m; j++)
            {
                arr[i][j] = s.at(j);
            }
        }
        if(m == 1 && n == 1) cout << "YES\n";
        else if(m == 1)
        {
            if(arr[0][0] == arr[n - 1][0]) cout << "YES\n";
            else cout << "NO\n";
        }
        else if(n == 1)
        {
            if(arr[0][0] == arr[0][m - 1]) cout << "YES\n";
            else cout << "NO\n";
        }
        else
        {
            bool flag = true;
            bool flag2 = true;
            bool flag3 = true;
            for(int i = 1; i < m; i++)
            {
                if(arr[0][i] != arr[0][i - 1])
                {
                    //cout << arr[0][i] << " " << arr[0][i - 1] << "\n";
                    flag2 = false;
                }
                if(arr[n - 1][i] != arr[n - 1][i - 1])
                {
                    flag3 = false;
                }
            }
            //cout << flag2 << " " << flag3 << "\n";
            if(flag2 && flag3 && arr[0][0] != arr[n - 1][0])
            {
                flag = false;
            }
            flag2 = true;
            flag3 = true;
            for(int i = 1; i < n; i++)
            {
                if(arr[i][0] != arr[i - 1][0])
                {
                    flag2 = false;
                }
                if(arr[i][m - 1] != arr[i - 1][m - 1])
                {
                    flag3 = false;
                }
            }
            if(flag2 && flag3 && arr[0][0] != arr[0][m - 1])
            {
                flag = false;
            }
            if(flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}