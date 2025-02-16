#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005 

int main()
{
    ll c, d; cin >> c >> d;
    vector<ll> Buzz;
    vector<ll> Fizz;
    for(int i = c; i <= d; i++){
        string s; cin >> s;
        if(s == "Buzz"){
            Buzz.push_back(i);
        }
        if(s == "FizzBuzz"){
            Buzz.push_back(i);
            Fizz.push_back(i);
        }
        if(s == "Fizz"){
            Fizz.push_back(i);
        }
    }
    ll f = 0;
    ll b = 0;
    if(Fizz.size() == 1){
        f = Fizz[0];
    }
    else if(Fizz.size() >= 2){
        f = Fizz[1] - Fizz[0];
    }
    else
    {
        f = d + 1;
    }
    if(Buzz.size() == 1){
        b = Buzz[0];
    }
    else if(Buzz.size() >= 2){
        b = Buzz[1] - Buzz[0];
    }
    else
    {
        b = d + 1;
    }
    cout << f << " " << b << "\n";
    

}