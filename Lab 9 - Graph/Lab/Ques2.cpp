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
	
	Adjacency *BFS(int v)
    {
        // v is a vertex we start DFS
		int numVer = this->adj->getSize();
		Adjacency* traversedList = new Adjacency;
		bool* visited = new bool[numVer];
		for (int i = 0; i < numVer; ++i) {
			visited[i] = false;
		}

		list<int> queue;
		visited[v] = true;
		queue.push_back(v);

		while (!queue.empty()) {
			int curVer = queue.front();
			traversedList->push(curVer);
			queue.pop_front();

			int curSize = this->adj[curVer].getSize();
			for (int i = 0; i < curSize; ++i) {
				int adjVer = this->adj[curVer].getElement(i);
				if (!visited[adjVer]) {
					visited[adjVer] = true;
					queue.push_back(adjVer);
				}
			}
		}

		delete[] visited;
		return traversedList;
	}
};