#include <iostream>
#include <vector>
#include <queue>

vector<int> topologicalSorting(vector<vector<int>> graph) {
    vector<int> g;
    int numVer = graph.size();
    vector<int> in_degree(numVer, 0);

    for (int u = 0; u < numVer; u++) {
        for (auto i = graph[u].begin(); i != graph[u].end(); i++)
            in_degree[*i]++;
    }

    queue<int> q;
    for (int i = 0; i < numVer; i++)
        if (in_degree[i] == 0)
            q.push(i);
    int count = 0;
    vector<int> result;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        result.push_back(u);
        for (auto i = graph[u].begin(); i != graph[u].end(); i++)
            if (--in_degree[*i] == 0)
                q.push(*i);
        count++;
    }
    if (count != numVer) {
        return g;
    }
    return result;
}