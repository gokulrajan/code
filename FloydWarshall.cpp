#include <iostream>
#include<vector>
#define V 4
#define INF 999999
using namespace std;

void print(int sol[][4])
{
	for(int i=0;i<V;i++)
	{
		for(int j=0;j<V;j++)
		{
			cout<<sol[i][j]<<"\t";
		}
		
		cout<<endl;
	}
}
void floydWarshall(int graph[V][V])
{
	int sol[V][V];
	
	for(int i=0;i<V;i++)
		for(int j=0;j<V;j++)
			sol[i][j]=graph[i][j];
			
			
	for(int k=0;k<V;k++)
	{
		for(int i=0;i<V;i++)
		{
			for(int j=0;j<V;j++)
			{
				if(sol[i][k]+sol[k][j]<sol[i][j])
				{
					sol[i][j]=sol[i][k]+sol[k][j];
				}
			}
		}
	}
print(sol);
}
int main() {
	 int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };
 
    // Print the solution
    floydWarshall(graph);
    return 0;
}