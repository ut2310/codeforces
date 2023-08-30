using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
using namespace std;
int gcd(int a , int b){
	if(b == 0) return a;
	return gcd(b , a%b);
}
int main(){
	int t, n;
	cin >> t;
	while(t--){
		int c0 = 0;
        int c1 = 0;
		string s;
		cin >> n >> s;
		map<pair<int,int>, int> dp;
		for(int i = 0; i < n; i++)
        {
			if(s[i] == 'D')
            {
                c0++;
            } 
			else
            {
                c1++;
            } 
			pair<int,int> p ;
			if(c0 == 0)
            {
                p = {0 , 1};
            } 
			else if(c1 == 0) 
            {
                p = {1 , 0};
            }
			else
            {
                p = {c0 / gcd(c0,c1) , c1 / gcd(c0,c1)};
            } 
 
			dp[p]++;
			cout << dp[p] << ' ' ;
		}
		cout << '\n';
	}
}