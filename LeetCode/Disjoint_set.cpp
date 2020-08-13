#include "iostream"
#include <vector>
using namespace std;

int find_root(int x, const vector<int>parent) {
	int x_root = x;
	while (parent[x_root] != -1) {
		x_root = parent[x_root];
	}
	return x_root;
}

/*-1--union success 
   0--union failed
*/
int union_vertices(int x ,int y,vector<int> &parent) {
	int x_root = find_root(x, parent);
	int y_root = find_root(y, parent);
	if (x_root != y_root) {
		parent[x_root] = y_root;
		return 1;
	}
	else
		return 0;
}

int main(){
	const int vertices = 7;
	vector<int> parent(vertices, -1);
	vector<vector<int>> edges = {{0,1},{1,2},{1,3},{2,6},{3,4},{2,5}};
	for (auto c : edges) {
		if (union_vertices(c[0],c[1],parent) == 0) {
			std::cout << "cicle  detected" << endl;
			return -1;
		}
	}
	std::cout << "no  cicle" << endl;
	return 0;
}
