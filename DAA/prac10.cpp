#include <iostream>
#include <list> 
#include <stack>
using namespace std;
class Graph
{
    int V;
    list<int> *adj;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v);
    void printGraph();
};
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::DFS(int v)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    stack<int> stack;
    stack.push(v);
    while (!stack.empty())
    {
        v = stack.top();
        stack.pop();
        if (!visited[v])
        {
            cout << v << " ";
            visited[v] = true;
            for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
                if (!visited[*i])
                    stack.push(*i);
        }
    }
}
void Graph::printGraph()
{
    for (int v = 0; v < V; ++v)
    {
        cout << "\nAdjacency list of vertex " << v << "\n";
        cout << "head";
        for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
            cout << " -> " << *i;
        cout << endl;
    }
}
int main()
{
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Graph before DFS traversal:\n";
    g.printGraph();
    cout << "\n\nFollowing is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);
    return 0;
}