//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <unordered_map>
//#include <unordered_set>
//#include <vector>
//#include <queue>
//#include <algorithm>
//#include <array>
//
//using namespace std;
//
//class Graph
//{
//    int V;    // No. of vertices 
//
//    // In a weighted graph, we need to store vertex 
//    // and weight pair for every edge 
//    list< pair<int, int> >* adj;
//
//public:
//    Graph(int V);  // Constructor 
//
//    // function to add an edge to graph 
//    void addEdge(int u, int v, int w);
//
//    // prints shortest path from s 
//    void shortestPath(int s);
//};
//
//// Allocates memory for adjacency list 
//Graph::Graph(int V)
//{
//    this->V = V;
//    adj = new list<pair<int, int>>[V];
//}
//
//void Graph::addEdge(int u, int v, int w)
//{
//    adj[u].push_back(make_pair(v, w));
//    adj[v].push_back(make_pair(u, w));
//}
//
//// Prints shortest paths from src to all other vertices 
//void Graph::shortestPath(int src) {
//    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
//    vector<int> dist(V, INT_MAX);
//    pq.push({ 0, src });
//    dist[src] = 0;
//    while (!pq.empty()) {
//        const auto u = pq.top().second;
//        pq.pop();
//        for (const auto [v, w] : adj[u]) {
//            if (dist[v] > dist[u] + w) {
//                dist[v] = dist[u] + w;
//                pq.push({ dist[v], v });
//            }
//        }
//    }
//    // Print shortest distances stored in dist[] 
//    printf("Vertex   Distance from Source\n");
//    for (int i = 0; i < V; ++i)
//        printf("%d \t\t %d\n", i, dist[i]);
//}
//
//int main()
//{
//    // create the graph given in above fugure 
//    int V = 9;
//    Graph g(V);
//
//    //  making above shown graph 
//    g.addEdge(0, 1, 4);
//    g.addEdge(0, 7, 8);
//    g.addEdge(1, 2, 8);
//    g.addEdge(1, 7, 11);
//    g.addEdge(2, 3, 7);
//    g.addEdge(2, 8, 2);
//    g.addEdge(2, 5, 4);
//    g.addEdge(3, 4, 9);
//    g.addEdge(3, 5, 14);
//    g.addEdge(4, 5, 10);
//    g.addEdge(5, 6, 2);
//    g.addEdge(6, 7, 1);
//    g.addEdge(6, 8, 6);
//    g.addEdge(7, 8, 7);
//
//    g.shortestPath(0);
//
//    return 0;
//}