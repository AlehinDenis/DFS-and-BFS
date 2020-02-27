#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> graph = vector<vector<int>>(5);
	graph[0] = { 1,2,3,4 };
	graph[1] = { 0,2,4 };
	graph[2] = { 1 };
	graph[3] = { 0,4 };
	graph[4] = { 0,1,3 };
}