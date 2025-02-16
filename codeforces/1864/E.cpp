using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 2
ll M;
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
        int index = s[i] - '0';
        if(temp->children[index]==NULL)
        {
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
        temp->cnt+=1;
    }
    temp->isEndOfWord = true;
}
string decToBinary(ll n)
{
    int binaryNum[30];

    int i = 0;
    while (n > 0) {
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    string res = "";
    for (int j = i - 1; j >= 0; j--){
        if(binaryNum[j] == 0){
            res.push_back(0);
        }
        else{
            res.push_back(1);
        }
    }
    return res;
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
int main()
{
    M = 998244353;
    ll n; cin >> n;
    vector<ll> s(n);
    Trie *root = getNode();
    map<ll, ll> freq;
    for(int i = 0; i < n; i++){
        cin >> s[i];
        insert(root, decToBinary(s[i]));
        freq[s[i]]++;
    }
    ll same = 0;
    ll diff = 0;
    for(auto j: freq){
        same += j.first * j.first;
        same %= M;
    }
    diff = n * n - same;
    diff %= M;
    ll res = same + 3 * modInverse(2) * diff;
    res %= M;
    



}