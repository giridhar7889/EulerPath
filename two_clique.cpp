#include <iostream>
#include <vector>
#include <map>
using namespace std;

void bipartite(int src, int col, map<int, vector<int>> &comp_graph, vector<int> &color, bool &ans, vector<bool> &visited)
{
    if (color[src] != -1 && color[src] != col)
    {
        ans = false;
        return;
    }
    color[src] = col;
    if (visited[src])
    {
        return;
    }
    visited[src] = true;
    for (auto i : comp_graph[src])
    {
        bipartite(i, col ^ 1, comp_graph, color, ans, visited);
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
    map<int, vector<int>> comp_graph;
    vector<int> temp(n, 0);
    for (int node = 0; node < n; node++)
    {

        temp[node] = 1;
        for (auto j : graph[node])
        {
            temp[j] = 1;
        }
        for (int t = 0; t < n; t++)
        {
            if (temp[t] == 0)
            {
                comp_graph[node].push_back(t);
                comp_graph[t].push_back(node);
            }
        }
        temp.clear();
    }
    // for (auto i : comp_graph)
    // {
    //     cout << i.first << "->";
    //     for (auto j : comp_graph[i.first])
    //     {
    //         cout << j;
    //     }
    //     cout << endl;
    // }
    vector<int> color(n, -1);
    vector<bool> visited(n, false);
    bool ans = true;
    bipartite(0, 0, comp_graph, color, ans, visited);
    if (ans == true)
    {
        cout << "can be divided into two cliques";
    }
    else
    {
        cout << "can't be divided into two cliques";
    }
}