using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 200005
#define ALPHABETSIZE 26

struct Trie{
    Trie *children[ALPHABETSIZE];
    bool state; //if you can make yourself win
    bool state2; //if you can make yourself lose
};

Trie* getNode(){
    Trie *node = new Trie;
    for(int i = 0; i < ALPHABETSIZE; i++)
    {
        node->children[i] = nullptr;
    }
    return node;
}

void insert(Trie *root, string s){
    Trie *temp = root;
    for(int i = 0; i < s.size(); i++)
    {
        int index = s[i] - 'a';
        if(temp->children[index] == NULL){
            temp->children[index] = getNode();
        }
        temp = temp->children[index];
    }
}

void dfs(Trie *node){
    bool flag = false;
    for(int i = 0; i < ALPHABETSIZE; i++)
    {
        if(node->children[i] != NULL){
            dfs(node->children[i]);
            flag |= !node->children[i]->state;
            //cout << i << " " << node->children[i]->state << "\n";
        }
    }
    node->state = flag;
    return;
}

void dfs2(Trie *node){
    bool flag = false; //are you able to force yourself to lose
    ll cnt = 0;
    for(int i = 0; i < ALPHABETSIZE; i++){
        if(node->children[i] != NULL){
            dfs2(node->children[i]);
            flag |= !node->children[i]->state2; 
            cnt++;
        }
    }
    if(cnt == 0){
        flag = true;
    }
    node->state2 = flag;
    return;
}

int main()
{
    ll n, k; cin >> n >> k;
    Trie* root = getNode();
    for(int i = 0; i < n; i++)
    {   
        string s; cin >> s;
        insert(root, s);
    }
    dfs(root);
    dfs2(root);
    // if state of root is True, first player wins
    //cout << root->state << " " << root->state2 << "\n";
    if(root->state && root->state2){
        cout << "First\n";
    }
    else if(root->state && !root->state2){ //first player wins but can't force himself to lose
        if(k % 2 == 1){
            cout << "First\n";
        }
        else{
            cout << "Second\n";
        }
    }
    else {
        cout << "Second\n";
    }

}