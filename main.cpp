#include "gargalo.h"
#include "Dijkstra.h"
using std::vector;
vector<vector<dijkstra::pii>> dijkstra::adj;//lista de adjacencias
vector<int> dijkstra::dist;//vetor das distancias

int main() {

	gargalo::calcula_gargalo(); 

	return 0;
}