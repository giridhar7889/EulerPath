#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// count indegree and out degree of the vertices
void countinoutdegree(vector<vector<int>> &graph, vector<int> &in, vector<int> &out)
{
    for (int i = 0; i < graph.size(); i++)
    {
        for (int j = 0; j < graph[i].size(); j++)
        {
            out[i]++;
            in[graph[i][j]]++;
        }
    }
    for (int i = 0; i < graph.size(); i++)
    {
        cout << in[i] << out[i] << endl;
    }
}

// check whether the graph has eulerian path
bool graphhaseulerpath(vector<int> &in, vector<int> &out)
{
    int start_nodes = 0, end_nodes = 0;
    for (int i = 0; i < in.size(); i++)
    {
        if (out[i] - in[i] > 1 || in[i] - out[i] > 1)
        {
            return false;
        }
        else if (out[i] - in[i] == 1)
        {
            start_nodes++;
        }
        else if (in[i] - out[i] == 1)
        {
            end_nodes++;
            n
        }
    }
    return (end_nodes == 0 && start_nodes == 0) || (end_nodes == 1 && start_nodes == 1);
}

// find starting node among the two vertices
int findstartnode(vector<int> &in, vector<int> &out)
{
    int start_node = 0;
    for (int i = 0; i < in.size(); i++)
    {
        if (out[i] - in[i] == 1)
        {
            return i;
        }
        if (out[i] > 1)
        {
            start_node = i;
        }
    }
    return start_node;
}

// Depth-first search
void dfs(int start_node, vector<vector<int>> &graph, vector<int> &in, vector<int> &out, vector<int> &path)
{
    while (out[start_node] != 0)
    {
        for (int i = 0; i < graph[start_node].size(); i++)
        {

            int next_node = graph[start_node][i];
            --out[start_node];

            dfs(next_node, graph, in, out, path);
        }
    }
    path.push_back(start_node);
}

// helper function
void find_euler_path(vector<vector<int>> &graph, vector<int> &in, vector<int> &out, vector<int> &path)
{
    countinoutdegree(graph, in, out);
    if (!graphhaseulerpath(in, out))
    {
        cout << "no euler path";
    }
    dfs(findstartnode(in, out), graph, in, out, path);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> graph(n);

    vector<int> in(n);
    vector<int> out(n);
    vector<int> path;

    for (int j = 0; j < m; j++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    find_euler_path(graph, in, out, path);
    reverse(path.begin(), path.end());

    //print the eulerian path if we traversed all the edges.
    //The graph might be disconnected ,in which case it is impossible to have and euler path
    if (path.size() == m + 1)
    {
        for (auto i : path)
        {
            cout << i;
        }
    }
    else
    {
        cout << "null";
    }
}
