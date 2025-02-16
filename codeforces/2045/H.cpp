using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 5005
#define ALPHABETSIZE 26
#define ff first
#define ss second
#define pii pair<long long,long long>
#define vi vector<long long>
#define vii vector<pair<long long,long long>>
ll dp[MAXN][MAXN]; //ending at the ith character, what is the max # of words i can have? 
//given this max #of words output the minimum thing we can end on

int main()
{
    string s; cin >> s;
    ll n = s.size();
    dp[0][1] = 1;
    dp[0][0] = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= i; j++){
             
        }
    }       
}