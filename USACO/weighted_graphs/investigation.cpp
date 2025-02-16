#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll M;
struct Node {
    long long distance;
    int node;
    long long frequency;
    long long minPathLen;
    long long maxPathLen;

    Node(long long dist, int n, long long freq, long long minLen, long long maxLen)
        : distance(dist), node(n), frequency(freq), minPathLen(minLen), maxPathLen(maxLen) {}
};
struct CompareNode{
    bool operator()(const Node &a, const Node &b){
        return a.distance > b.distance;
    }
};
int main() {
    M = 1e9 + 7;
	int n, m;
	cin >> n >> m;

	// Adjacency list of (neighbour, edge weight)
	vector<vector<pair<ll, ll>>> neighbors(n);
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		neighbors[a - 1].push_back({b - 1, c});
	}

	// Initially set all distances to infinity
	vector<long long> dist(n, LLONG_MAX);
    vector<long long> min_len(n, LLONG_MAX);
    vector<long long> max_len(n, LLONG_MIN);
    vector<long long> freq(n, 0);
    vector<bool> visited(n);
	// Dijkstra's algorithm
	priority_queue<Node, vector<Node>, CompareNode> pq;

	int start = 0;
	dist[start] = 0;  // The shortest path from a node to itself is 0
    freq[start] = 1;
    min_len[start] = 0;
    max_len[start] = 0;
	pq.push(Node(0LL, 0LL, 1LL, 0LL, 0LL));

	while (!pq.empty()) {
		Node x = pq.top();

		pq.pop();
		if (visited[x.node]) { continue; }
        visited[x.node] = true;
        //cout << x.distance << " " << x.node << " " << x.frequency << " " << x.minPathLen << " " << x.maxPathLen << "\n";
		for (pair<ll, ll> &i : neighbors[x.node]) {
			// If we can reach a neighbouring node faster,
			// we update its minimum distance
            // if(x.node == 2){
            //     cout << x.distance << " " << i.second << " " << dist[i.first] << "hi2\n";
            // }
			if (x.distance + i.second < dist[i.first]) {
                freq[i.first] = x.frequency; freq[i.first] %= M;
				pq.push(Node(dist[i.first] = dist[x.node] + i.second,
                i.first, freq[i.first] = freq[x.node], 
                min_len[i.first] = min_len[x.node] + 1,
                max_len[i.first] = max_len[x.node] + 1));
                //freq[i.first] %= M;
                //cout << x.distance + i.second << " " << i.first << " " << x.frequency << " " << x.minPathLen + 1 << " " << x.maxPathLen + 1 << "hi\n";
			}
            else if(x.distance + i.second == dist[i.first]){
                freq[i.first] += freq[x.node]; freq[i.first] %= M;
                min_len[i.first] = min(min_len[i.first], min_len[x.node] + 1);
                max_len[i.first] = max(max_len[i.first], max_len[x.node] + 1);
                //cout << x.distance + i.second << " " << i.first << " " << freq[i.first] << " " << min_len[i.first] << " " << max_len[i.first] << "hi\n";

            }
		}
	}

	//for (int i = 0; i < n - 1; i++) { cout << dist[i] << ' '; }
	cout << dist[n - 1] << " " << freq[n - 1] << " " << min_len[n - 1] << " " << max_len[n - 1] << "\n";
}