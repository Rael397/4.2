#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

namespace dijkstra {
    using namespace std;
    typedef pair<int, int> pii;
   extern vector<vector<pii>> adj;
   extern vector<int> dist;

   int aplica_dijkstra(int inicio, vector<int>& parent);


}
