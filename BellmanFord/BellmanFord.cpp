#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Edge{
    public:
    int source{}, destination{}, weight{};
};

class Graph{
    public:
    int vertexNumber{}, edgeNumber{};
    Edge *edges = nullptr;
    // Constructs a graph with V vertices and E edges
    Graph(int V, int E){
        this->vertexNumber = V;
        this->edgeNumber = E;
        this->edges = (Edge *)malloc((long long unsigned int)E * sizeof(Edge));
    }

    // A utility function to add the given edge to graph
    void addEdge(int src, int dest, int weight){
        static int edgeIndex = 0;
        if(edgeIndex < this->edgeNumber){
            Edge newEdge;
            newEdge.source = src;
            newEdge.destination = dest;
            newEdge.weight = weight;
            this->edges[edgeIndex++] = newEdge;
        }
    }
};

/**
 * @brief Utility function to print the distance from source to all vertices
 * 
 * @param distance {int} - vector of distances
 * @param V {int} - number of vertices
 */
void printDistances(int distance[], int V){
    cout << "\nVertex\tDistance from source" << endl;
    for (int i = 0; i < V; i++)
    {
        if(distance[i] == INT_MAX){
            cout << i << "\t" << "INF" << endl;
        }
        else{
            cout << i << "\t" << distance[i] << endl;
        }
    }
}

/**
 * @brief Bellman-Ford algorithm to find the shortest path from source to all vertices
 * 
 * @param graph {Graph} - graph
 * @param source {int} - source vertex
 */
void BellmanFord(Graph graph, int source){
    int V = graph.vertexNumber;
    int E = graph.edgeNumber;
    int* distance = new int[V];
    for(int i = 0; i < V; i++) distance[i] = INT_MAX;
    distance[source] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph.edges[j].source;
            int v = graph.edges[j].destination;
            int weight = graph.edges[j].weight;
            if(distance[u] != INT_MAX && distance[u] + weight < distance[v]){
                distance[v] = distance[u] + weight;
            }
        }
    }
    // Check for negative weight cycles
    for (int i = 0; i < E; i++)
    {
        int u = graph.edges[i].source;
        int v = graph.edges[i].destination;
        int weight = graph.edges[i].weight;
        if(distance[u] != INT_MAX && distance[u] + weight < distance[v]){
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }
    printDistances(distance, V);
}


int main(){
    int V = 5;
    int E = 8;
    Graph graph(V, E);
    graph.addEdge(0, 1, -1);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 3);
    graph.addEdge(1, 3, 2);
    graph.addEdge(1, 4, 2);
    graph.addEdge(3, 2, 5);
    graph.addEdge(3, 1, 1);
    graph.addEdge(4, 3, -3);
    BellmanFord(graph, 0);
    system("pause");
    return 0;
}