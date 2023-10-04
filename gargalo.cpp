#include "gargalo.h"

    int gargalo::calcula_gargalo() {
        map<string, int> cidade_para_indice = {
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

        dijkstra::adj.resize(num_nos + 1);
        dijkstra::dist.resize(num_nos + 1, -1);
        vector<int> parent(num_nos + 1, -1);

        int inicio = cidade_para_indice["Paulinia"];
        dijkstra::dist[inicio] = INT_MAX;


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

        dijkstra::aplica_dijkstra(inicio, parent);

        map<int, string> indice_para_cidade;
        for (const auto& pair : cidade_para_indice) {
            indice_para_cidade[pair.second] = pair.first;
        }

        int noh = cidade_para_indice["Sao Paulo"];
        vector<string> caminho;
        int valor_gargalo = INT_MAX;  
        int capacidade_cumulativa = 0;  
        for (; noh != -1; noh = parent[noh]) {
            caminho.push_back(indice_para_cidade[noh]);
            if (parent[noh] != -1) {  
                for (auto& vizinho : dijkstra::adj[parent[noh]]) {
                    if (vizinho.first == noh) {
                        capacidade_cumulativa += vizinho.second;  
                        valor_gargalo = std::min(valor_gargalo, capacidade_cumulativa);  
                        break;
                    }
                }
            }
        }

        cout << "O gargalo da distribuicao eh: " << valor_gargalo << endl;

        reverse(caminho.begin(), caminho.end());

        cout << "O caminho do gargalo eh: ";
        for (const string& city : caminho) {
            cout << city << " ";
        }
        return 0;
    }

