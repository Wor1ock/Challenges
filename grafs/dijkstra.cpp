#include <iostream>
#include <limits.h>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int to;
    int weight;
};

int dijkstra(vector<vector<Edge>>& graph, int src, int dest) {
    int N = graph.size();
    vector<int> dist(N, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (Edge& e : graph[u]) {
            int v = e.to;
            int weight = e.weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return (dist[dest] != INT_MAX) ? dist[dest] : -1;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N + 1);

    for (int i = 0; i < M; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    int A, B;
    cin >> A >> B;

    cout << dijkstra(graph, A, B) << endl;
    return 0;
}
