#include <iostream>
using namespace std;
#include <vector>
#include <map>

void dfs(int src, int parent, int &ans, map<int, vector<int>> &graph, int turns, vector<bool> &visited)
{
    if (visited[src])
    {
        return;
    }
    if (src == parent && turns == 3)
    {
        ans++;
        visited[src] = true;
        return;
    }

    if (turns > 3)
    {
        return;
    }
    for (auto i : graph[src])
    {
        dfs(i, parent, ans, graph, turns + 1, visited);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> graph;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans = 0;
    int turns = 0;
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        dfs(i, i, ans, graph, turns, visited);
    }
    cout << ans;
}