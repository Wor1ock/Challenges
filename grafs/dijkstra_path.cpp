#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(vector<int> &dist, vector<bool> &visited, int N)
{
    int min_dist = INT_MAX, min_index;

    for (int v = 1; v < N; ++v)
        if (visited[v] == false && dist[v] <= min_dist)
            min_dist = dist[v], min_index = v;

    return min_index;
}

vector<int> reconstructPath(vector<int> &prev, int dest)
{
    vector<int> path;
    for (int at = dest; at != -1; at = prev[at])
        path.push_back(at);
    reverse(path.begin(), path.end());
    return path;
}

vector<int> dijkstra(vector<vector<int>> &graph, int src, int dest)
{
    int N = graph.size();
    vector<int> dist(N, INT_MAX);
    vector<bool> visited(N, false);
    vector<int> prev(N, -1);
    dist[src] = 0;

    for (int count = 1; count < N; ++count)
    {
        int u = minDistance(dist, visited, N);
        visited[u] = true;

        for (int v = 1; v < N; ++v)
            if (!visited[v] && graph[u][v] != 0 && graph[u][v] != -1 && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
    }

    if (dist[dest] == INT_MAX)
        return vector<int>{-1};

    vector<int> path;
    for (int at = dest; at != -1; at = prev[at])
        path.push_back(at);

    reverse(path.begin(), path.end());

    return path;
}

int main()
{
    int N, S, F;
    cin >> N >> S >> F;
    ++N;

    vector<vector<int>> graph(N, vector<int>(N));
    for (int i = 1; i < N; ++i)
        for (int j = 1; j < N; ++j)
            cin >> graph[i][j];

    vector<int> path = dijkstra(graph, S, F);

    if (path.empty())
        cout << "-1\n";
    else
        for (int i = 0; i < path.size(); ++i)
            cout << path[i] << " ";

    return 0;
}
