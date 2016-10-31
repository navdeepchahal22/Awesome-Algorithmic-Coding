//this code implementation is just an example to show how ford_fulkerson work 
//i.e i have build this on a particular test case 
//for generalised version , i mean the graph's parameter no: of nodes 
// and no: of edges has to be taken as input by user along with corresponding 
//edge weight so that part has to be implemented 

#include <iostream>
#include <string.h>
#include <queue>
#define max_val 99999999
using namespace std;
bool bfs(int rGraph[][6], int s, int t, int parent[]);
int fordFulkerson(int graph[6][6], int s, int t);
int fordFulkerson(int graph[6][6], int s, int t)

{

  int u, v;

  int rGraph[6][6];  //residue graph

  for (u = 0; u < 6; u++)

  {

    for (v = 0; v < 6; v++)

    {

      rGraph[u][v] = graph[u][v];

    }

  }

  int parent[6];

  int max_flow = 0;

  while (bfs(rGraph, s, t, parent))

  {

    int path_flow = max_val;

    for (v = t; v != s; v = parent[v])

    {

      u = parent[v];

      path_flow = min(path_flow, rGraph[u][v]);

    }

    for (v = t; v != s; v = parent[v])

    {

      u = parent[v];

      rGraph[u][v] -= path_flow;

      rGraph[v][u] += path_flow;

    }

    max_flow += path_flow;

  }

  return max_flow;

}

int main()

{

  int graph[6][6] = { {0, 16, 13, 0, 0, 0},

    {0, 0, 10, 12, 0, 0},

    {0, 4, 0, 0, 14, 0},

    {0, 0, 9, 0, 0, 20},

    {0, 0, 0, 7, 0, 4},

    {0, 0, 0, 0, 0, 0}

  }; 

  cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);
cout <<"\n" ;

return 0;

}
bool bfs(int rGraph[][6], int s, int t, int parent[])

{

  bool visited[6];

  memset(visited, 0, sizeof(visited));

  queue <int> q;

  q.push(s);

  visited[s] = true;

  parent[s] = -1;



  while (!q.empty())

  {

    int u = q.front();

    q.pop();

    for (int v = 0; v < 6; v++)

    {

      if (visited[v] == false && rGraph[u][v] > 0)

      {

        q.push(v);

        parent[v] = u;

        visited[v] = true;

      }

    }

  }

  return (visited[t] == true);

}




