#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005;
#define ALPHABETSIZE 26
#define ll long long
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
void reverseStr(string& str)
{
    ll n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

}