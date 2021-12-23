#include <iostream>
#include <vector>
#include <queue>

void bfs(vector<vector<int>> graph, int start) {
	int numVertices = graph.size();
	bool *visited = new bool[numVertices]; 
    for(int i = 0; i < numVertices; i++) 
        visited[i] = false; 

    queue<int> myQueue; 
    bool isFirst = true;
    visited[start] = true; 
    myQueue.push(start); 

    while(!myQueue.empty()) 
    { 
        start = myQueue.front();
        if (isFirst) {
            cout << start;
            isFirst = false;
        }
        else cout << " " << start;
        myQueue.pop(); 

        int outDegree = graph[start].size();
        for (int j = 0; j < outDegree; ++j) 
        { 
            int temp = graph[start][j];
            if (!visited[temp]) 
            { 
                visited[temp] = true; 
                myQueue.push(temp); 
            } 
        }
    }
    delete[] visited;
}