#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair<int,int>

class Graph {
private:
    vector<pair<int, edge>> G; 
    vector<pair<int, edge>> T; 
    int* variety;
    int V; 
public:
    Graph(int V);
    void AddWeightedEdge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
};
Graph::Graph(int V) {
    variety = new int[V];

    for (int i = 0; i < V; i++)
        variety[i] = i;

    G.clear();
    T.clear();
}
void Graph::AddWeightedEdge(int u, int v, int w) {
    G.push_back(make_pair(w, edge(u, v)));
    G.push_back(make_pair(w, edge(v, u)));
}
int Graph::find_set(int i) {
    if (i == variety[i])
        return i;
    else
        return find_set(variety[i]);
}

void Graph::union_set(int u, int v) {
    variety[u] = variety[v];
}
void Graph::kruskal() {
    size_t i, uRep, vRep;
    sort(G.begin(), G.end()); 
    for (i = 0; i < G.size(); i++) {
        uRep = find_set(G[i].second.first);
        vRep = find_set(G[i].second.second);
        if (uRep != vRep) {
            T.push_back(G[i]); 
            union_set(uRep, vRep);
        }
    }
}
void Graph::print() {
    cout << "Ребро :" << " Вес" << endl;
    int minw = 0;
    for (int i = 0; i < T.size(); i++) {
        cout << T[i].second.first +1 << "-" << T[i].second.second +1 << "   : "
            << T[i].first;
        cout << endl;
        minw += T[i].first;
    }
    cout << "Минимальный вес: " << minw << endl;
}
int main() {
    setlocale(LC_ALL, "ru");
    Graph g(8);
    g.AddWeightedEdge(0, 1, 14);
    g.AddWeightedEdge(0, 5, 8);
    g.AddWeightedEdge(1, 5, 2);
    g.AddWeightedEdge(1, 3, 10);
    g.AddWeightedEdge(1, 4, 2);
    g.AddWeightedEdge(1, 7, 9);
    g.AddWeightedEdge(1, 2, 5);
    g.AddWeightedEdge(2, 7, 11);
    g.AddWeightedEdge(3, 5, 6);
    g.AddWeightedEdge(3, 4, 3);
    g.AddWeightedEdge(3, 6, 5);
    g.AddWeightedEdge(4, 6, 8);
    g.AddWeightedEdge(4, 7, 1);
    g.AddWeightedEdge(5, 6, 5);
    g.AddWeightedEdge(6, 7, 7);

    g.kruskal();
    g.print();
    return 0;
}

