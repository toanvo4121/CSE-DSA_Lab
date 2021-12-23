int minDistance(int dist[], bool sptSet[], int V) 
{ 
    int min = 99999, min_index=-1; 

    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
    return min_index; 
}
int Dijkstra(int** graph, int src,int dst) 
{ 
    int V=6;
    int dist[V];  
    bool sptSet[V]; 
    for (int i = 0; i < V; i++){ 
        dist[i] = 99999; 
        sptSet[i] = false; 
        }
    dist[src] = 0; 
    for (int count = 0; count < V - 1; count++) { 
        int u = minDistance(dist, sptSet,V); 
        sptSet[u] = true; 
        for (int v = 0; v < V; v++) 
            if (!sptSet[v] && graph[u][v] && dist[u] != 99999 && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    } 
    return dist[dst];
}