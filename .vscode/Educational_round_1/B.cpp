using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <math.h>
int l, r, k;
string s;
void shift_string()
{
    k = k % (r - l + 1);
    string res = "";
    res = res + s.substr(0, l - 1) + s.substr(r - k, k) + s.substr(l - 1, r - k - l + 1) + s.substr(r); 
    s = res;   
}
int main()
{
    int Q;
    cin >> s >> Q;
    for(int i = 0; i < Q; i++)
    {
        cin >> l >> r >> k;
        shift_string();
    }
    cout << s;
}