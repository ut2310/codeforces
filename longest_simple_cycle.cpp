    using namespace std;
    using ll = long long;
    #include <iostream>
    #include <utility>

    
    const long N = 3 + 1e5;
    
    int n, a[N], b[N], c[N];
    
    int main() {
        int T;
        cin >> T;
        while (T--) {
            cin >> n;
            for (int i = 1; i <= n; ++i) {
                cin >> c[i];
            }
            for (int i = 1; i <= n; ++i) {
                cin >> a[i];
            }
            for (int i = 1; i <= n; ++i) {
                cin >> b[i];
            }
            ll ans = 0;
            ll last = c[n] - 1;
            for (int i = n; i > 1; --i) {
                ans = max(ans, last + 2 + abs(b[i] - a[i]));
                if (a[i] != b[i]){
                    last = last + 2 + c[i - 1] - 1LL - abs(b[i] - a[i]);
                    last = max(last, c[i - 1] - 1LL);
                    //last = max({last + 2, (ll)abs(a[i] - b[i]), c[i - 1] - 1LL});
                }
                else
                    last = c[i - 1] - 1;
            }
            cout << ans << endl;
        }
        return 0;
    }