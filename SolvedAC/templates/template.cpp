using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};
struct Trie
{
    Trie *children[ALPHABETSIZE];
    bool isEndOfWord;   
    ll cnt;
};
Trie* getNode()
{
    Trie* node = new Trie;
    node->isEndOfWord = false;
    for(int i = 0; i < ALPHABETSIZE; i++)
    {
        node->children[i] = nullptr;
    }
    node->cnt = 0;
    return node;
}
void insert(struct Trie *root, string s)
{
    Trie *temp = root;
    for(int i = 0; i < s.size(); i++)
    {
        int index = s.at(i) - 'a';
        if(temp->children[index]==NULL)
        {
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
        temp->cnt+=1;
    }
    temp->isEndOfWord = true;
}
ll M;
ll fact[MAXN];  
ll invfact[MAXN];
// check if jth bit is 1: (temp & (1 << j)) 
template<class T>
std::ostream &operator<<(std::ostream &o, std::vector<T> v) {
    for (auto &&x : v) o << x << " ";
    return o;
}
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b)
        return gcd(a % b, b);
    return gcd(a, b % a);
}
vector<ll> SieveOfEratosthenes(int n, vector<ll> primes)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is not changed, then it is a prime
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
  
    // Print all prime numbers
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.push_back(p);
    return primes;
}
pair<ll, pair<ll, ll>> maxSubArraySum(vector<ll> a, ll size) //return subarray sum and indices of the array which makes the subarray sum
{
    vector<pair<ll, ll>> max_ending_here;   
    ll max_so_far = -1;
    max_ending_here.push_back(make_pair(a[0], 0));
    ll l, r;
    for (int i = 1; i < size; i++) {
        if(max_ending_here[i - 1].first > 0)
        {
            max_ending_here.push_back(make_pair(max_ending_here[i - 1].first + a[i], max_ending_here[i - 1].second));
        }
        else
        {
            max_ending_here.push_back(make_pair(a[i], i));
        }
    }
    for(int i = 0; i < size; i++)
    {
        if(max_ending_here[i].first > max_so_far)
        {
            max_so_far = max_ending_here[i].first;
            l = max_ending_here[i].second;
            r = i;
        }
    }
    return make_pair(max_so_far, make_pair(l, r));
}

ll mod(ll a, ll b)
{
    if(a % b < 0)
    {
        return b + a % b;
    }
    return a % b;
}
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
 
    ll p = power(x, y / 2) % M;
    p = (p * p) % M;
 
    return (y % 2 == 0) ? p : (x * p) % M;
}
ll modInverse(ll A)
{
    return power(A, M - 2);
}
ll choose(ll a, ll b)
{
    if(a < b)
    {
        return 0;
    }
    else
    {
        ll res = mod((fact[a] * invfact[b]), M);
        res = mod((res * invfact[a - b]), M);
        return res;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    M = 1e9 + 7;
}