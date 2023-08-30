#include <iostream>
#include <algorithm>
#include <queue>
#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;
int a[maxn], b[maxn];
int n;
bool valid(int x) 
{
	int num1, num2;
	int k = (n + x) - (n + x) / 4;
	if (k <= x)
    {
        num1 = 100 * k;
    } 
	else 
    {
		num1 = 100 * x + a[n] - a[n - (k - x)];
	}
	if (k >= n)
    {
        num2 = b[n];
    } 
	else
    {
        num2 = b[n]-b[n-k];
    } 
	if (num1 >= num2)
    {
        return true;
    } 
	return false;
}
int main() {
	int t;
	cin >> t;
	while (t--)
    {
		cin >> n;
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
		sort(a + 1, a + 1 + n);
		sort(b + 1, b + 1 + n);
		for (int i = 1; i <= n; i++) a[i] += a[i - 1], b[i] += b[i - 1];
		int l = 0, r = 200005,mid,ans=100000000;
		while (l<=r) 
        {
			mid = (l + r) / 2;
			if (valid(mid)) 
            {
				r = mid - 1;
				ans = min(ans, mid);
			}
			else l = mid + 1;
		}
		cout << ans << endl;
	}
	return 0;
}