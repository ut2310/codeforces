using namespace std;
#include <bits/stdc++.h>
#define ll long long
#define MAXN 300005
const int MAX = 300005;
vector<ll> adj[MAXN];
struct Query
{
    int l, r, idx;
};
 
// cmp function to sort queries according to r
bool cmp(Query x, Query y)
{
    return x.r < y.r;
}
 
// updating the bit array
void update(int idx, int val, int bit[], int n)
{
    for (; idx <= n; idx += idx&-idx)
        bit[idx] += val;
}
 
// querying the bit array
int query(int idx, int bit[], int n)
{
    int sum = 0;
    for (; idx>0; idx-=idx&-idx)
        sum += bit[idx];
    return sum;
}
 
ll answeringQueries(vector<ll> arr, int n, vector<Query> queries, int q)
{
    // initialising bit array
    int bit[n+1];
    memset(bit, 0, sizeof(bit));
 
    // holds the rightmost index of any number
    // as numbers of a[i] are less than or equal to 10^6
    int last_visit[MAX];
    memset(last_visit, -1, sizeof(last_visit));
 
    // answer for each query
    vector<ll> ans(q);
    int query_counter = 0;
    for (int i=0; i<n; i++)
    {
        // If last visit is not -1 update -1 at the
        // idx equal to last_visit[arr[i]]
        if (last_visit[arr[i]] !=-1)
            update (last_visit[arr[i]] + 1, -1, bit, n);
 
        // Setting last_visit[arr[i]] as i and updating
        // the bit array accordingly
        last_visit[arr[i]] = i;
        update(i + 1, 1, bit, n);
 
        // If i is equal to r of any query  store answer
        // for that query in ans[]
        while (query_counter < q && queries[query_counter].r == i)
        {
            ans[queries[query_counter].idx] =
                     query(queries[query_counter].r + 1, bit, n)-
                     query(queries[query_counter].l, bit, n);
            query_counter++;
        }
    }
    ll res = 0;
    // print answer for each query
    for (int i=0; i<q; i++){
        res += ans[i];
    }
    return res;
}
int main()
{
    ll N, M; cin >> N >> M;
    vector<ll> a(N);
    set<ll> distinct;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        distinct.insert(a[i]);
        adj[a[i]].push_back(i);
    }
    ll res = 0; res += (distinct.size()) * (M - 1);
    //cout << res << "\n";
    vector<Query> queries;
    ll cnt = 0;
    for(int i = 1; i <= M; i++){
        for(int j = 1; j < adj[i].size(); j++){
            Query q; q.l = adj[i][j - 1]; q.r = adj[i][j]; q.idx = cnt;
            queries.push_back(q);
            cnt++;
        }
    }
    sort(queries.begin(), queries.end(), cmp);
    // for(auto j: queries){
    //     cout << j.l << " " << j.r << "\n";
    // }
    res += answeringQueries(a, N, queries, cnt);
    res -= queries.size();
    cout << res << "\n";
}