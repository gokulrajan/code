#include <iostream>
#include<vector>
#include<list>
#include<queue>

using namespace std;

class Graph
{
	
	private:
	int V;
	list<int>*adj;
	void BFSUtil(int,bool visited[]);
	
	public:
	Graph(int);
	void addEdge(int ,int);
	void BFS(int);
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

void Graph::BFSUtil(int s ,bool visited[])
{
	queue<int> q;
	visited[s]=true;
	
	cout<<s<<'\t';
	
	list<int>::iterator i;
	
	for(i=adj[s].begin();i!=adj[s].end();i++)
	{
		if(!visited[*i])
		{
			visited[*i]=true;
		
			q.push(*i);
		}
	}
	
while(!q.empty())
{
	int v=q.front();
	q.pop();
	BFSUtil(v,visited);	
}
	

	
}

void Graph::BFS(int s)
{
	bool *visited=new bool[V];
	for(int i=0;i<V;i++)
		visited[i]=false;
		
	BFSUtil(s,visited);
}

int main() {

	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(0);
 
    return 0;
}