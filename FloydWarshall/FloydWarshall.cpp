/**
 * @file FloydWarshall.cpp
 * @author Nicholas Smith
 * @brief
 * @version 0.1
 * @date 2023-01-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <iostream>
#include <bits/stdc++.h>

int Vertices;

namespace dynamic_programming
{
    namespace FloydWarshall
    {
        class Graph
        {
        private:
            int V;
            int **adj;

        public:
            Graph(int V);
            void addEdge(int u, int v, int w);
            void floydWarshall();
            void showMinDistanceBetween(int u, int v);
        };

        Graph::Graph(int V)
        {
            this->V = V;
            adj = new int *[V];
            for (int i = 0; i < V; i++)
            {
                adj[i] = new int[V];
                for (int j = 0; j < V; j++)
                {
                    adj[i][j] = INT_MAX;
                }
            }
        }

        void Graph::addEdge(int u, int v, int w)
        {
            adj[u][v] = w;
        }

        void Graph::floydWarshall()
        {
            Vertices = V;
            std::vector<std::vector<int>> dist(V, std::vector<int>(V, INT_MAX));
            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (i == j)
                    {
                        dist[i][j] = 0;
                    }
                    else if (adj[i][j] != INT_MAX)
                    {
                        dist[i][j] = adj[i][j];
                    }
                }
            }

            for (int k = 0; k < V; k++)
            {
                for (int i = 0; i < V; i++)
                {
                    for (int j = 0; j < V; j++)
                    {
                        if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j])
                        {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }

            for (int i = 0; i < V; i++)
            {
                for (int j = 0; j < V; j++)
                {
                    if (dist[i][j] == INT_MAX)
                    {
                        std::cout << "INF"
                                  << " ";
                    }
                    else
                    {
                        std::cout << dist[i][j] << " ";
                    }
                }
                std::cout << std::endl;
            }
            
        }

        void Graph::showMinDistanceBetween(int u, int v)
        {
            std::cout << "The minimum distance between " << u << " and " << v << " is " << adj[u][v] << std::endl;
        }
    }
}

int main(){
    int V = 5;
    dynamic_programming::FloydWarshall::Graph g(V);
    g.addEdge(0, 2, 9);
    g.addEdge(0, 4, 10);
    g.addEdge(1, 3, 5);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 0, 10);
    g.addEdge(3, 1, 2);
    g.addEdge(3, 2, 1);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 1, 3);
    g.addEdge(4, 2, 4);
    g.addEdge(4, 3, 9);
    
    g.floydWarshall();
    g.showMinDistanceBetween(1, 4);
    g.showMinDistanceBetween(0, 3);
    system("pause");
    return 0;
}