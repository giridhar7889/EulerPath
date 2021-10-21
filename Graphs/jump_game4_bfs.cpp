class Solution
{
public:
    int minJumps(vector<int> &arr)
    {
        int n = arr.size();
        if (n == 1)
        {
            return 0;
        }

        map<int, vector<int>> graph;
        for (int i = 0; i < n; i++)
        {
            graph[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);
        vector<bool> visited(n, false);
        vector<int> dist(n, 0);
        dist[0] = 0;
        visited[0] = true;

        while (!q.empty())
        {
            int x = q.front();
            q.pop();

            if (x == arr.size() - 1)
            {
                return dist[x];
                break;
            }

            for (auto i : graph[arr[x]])
            {
                if (i != x && !visited[i])
                {
                    visited[i] = true;

                    q.push(i);
                    dist[i] = dist[x] + 1;
                }
            }
            if (x - 1 != -1 && !visited[x - 1])
            {
                visited[x - 1] = true;
                q.push(x - 1);
                dist[x - 1] = dist[x] + 1;
            }
            if (x + 1 != n && !visited[x + 1])
            {
                visited[x + 1] = true;
                q.push(x + 1);
                dist[x + 1] = dist[x] + 1;
            }
            graph.erase(arr[x]);
        }
        return dist[n - 1];
    }
};