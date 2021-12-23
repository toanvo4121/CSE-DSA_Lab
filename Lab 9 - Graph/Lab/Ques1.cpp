#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};

class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
		int numVer = this->adj->getSize();
		Adjacency* traversedList = new Adjacency;
		bool* visited = new bool[numVer];
		for (int i = 0; i < numVer; ++i) {
			visited[i] = false;
		}
		this->DFSRec(v, visited, traversedList);
		delete[] visited;
		return traversedList;
	}

	void DFSRec(int v, bool* visited, Adjacency* &traversedList) {
		visited[v] = true;
		traversedList->push(v);

		int curSize = this->adj[v].getSize();
		for (int i = 0; i < curSize; ++i) {
			int adjVer = this->adj[v].getElement(i);
			if (!visited[adjVer])
				this->DFSRec(adjVer, visited, traversedList);
		}
	}
};