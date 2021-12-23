#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
#include <utility>
#include <map>
#include <vector>
#include <set>
using namespace std;

struct Graph
{
    int V, E;
    vector< pair<int, pair<int, int>> > edges;
    // Constructor 
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }

    void addEdge(int u, int v, int w)
    {
        edges.push_back({ w, {u, v} });
    }
    
    //YOUR CODE HERE
    class subset {
    public:
        int parent;
        int rank;
    };
    int find(subset subsets[], int i)
    {
        if (subsets[i].parent != i)
            subsets[i].parent
                = find(subsets, subsets[i].parent);
    
        return subsets[i].parent;
    }

    void Union(subset subsets[], int x, int y)
    {
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);
        if (subsets[xroot].rank < subsets[yroot].rank)
            subsets[xroot].parent = yroot;
        else if (subsets[xroot].rank > subsets[yroot].rank)
            subsets[yroot].parent = xroot;
        else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
    int kruskalMST() {
        vector< pair<int, pair<int, int>> > holder;
        bool visit[edges.size()];
        for(unsigned int i=0;i<edges.size(); i++)
            visit[i]=0;
        int min=-1;
        int z=-1;
        while(holder.size()<edges.size()){
            for(unsigned int i=0; i<edges.size(); i++)
                if((min>edges[i].first||min==-1)&&visit[i]==0){
                    z=i;
                    min=edges[i].first;
                }
            holder.push_back(edges[z]);
            visit[z]=1;
            min=-1;
            z=-1;
        }
        subset* subsets = new subset[(V * sizeof(subset))];
        for (int v = 0; v < V; ++v) 
        {
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
        int ans = 0;
        int e = 0; 
        int i = 0;
        vector< pair<int, pair<int, int>> > spanningTree;
        
        while (e < V - 1 && i < E) 
        {
        pair<int, pair<int, int>> next_edge;
        next_edge = holder[i++];
        int x = find(subsets, next_edge.second.first);
            int y = find(subsets, next_edge.second.second);
            if (x != y) {
                spanningTree.push_back(next_edge) ;e++;
                Union(subsets, x, y);
            }
            
        }
        for (unsigned i = 0; i < spanningTree.size(); ++i) 
        {
            
            ans = ans + spanningTree[i].first;
        }
        return ans;
    }
};
