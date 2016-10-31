#include <bits/stdc++.h>

using namespace std;

void connect(int origin, int destination, vector<vector<int> >& graph)
{
        graph[origin].push_back(destination);
}

void dfs(int idx, vector<bool>& visited, stack<int>& node_stack, vector<vector<int> > const graph)
{
        visited[idx]=1;
        for (auto i:graph[idx]) {
                if (not visited[i])
                        dfs(i, visited, node_stack, graph);
        }

        node_stack.push(idx);
}

void topological_sort(vector<vector<int> > const graph, int num_of_vertex)
{
        stack<int> node_stack;
        vector<bool> visited(num_of_vertex, false);

        for (int i=0; i < num_of_vertex; ++i) {
                if (not visited[i]) {
                        dfs(i, visited, node_stack, graph);
                }
        }

        while (not node_stack.empty()) {
                int idx=node_stack.top();
                cout << idx << " ";
                node_stack.pop();
        }
        cout << "\n";
}

int main()
{
        ios::sync_with_stdio(false);
        int num_of_vertex, num_of_edges;
        cout << "Num of vertex:\n";
        cin >> num_of_vertex;
        vector< vector<int> > graph(num_of_vertex, vector<int>());
        cout << "Num of edges:\n";
        cin >> num_of_edges;

        int origin, destination;
        for (int i=0; i < num_of_edges; ++i) {
                cin >> origin >> destination;
                connect(origin, destination, graph);
        }

        cout << "Topological sort:\n";
        topological_sort(graph, num_of_vertex);
        return 0;
}
