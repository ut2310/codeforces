#include <bits/stdc++.h>
#define ll long long
using namespace std;
void computeLPSArray(string &pat, int M, int* lps)
{
    // length of the previous longest prefix suffix
    int len = 0;
 
    lps[0] = 0; // lps[0] is always 0
 
    // the loop calculates lps[i] for i = 1 to M-1
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else // (pat[i] != pat[len])
        {
            // This is tricky. Consider the example.
            // AAACAAAA and i = 7. The idea is similar
            // to search step.
            if (len != 0) {
                len = lps[len - 1];
 
                // Also, note that we do not increment
                // i here
            }
            else // if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector<ll> KMPSearch(string &pat, string &txt)
{
    int M = pat.size();
    int N = txt.size();
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int lps[M];
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
    vector<ll> res;
    int i = 0; // index for txt[]
    int j = 0; // index for pat[]
    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
 
        if (j == M) {
            res.push_back(i - j);
            j = lps[j - 1];
        }
 
        // mismatch after j matches
        else if (i < N && pat[j] != txt[i]) {
            // Do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return res;
}
 
// Fills lps[] for given pattern pat[0..M-1]


bool check(string &s, ll len, ll num)
{
    string rq = s.substr(0, len);
    vector<ll> res = KMPSearch(rq, s);
    ll final_res = 0;
    if(res.size() >= 1)final_res++;
    ll last_counted = 0;
    for(int i = 1; i < res.size(); i++)
    {
        if(res[i] - res[last_counted] >= len)
        {
            final_res++;
            last_counted = i;
        }
    }
    // cout << num << " " << cnt << "\n";
    if(final_res >= num)
    {
        return true;
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t-->0)
    {
        ll n, l, r; cin >> n >> l >> r;
        string s; cin >> s;  
        if(l == 1)
        {
            cout << n << "\n";
        }
        else
        {
            ll low = 0;
            ll high = n; 
            while(low < high)
            {
                ll mid = (low + high + 1)/2;
                if(check(s, mid, l))
                {
                    low = mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
            cout << low << "\n";
        }
    }
    
}