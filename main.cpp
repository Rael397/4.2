#include "gargalo.h"
#include "Dijkstra.h"
using std::vector;
vector<vector<dijkstra::pii>> dijkstra::adj;
vector<int> dijkstra::dist;

int main() {

	gargalo::calcula_gargalo();

	return 0;
}