using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26

struct Trie
{
    Trie *children[ALPHABETSIZE];
    int isEndOfWord;
};
Trie *getNode()
{
    Trie *node = new Trie;
    for(int i = 0; i < ALPHABETSIZE; i++){
        node->children[i] = nullptr;
    }
    return node;
}
void insert(struct Trie *root, string s)
{
    Trie *temp = root;
    for(int i = 0; i < s.size(); i++)
    {

    }
}

int main()
{
    string s;
    getline(cin, s);
    ll n; cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<string> suffix;
    for(int i = 0; i < s.size(); i++){
        suffix.push_back(s.substr(i));
    }
    sort(suffix.begin(), suffix.end());
    for(int i = 0; i < suffix.size(); i++){
        cout << suffix[i] << "\n";
    }
}