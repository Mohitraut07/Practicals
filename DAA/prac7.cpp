#include <iostream>
#include <vector>
#include <queue>
#include <limits>  // for numeric_limits

#define INF std::numeric_limits<int>::max()

class Graph
{
private:
    int V;                              // Number of vertices
    std::vector<std::vector<std::pair<int, int> > > adj; // Adjacency list representation of the graph
public:
    Graph(int vertices) : V(vertices)
    {
        adj.resize(V);
    }
    // Function to add an edge to the graph
    void addEdge(int u, int v, int weight) {
        adj[u].push_back(std::make_pair(v, weight));
        adj[v].push_back(std::make_pair(u, weight)); // For undirected graph
    }
    // Function to find the minimum spanning tree using Prim's algorithm
    int primMST(int startVertex) {
        // Priority queue to store vertices along with their weights
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > pq;
        std::vector<int> key(V, INF); // Key values used to pick minimum weight edge in cut
        std::vector<bool> inMST(V, false); // To represent set of vertices included in MST
        int totalWeight = 0;

        // Add startVertex to the priority queue and initialize its key as 0
        pq.push(std::make_pair(0, startVertex));
        key[startVertex] = 0;

        // Loop until priority queue becomes empty
        while (!pq.empty()) {
            int u = pq.top().second; // Extract vertex with minimum key value
            pq.pop();

            // Add vertex u to the minimum spanning tree
            inMST[u] = true;
            totalWeight += key[u];

            // Update key values and add adjacent vertices to the priority queue
            for (std::pair<int, int>& neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push(std::make_pair(key[v], v));
                }
            }
        }

        return totalWeight; // Return the total weight of the minimum spanning tree
    }
};

int main()
{
    Graph g(5); // Create a graph with 5 vertices
    // Add edges to the graph (vertex1, vertex2, weight)
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 6);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 4, 7);
    g.addEdge(3, 4, 9);
    int startVertex = 0;                      // Choose any vertex as the starting point
    int totalWeight = g.primMST(startVertex); // Compute the minimum spanning tree
    std::cout << "Total Weight of Minimum Spanning Tree: " << totalWeight << std::endl;
    return 0;
}
