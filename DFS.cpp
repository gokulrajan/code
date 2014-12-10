#include <iostream>
#include<vector>
#include<list>
using namespace std;

class Graph
{
	
	private:
	
	int V;
	list<int>*adj;
	void DFSUtil(int,bool*);
	
	
	public:
	
	Graph(int);
	void addEdge(int,int);
	void DFS(int);
	
	
};

Graph::Graph(int V)
{
	this->V=V;
	this->adj=new list<int>[V];
}


void Graph::addEdge(int src,int dest)
{
	adj[src].push_back(dest);
}


void Graph::DFSUtil(int u,bool visited[])
{
	
	visited[u]=true;
	cout<<u<<'\t';
	
	list<int>::iterator i;
	
	for(i=adj[u].begin();i!=adj[u].end();i++)
		{
			if(visited[*i]==false)
				DFSUtil(*i,visited);
		}
	
}

void Graph:: DFS(int start)
{
	bool *visited=new bool[V];
	
	for(int i=0;i<V;i++)
		visited[i]=false;
		
	DFSUtil(start,visited);
}

int main() {
	Graph g(4);
	g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
	return 0;
}