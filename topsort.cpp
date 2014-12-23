#include <iostream>
#include<stack>
#include<vector>
#include<list>
using namespace std;

class Graph
{
	private:
	
	int V;
	void tsortUtil(int,bool v[],stack<int>&);
	list<int> *adj;
	
	public:
	
	Graph(int);
	void tsort();
	void addEdge(int,int);
	
};

void Graph::addEdge(int src,int dest)
{
	adj[src].push_back(dest);
}


Graph::Graph(int V)
{
	this->V=V;
	adj=new list<int>[V];
}



void Graph::tsortUtil(int s,bool visited[],stack<int> &slist)
{
	visited[s]=true;
	
	list<int>::iterator i;
	
	for(i=adj[s].begin();i!=adj[s].end();i++)
	{
		if(visited[*i]==false)
		{
			tsortUtil(*i,visited,slist);
		}
	}
	
	slist.push(s);
}

void Graph::tsort()
{
	bool *visited=new bool[V];
	
	stack<int> slist;
	
	for(int i=0;i<V;i++)
		visited[i]=false;
		
	for(int i=0;i<V;i++)
		tsortUtil(i,visited,slist);
		
		while(!slist.empty())
		{
			cout<<slist.top();
			cout<<'\t';
			slist.pop();
		}
		
		
}


int main() {
	
	Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
 
    cout << "Following is a Topological Sort of the given graph \n";
    g.tsort();
	return 0;
}