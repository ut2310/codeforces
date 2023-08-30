using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
int a[maxn], c[maxn][maxn];
 
void init()
{
	for(int i = 0; i < maxn; i++){
		c[i][0] = 1;
		for(int j = 1; j <= i; j++){
			c[i][j] = (c[i-1][j] + c[i-1][j-1]) % mod;
		}
	}
}
 
int main()
{
	init();
	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		int sum = 0, cnt  = 0;
		int target = a[n-k+1];
		for(int i = 1; i <= n; i++){
			if(a[i] == target){
				sum++;
				if(i >= n - k + 1)
					cnt++;
			}
		}
		cout << c[sum][cnt] << endl;
	}
	return 0;
}