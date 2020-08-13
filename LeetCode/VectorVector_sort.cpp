#include "iostream"
#include <algorithm>
#include <vector>
using namespace std;


int main(){
	vector<vector<int>> edges = {{0,1},{3,4},{8,3},{2,6},{3,8},{6,5},{3,6}};
	std::sort(edges.begin(),edges.end());
	//for (auto c : edges) 
	//	std::cout <<c[0]<<""<<c[1]<<endl;
	return 0;
}
