#include<iostream> 
#include <list>
using namespace std;

class DirectedGraph 
{ 
	int V;
	list<int> *adj;
	bool isCyclicUtil(int v, bool visited[], bool *rs) {
		if(!visited[v]) { 
			visited[v] = true; 
			rs[v] = true; 

			list<int>::iterator it; 
			for(it = adj[v].begin(); it != adj[v].end(); ++it) { 
				if (!visited[*it] && isCyclicUtil(*it, visited, rs)) 
					return true; 
				else if (rs[*it]) 
				    return true;
			} 
	
		} 
		rs[v] = false; 
		return false; 
	}
public: 
	DirectedGraph(){
        V = 0;
        adj = NULL;
    }
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = new list<int>[V];
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	bool isCyclic() 
	{ 
		bool *visited = new bool[V]; 
		bool *rs = new bool[V]; 
		for (int i = 0; i < V; i++) { 
			visited[i] = false; 
			rs[i] = false; 
		} 
		for (int i = 0; i < V; i++)
			if (isCyclicUtil(i, visited, rs)) 
				return true; 
		return false; 
	}
}; 