#include "Dijkstra.h"

int dijkstra::aplica_dijkstra(int inicio, vector<int>& parent) {
    //verificacao se o indice do inicio eh valido
        if (inicio < 0 || inicio >= dist.size()) {
            cout << "Indice de inicio invalido." << endl;
            return 1;
        }
        //aqui to inicializando a fila de prioridade e distancia
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push(make_pair(0, inicio));
        dist[inicio] = INT_MAX;
        parent[inicio] = -1; //aqui eh -1 pq  o no inicial n tem pai 
        //o loop principal do algoritmo
        while (!pq.empty()) {
            int no = pq.top().second;
            int distancia_minima = pq.top().first;
            pq.pop();
            //verificacao se o indice do no eh valido
            if (no < 0 || no >= dist.size() || no >= adj.size()) {
                cout << "Indice de no invalido." << endl;
                return 1;
            }
            //ignora no que a distancia minima ja foi calculada
            if (dist[no] < distancia_minima) {
                continue;
            }
            //atualiza as distancias pra todos os nos adjacentes
            for (auto aresta : adj[no]) {
                int no_adjacente = aresta.first;
                int peso = aresta.second;
                //verificacao se o indice do no adjacente eh valido
                if (no_adjacente < 0 || no_adjacente >= dist.size()) {
                    cout << "Indice de no adjacente invalido." << endl;
                    return 1;
                }
                //atualiza a distancia pro no adjacente se um caminho mais curto eh encontrado
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