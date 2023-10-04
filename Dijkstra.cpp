#include "Dijkstra.h"

int dijkstra::aplica_dijkstra(int inicio, vector<int>& parent) {
        if (inicio < 0 || inicio >= dist.size()) {
            cout << "Indice de inicio invalido." << endl;
            return 1;
        }

        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, inicio));
        dist[inicio] = INT_MAX;
        parent[inicio] = -1;

        while (!pq.empty()) {
            int no = pq.top().second;
            int distancia_minima = pq.top().first;
            pq.pop();
            if (no < 0 || no >= dist.size() || no >= adj.size()) {
                cout << "Indice de no invalido." << endl;
                return 1;
            }
            if (dist[no] < distancia_minima) {
                continue;
            }
            for (auto aresta : adj[no]) {
                int no_adjacente = aresta.first;
                int peso = aresta.second;

                if (no_adjacente < 0 || no_adjacente >= dist.size()) {
                    cout << "Indice de no adjacente invalido." << endl;
                    return 1;
                }

                int nova_distancia = min(dist[no], peso);
                if (nova_distancia > dist[no_adjacente]) {
                    dist[no_adjacente] = nova_distancia;
                    parent[no_adjacente] = no; 
                    pq.push(make_pair(nova_distancia, no_adjacente));
                }
            }
        }
        return 0;
    
}