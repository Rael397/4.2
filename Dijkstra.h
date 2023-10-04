#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

namespace dijkstra {
    using namespace std;
    typedef pair<int, int> pii; // aqui coloquei um par de ints pra representar aresta e o peso dela
   extern vector<vector<pii>> adj; //eh aquela lista de adjacencias que fiz antes lembra? mas agora declarei externa pra usar depois no gargalo.cpp
   extern vector<int> dist; //mesma coisa que o de cima so que com as distancias

   int aplica_dijkstra(int inicio, vector<int>& parent);


}
