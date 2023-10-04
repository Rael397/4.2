#include "gargalo.h"

    int gargalo::calcula_gargalo() {
        map<string, int> cidade_para_indice = { //aqui eh o mapa do grafo, indico nome e indice de cada cidade
            {"Paulinia", 0},
            {"Piracicaba", 1},
            {"Campinas", 2},
            {"Itu", 3},
            {"Sorocaba", 4},
            {"Jundiai", 5},
            {"Sao Paulo", 6}
        };

        int num_nos = cidade_para_indice.size();
        int num_arestas = 11;
        //aqui to redimensionando a lista de adjacencias e o vetor de distancias
        dijkstra::adj.resize(num_nos + 1); //no caso aqui eh so por questao de tamanho mesmo
        dijkstra::dist.resize(num_nos + 1, -1); // e aqui eh pq pra inicializar os nos com -1 pra achar o caminho mais curto, precisei redimensionar o vetor de distancias
        vector<int> parent(num_nos + 1, -1); //aqui eh o vetor de pais, que vai ser usado pra achar o caminho mais curto

        int inicio = cidade_para_indice["Paulinia"]; //no inicial, de onde partimos na distribuicao
        dijkstra::dist[inicio] = INT_MAX; // aqui eu defini a distancia inicial como infinito pq senao da bo no gargalo, e ele fica como -1, ai fiz o caminho mais rapido pra poupar tempo

        //aqui to colocando as arestas no grafo
        dijkstra::adj[cidade_para_indice["Paulinia"]].push_back({ cidade_para_indice["Piracicaba"], 7 });
        dijkstra::adj[cidade_para_indice["Paulinia"]].push_back({ cidade_para_indice["Campinas"], 2 });
        dijkstra::adj[cidade_para_indice["Piracicaba"]].push_back({ cidade_para_indice["Sorocaba"], 5 });
        dijkstra::adj[cidade_para_indice["Piracicaba"]].push_back({ cidade_para_indice["Campinas"], 1 });
        dijkstra::adj[cidade_para_indice["Sorocaba"]].push_back({ cidade_para_indice["Sao Paulo"], 5 });
        dijkstra::adj[cidade_para_indice["Campinas"]].push_back({ cidade_para_indice["Itu"], 1 });
        dijkstra::adj[cidade_para_indice["Campinas"]].push_back({ cidade_para_indice["Jundiai"], 1 });
        dijkstra::adj[cidade_para_indice["Itu"]].push_back({ cidade_para_indice["Sorocaba"], 1 });
        dijkstra::adj[cidade_para_indice["Itu"]].push_back({ cidade_para_indice["Sao Paulo"], 5 });
        dijkstra::adj[cidade_para_indice["Itu"]].push_back({ cidade_para_indice["Jundiai"], 5 });
        dijkstra::adj[cidade_para_indice["Jundiai"]].push_back({ cidade_para_indice["Sao Paulo"], 5 });
        //aqui to aplicando dijkstra (n diga kk), pra achar o caminho mais curto a partir do no inicial (paulinia)
        dijkstra::aplica_dijkstra(inicio, parent);

        map<int, string> indice_para_cidade; //aqui to criando um mapa de indice pra cidade pra poder printar o caminho mais curto mais pra frente
        for (const auto& pair : cidade_para_indice) { 
            indice_para_cidade[pair.second] = pair.first;
        }

        int noh = cidade_para_indice["Sao Paulo"]; //aqui eh o no final, onde a distribuicao termina (sao paulo)
        vector<string> caminho; //criei esse vetor pra guardar o caminho mais curto
        int valor_gargalo = INT_MAX;  //lembra que coloquei distancia inicial como infinito? entao, aqui eu to colocando o valor do gargalo como infinito tbm pra n dar o pepino do gargalo = -1
        int capacidade_cumulativa = 0;  //como a capacidade eh cumulativa a cada aresta, inicializei ela como 0
        //esse for aqui eh pra percorrer o caminho mais curto do no final ao inicial
        for (; noh != -1; noh = parent[noh]) {
            caminho.push_back(indice_para_cidade[noh]); //aqui to colocando o nome da cidade no vetor caminho
            if (parent[noh] != -1) {  //esse if eh pra ignorar o no inicial, pq ele n tem pai
                for (auto& vizinho : dijkstra::adj[parent[noh]]) { //ja esse for eh pra percorrer os vizinhos do no pai
                    if (vizinho.first == noh) { //aqui eh pra achar o vizinho  que eh o no atual (a aresta que leva ao no atual resumindo)
                        capacidade_cumulativa += vizinho.second;  //aqui eh pra somar a capacidade cumulativa, basicamente ta atualizando ela com o peso da aresta
                        valor_gargalo = std::min(valor_gargalo, capacidade_cumulativa);  // agora que atualizou a capacidade cumulativa, aqui eh pra atualizar o valor do gargalo, que eh o minimo entre o valor do gargalo e a capacidade cumulativa
                        break;
                    }
                }
            }
        }

        cout << "O gargalo da distribuicao eh: " << valor_gargalo << endl; //aqui eh pra printar o valor do gargalo 

        reverse(caminho.begin(), caminho.end()); //aqui to invertendo o caminho pra mostrar o caminho do gargalo do inicio ao fim

        cout << "O caminho do gargalo eh: ";
        for (const string& city : caminho) {
            cout << city << " ";
        }
        return 0;
        //acabou (ufa)
    }

