//code for dijsktra
#include <iostream>
#include <climits>
using namespace std;
const int numberVertex = 10;
int minDistance(int dist[], bool ShortestPathTree[])
{
	int min = INT_MAX, min_index;
	for(int ver=0;ver<numberVertex;ver++)
	{
		if(ShortestPathTree[ver]==false && dist[ver]<=min)
		{
			min=dist[ver];
			min_index=ver;
		}
	}
	return min_index;
}
void dijkstra(int graph[numberVertex][numberVertex], int source)
{
	int dist[numberVertex];
	bool ShortestPathTree[numberVertex];
	for(int i=0; i<numberVertex;i++)
	{
		dist[i]=INT_MAX;
		ShortestPathTree[i]=false;
	}
	dist[source] = 0;
	for(int count=0; count<numberVertex-1; count++)
	{
		int u=minDistance(dist, ShortestPathTree);
		ShortestPathTree[u]=true;
		for(int ver = 0; ver < numberVertex; ver++)
		{
			if(ShortestPathTree[ver] == 0 && graph[u][ver] != 0 &&
					dist[u] != INT_MAX && dist[u] + graph[u][ver] < dist[ver])
		dist[ver] = dist[u] + graph[u][ver];
		}
	}
	cout << "Distance from Source:" << endl;
	cout << "Vertex\t\tDistance" << endl;
	for(int i = 0; i < numberVertex; i++)
	{
		cout << i << "\t\t" << dist[i] << endl;
	}
}

int main()
{
	int graph[numberVertex][numberVertex] = {{0, 14, 0, 7, 0, 0, 0, 8, 0, 10},
		{14, 0, 8, 0, 0, 0, 0, 11, 0, 0},
		{0, 8, 0, 7, 0, 4, 0, 0, 2, 0},
		{7, 0, 7, 0, 9, 12, 0, 0, 0, 5},
		{0, 0, 0, 9, 0, 0, 0, 0, 0, 0},
		{0, 0, 4, 0, 0, 0, 2, 0, 0, 11},
		{0, 0, 0, 12, 0, 2, 0, 1, 6, 15},
		{8, 11, 0, 0, 0, 0, 1, 0, 7, 0},
		{0, 0, 2, 0, 0, 0, 6, 7, 0, 0},
		{10, 0, 0, 5, 0, 11, 15, 0, 0, 0}};
	dijkstra(graph, 0);
	return 0;
}

