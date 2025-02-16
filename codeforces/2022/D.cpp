using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005

int main()
{
    ll t; cin >> t;
    ll cnt = 0;
    while(t-->0){
        ll n; cin >> n;
        cnt++;
        if(cnt == 2 && n != 4){
            cout << n << "\n";
        }
        vector<ll> color(n + 1);
        bool flag = true;
        for(int i = 1; i <= n/3; i++){
            //3 * i, 3 * i - 1, 3 * i - 2
            ll ans1, ans2, ans3;
            color[3*i] = 1;
            cout << "? " << 3*i << " " << 3*i - 1 << "\n";
            cout.flush();
            cin >> ans1;
            color[3*i - 1] =  abs((1 - ans1) - color[3*i]); //switch if ans1 is 0
            cout << "? " << 3*i - 1 << " " << 3*i - 2 << "\n";
            cout.flush();
            cin >> ans2;
            color[3*i - 2] = abs((1 - ans2) - color[3*i - 1]);
            cout << "? " << 3*i - 2 << " " << 3*i << "\n";
            cout.flush();
            cin >> ans3;
            ll temp = abs((1 - ans3) - color[3*i - 2]);
            if(temp != color[3 * i]){
                ll ans4, ans5;
                cout << "? " << 3*i - 1 << " " << 3*i << "\n";
                cout.flush(); cin >> ans4;
                cout << "? " << 3*i - 2 << " " << 3*i - 1 << "\n";
                cout.flush(); cin >> ans5;
                if(ans4 != ans1 && ans5 != ans2){
                    cout << "! " << 3*i - 1 << "\n";
                }
                else if(ans4 != ans1){
                    cout << "! " << 3*i << "\n";
                }
                else if(ans5 != ans2){
                    cout << "! " << 3*i - 2 << "\n";
                }
                cout.flush();
                flag = false;
            }
        }
        if(flag){
            if(n % 3 == 1){
                cout << "! " << n << "\n";
                cout.flush();
            }
            else{
                ll ans4, ans5;
                cout << "? " << n << " " << n - 2 << "\n";
                cout.flush(); cin >> ans4;
                cout << "? " << n - 2 << " " << n << "\n";
                cout.flush(); cin >> ans5;
                if(ans4 != ans5){
                    cout << "! " << n << "\n";
                    cout.flush();
                }
                else{
                    cout << "! " << n - 1 << "\n";
                    cout.flush();
                }
            }
        }
    }
}